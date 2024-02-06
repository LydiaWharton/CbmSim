#!/usr/bin/bash

# grab global vars and functions
source forgetting_setup.sh

set -x

#commence the automation
cd $build_dir

# build the adams (or eves) of bunnies
# (naming here refers to which ISI will be used down the line)
for isi in ${isis[@]}; do
  ./cbm_sim -b forgetting.bld -o forgetting_build_ISI_${isi}
done

# Step 1: acq and forget data collection
run_trials_on cbm_sim_gpu_0 eq eq_config
run_trials_on cbm_sim_gpu_0 acq acq_config
# getting the right number of trials requires fiddling
#run_trials_on cbm_sim_gpu_0 forget_est_20k forget_est_config # -> might need to run a couple times
run_trials_on cbm_sim_weight_freq forget forget_config

# Step 2: necessity and sufficiency for CR-mediated PF->PC synapses
# Step 2a: create a set of reset weight files for all isi
#          to later probe for with what num reset CRs go away
cd $scripts_dir
source .venv/bin/activate
for isi in ${isis[@]}; do
   ./reset_weights.py $isi
done
deactivate

for isi in ${isis[@]}; do
   ./reset_probe_trials.sh $isi
done

# TODO: need analysis to determine how many weights reset need for each
#       isi to forget memory (need criterion)

# TODO: given amount needed to reset to remove memory,
#       need to run forgetting with that num weights frozen,
#       analyze, then repeat with increase num weights until
#       sim does not forget (need criterion)

# Step 3: simulate random walk using external program
# cd $scripts_dir
# ./random_walk.py [min weights needed to prevent forget with freeze and
#                   weights needed for sim to forget]

# run_trials_on cbm_sim_weight_freq cr_test_random_walk random_walk_config

# Step 4(TODO): forgetting time as a function of gr background activity
# Step 5(TODO): Analysis time baby (faster turn-over times in notebooks at first,
# then for official data analysis include scripts that we can run here maybe :-) )

cd $scripts_dir
