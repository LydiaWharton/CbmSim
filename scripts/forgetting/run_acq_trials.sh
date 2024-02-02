#!/usr/bin/bash

declare -a num_walked

inputs_dir=lobule_v

## nohup ./reset_probe.sh &> ISI_500_probes.log &

## set -x
## awk modifies text streams
## 1) grab all files you want to loop over
## 2) parse the file basename wrt a delimiter ('_')
## 3) select the last element ($3)
## 4) append this element to list of num_resets


# reset_nums=$(ls * | awk -F_ '{print $3}')

# # | awk -F. {'print $1'}

# echo $reset_nums

# for num in $(ls * | awk -F_ '{print $4}' | awk -F. {'print $1'} | sort -k 1n); do
# 	cd ../../../../build/
# ## for num in {1}; do

cd ../../build/

./cbm_sim_gpu_0 --mfnc-off \
-i eq_ISI_500.sim \
-s acq_ISI_500.sess \
-r PC,NC \
-o test_acq_ISI_500

