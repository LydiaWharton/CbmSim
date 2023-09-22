/*
 * activityparams.cpp
 *
 *  Created on: Oct 11, 2012
 *      Author: varicella
 */

#include <assert.h>
#include <cstring>
#include <fstream>

#include "activityparams.h"
#include "connectivityparams.h"
#include "file_utility.h"

bool act_params_populated = false;

float coupleRiRjRatioGO = 0.0;
float coupleRiRjRatioIO = 0.0;
float eBCtoPC = 0.0;
float eGABAGO = 0.0;
float eGOGR = 0.0;
float eMFGR = 0.0;
float eMGluRGO = 0.0;
float eNCtoIO = 0.0;
float ePCtoBC = 0.0;
float ePCtoNC = 0.0;
float eSCtoPC = 0.0;
float gDecTauBCtoPC = 0.0;
float gIncBCtoPC = 0.0;
float gGABADecTauGOtoGO = 0.0;
float gIncDirectGOtoGR = 0.0;
float gDirectTauGOtoGR = 0.0;
float gIncFracSpilloverGOtoGR = 0.0;
float gSpilloverTauGOtoGR = 0.0;
float gGABAIncGOtoGO = 0.0;
float gDecTauGRtoGO = 0.0;
float gIncGRtoGO = 0.0;
float gDecTauMFtoGO = 0.0;
float gIncMFtoGO = 0.0;
float gConstGO = 0.0;
float NMDA_AMPAratioMFGO = 0.0;
float gDecTauMFtoGONMDA = 0.0;
float gIncDirectMFtoGR = 0.0;
float gDirectTauMFtoGR = 0.0;
float gIncFracSpilloverMFtoGR = 0.0;
float gSpilloverTauMFtoGR = 0.0;
float recoveryTauMF = 0.0;
float fracDepMF = 0.0;
float recoveryTauGO = 0.0;
float fracDepGO = 0.0;
float gIncMFtoUBC = 0.0;
float gIncGOtoUBC = 0.0;
float gIncUBCtoUBC = 0.0;
float gIncUBCtoGO = 0.0;
float gIncUBCtoGR = 0.0;
float gKIncUBC = 0.0;
float gKTauUBC = 0.0;
float gConstUBC = 0.0;
float threshTauUBC = 0.0;
float gMGluRDecGRtoGO = 0.0;
float gMGluRIncDecayGO = 0.0;
float gMGluRIncScaleGO = 0.0;
float gMGluRScaleGRtoGO = 0.0;
float gDecT0ofNCtoIO = 0.0;
float gDecTSofNCtoIO = 0.0;
float gDecTTofNCtoIO = 0.0;
float gIncNCtoIO = 0.0;
float gIncTauNCtoIO = 0.0;
float gDecTauPCtoBC = 0.0;
float gDecTauPCtoNC = 0.0;
float gIncAvgPCtoNC = 0.0;
float gDecTauGRtoBC = 0.0;
float gDecTauGRtoPC = 0.0;
float gDecTauGRtoSC = 0.0;
float gIncGRtoPC = 0.0;
float gDecTauSCtoPC = 0.0;
float gIncSCtoPC = 0.0;
float gluDecayGO = 0.0;
float gluScaleGO = 0.0;
float goGABAGOGOSynDepF = 0.0;
float goGABAGOGOSynRecTau = 0.0;

// experimental short term plasticity params
float grEligBase = 0.0;
float grEligMax = 0.0;
float grEligExpScale = 0.0;
float grEligDecayTau = 0.0;
float grEligDecay = 0.0;
float grStpMax = 0.0;
float grStpDecayTau = 0.0;
float grStpDecay = 0.0;
float grStpInc = 0.0;
// experimental short term plasticity params

// experimental long term plasticity params
float fracSynWLow = 0.0;
float fracLowState = 0.0;
float cascPlastProbMin = 0.0;
float cascPlastProbMax = 0.0;
float cascPlastWeightLow = 0.0;
float cascPlastWeightHigh = 0.0;
float binPlastProbMin = 0.0;
float binPlastProbMax = 0.0;
float binPlastWeightLow = 0.0;
float binPlastWeightHigh = 0.0;
// experimental long term plasticity params

float synLTDStepSizeGRtoPC = 0.0;
float synLTPStepSizeGRtoPC = 0.0;
float mGluRDecayGO = 0.0;
float mGluRScaleGO = 0.0;
float maxExtIncVIO = 0.0;
float gmaxAMPADecTauMFtoNC = 0.0;
float synLTDStepSizeMFtoNC = 0.0;
float synLTDPCPopActThreshMFtoNC = 0.0;
float synLTPStepSizeMFtoNC = 0.0;
float synLTPPCPopActThreshMFtoNC = 0.0;
float gmaxNMDADecTauMFtoNC = 0.0;
float msLTDDurationIO = 0.0;
float msLTDStartAPIO = 0.0;
float msLTPEndAPIO = 0.0;
float msLTPStartAPIO = 0.0;
float msPerHistBinGR = 0.0;
float msPerHistBinMF = 0.0;
float relPDecT0ofNCtoIO = 0.0;
float relPDecTSofNCtoIO = 0.0;
float relPDecTTofNCtoIO = 0.0;
float relPIncNCtoIO = 0.0;
float relPIncTauNCtoIO = 0.0;
float gIncPCtoBC = 0.0;
float gIncGRtoBC = 0.0;
float gIncGRtoSC = 0.0;
float rawGLeakBC = 0.0;
float rawGLeakGO = 0.0;
float rawGLeakGR = 0.0;
float rawGLeakIO = 0.0;
float rawGLeakNC = 0.0;
float rawGLeakPC = 0.0;
float rawGLeakSC = 0.0;
float rawGMFAMPAIncNC = 0.0;
float rawGMFNMDAIncNC = 0.0;
float threshDecTauBC = 0.0;
float threshDecTauGO = 0.0;
float threshDecTauUBC = 0.0;
float threshDecTauGR = 0.0;
float threshDecTauIO = 0.0;
float threshDecTauNC = 0.0;
float threshDecTauPC = 0.0;
float threshDecTauSC = 0.0;
float threshMaxBC = 0.0;
float threshMaxGO = 0.0;
float threshMaxGR = 0.0;
float threshMaxIO = 0.0;
float threshMaxNC = 0.0;
float threshMaxPC = 0.0;
float threshMaxSC = 0.0;
float weightScale = 0.0;
float rawGRGOW = 0.0;
float rawMFGOW = 0.0;
float gogrW = 0.0;
float gogoW = 0.0;

/* derived act params */
float numTSinMFHist = 0.0;
float gLeakGO = 0.0;
float gDecMFtoGO = 0.0;
float gDecayMFtoGONMDA = 0.0;
float gDecGRtoGO = 0.0;
float gGABADecGOtoGO = 0.0;
float goGABAGOGOSynRec = 0.0;
float threshDecGO = 0.0;
float gDirectDecMFtoGR = 0.0;
float gSpilloverDecMFtoGR = 0.0;
float gDirectDecGOtoGR = 0.0;
float gSpilloverDecGOtoGR = 0.0;
float threshDecGR = 0.0;
float tsPerHistBinGR = 0.0;
float gLeakSC = 0.0;
float gDecGRtoSC = 0.0;
float threshDecSC = 0.0;
float gDecGRtoBC = 0.0;
float gDecPCtoBC = 0.0;
float threshDecBC = 0.0;
float threshDecPC = 0.0;
float gLeakPC = 0.0;
float gDecGRtoPC = 0.0;
float gDecBCtoPC = 0.0;
float gDecSCtoPC = 0.0;
float tsPopHistPC = 0.0;
float tsPerPopHistBinPC = 0.0;
// float numPopHistBinsPC    = 0.0;
float gLeakIO = 0.0;
float threshDecIO = 0.0;
float tsLTDDurationIO = 0.0;
float tsLTDstartAPIO = 0.0;
float tsLTPstartAPIO = 0.0;
float tsLTPEndAPIO = 0.0;
float grPCHistCheckBinIO = 0.0;
float gmaxNMDADecMFtoNC = 0.0;
float gmaxAMPADecMFtoNC = 0.0;
float gNMDAIncMFtoNC = 0.0;
float gAMPAIncMFtoNC = 0.0;
float gDecPCtoNC = 0.0;
float gLeakNC = 0.0;
float threshDecNC = 0.0;
float gLeakBC = 0.0;
float grgoW = 0.0;
float mfgoW = 0.0;

void populate_act_params(parsed_sess_file &s_file) {
  coupleRiRjRatioGO = std::stof(s_file.parsed_var_sections["activity"]
                                    .param_map["coupleRiRjRatioGO"]
                                    .value);
  coupleRiRjRatioIO = std::stof(s_file.parsed_var_sections["activity"]
                                    .param_map["coupleRiRjRatioIO"]
                                    .value);
  eBCtoPC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["eBCtoPC"].value);
  eGABAGO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["eGABAGO"].value);
  eGOGR = std::stof(
      s_file.parsed_var_sections["activity"].param_map["eGOGR"].value);
  eMFGR = std::stof(
      s_file.parsed_var_sections["activity"].param_map["eMFGR"].value);
  eMGluRGO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["eMGluRGO"].value);
  eNCtoIO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["eNCtoIO"].value);
  ePCtoBC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["ePCtoBC"].value);
  ePCtoNC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["ePCtoNC"].value);
  eSCtoPC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["eSCtoPC"].value);
  gDecTauBCtoPC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gDecTauBCtoPC"].value);
  gIncBCtoPC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gIncBCtoPC"].value);
  gGABADecTauGOtoGO = std::stof(s_file.parsed_var_sections["activity"]
                                    .param_map["gGABADecTauGOtoGO"]
                                    .value);
  gIncDirectGOtoGR = std::stof(s_file.parsed_var_sections["activity"]
                                   .param_map["gIncDirectGOtoGR"]
                                   .value);
  gDirectTauGOtoGR = std::stof(s_file.parsed_var_sections["activity"]
                                   .param_map["gDirectTauGOtoGR"]
                                   .value);
  gIncFracSpilloverGOtoGR = std::stof(s_file.parsed_var_sections["activity"]
                                          .param_map["gIncFracSpilloverGOtoGR"]
                                          .value);
  gSpilloverTauGOtoGR = std::stof(s_file.parsed_var_sections["activity"]
                                      .param_map["gSpilloverTauGOtoGR"]
                                      .value);
  gGABAIncGOtoGO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gGABAIncGOtoGO"].value);
  gDecTauGRtoGO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gDecTauGRtoGO"].value);
  gIncGRtoGO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gIncGRtoGO"].value);
  gDecTauMFtoGO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gDecTauMFtoGO"].value);
  gIncMFtoGO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gIncMFtoGO"].value);
  gConstGO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gConstGO"].value);
  NMDA_AMPAratioMFGO = std::stof(s_file.parsed_var_sections["activity"]
                                     .param_map["NMDA_AMPAratioMFGO"]
                                     .value);
  gDecTauMFtoGONMDA = std::stof(s_file.parsed_var_sections["activity"]
                                    .param_map["gDecTauMFtoGONMDA"]
                                    .value);
  gIncDirectMFtoGR = std::stof(s_file.parsed_var_sections["activity"]
                                   .param_map["gIncDirectMFtoGR"]
                                   .value);
  gDirectTauMFtoGR = std::stof(s_file.parsed_var_sections["activity"]
                                   .param_map["gDirectTauMFtoGR"]
                                   .value);
  gIncFracSpilloverMFtoGR = std::stof(s_file.parsed_var_sections["activity"]
                                          .param_map["gIncFracSpilloverMFtoGR"]
                                          .value);
  gSpilloverTauMFtoGR = std::stof(s_file.parsed_var_sections["activity"]
                                      .param_map["gSpilloverTauMFtoGR"]
                                      .value);
  recoveryTauMF = std::stof(
      s_file.parsed_var_sections["activity"].param_map["recoveryTauMF"].value);
  fracDepMF = std::stof(
      s_file.parsed_var_sections["activity"].param_map["fracDepMF"].value);
  recoveryTauGO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["recoveryTauGO"].value);
  fracDepGO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["fracDepGO"].value);
  gIncMFtoUBC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gIncMFtoUBC"].value);
  gIncGOtoUBC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gIncGOtoUBC"].value);
  gIncUBCtoUBC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gIncUBCtoUBC"].value);
  gIncUBCtoGO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gIncUBCtoGO"].value);
  gIncUBCtoGR = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gIncUBCtoGR"].value);
  gKIncUBC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gKIncUBC"].value);
  gKTauUBC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gKTauUBC"].value);
  gConstUBC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gConstUBC"].value);
  threshTauUBC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["threshTauUBC"].value);
  gMGluRDecGRtoGO = std::stof(s_file.parsed_var_sections["activity"]
                                  .param_map["gMGluRDecGRtoGO"]
                                  .value);
  gMGluRIncDecayGO = std::stof(s_file.parsed_var_sections["activity"]
                                   .param_map["gMGluRIncDecayGO"]
                                   .value);
  gMGluRIncScaleGO = std::stof(s_file.parsed_var_sections["activity"]
                                   .param_map["gMGluRIncScaleGO"]
                                   .value);
  gMGluRScaleGRtoGO = std::stof(s_file.parsed_var_sections["activity"]
                                    .param_map["gMGluRScaleGRtoGO"]
                                    .value);
  gDecT0ofNCtoIO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gDecT0ofNCtoIO"].value);
  gDecTSofNCtoIO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gDecTSofNCtoIO"].value);
  gDecTTofNCtoIO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gDecTTofNCtoIO"].value);
  gIncNCtoIO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gIncNCtoIO"].value);
  gIncTauNCtoIO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gIncTauNCtoIO"].value);
  gDecTauPCtoBC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gDecTauPCtoBC"].value);
  gDecTauPCtoNC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gDecTauPCtoNC"].value);
  gIncAvgPCtoNC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gIncAvgPCtoNC"].value);
  gDecTauGRtoBC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gDecTauGRtoBC"].value);
  gDecTauGRtoPC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gDecTauGRtoPC"].value);
  gDecTauGRtoSC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gDecTauGRtoSC"].value);
  gIncGRtoPC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gIncGRtoPC"].value);
  gDecTauSCtoPC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gDecTauSCtoPC"].value);
  gIncSCtoPC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gIncSCtoPC"].value);
  gluDecayGO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gluDecayGO"].value);
  gluScaleGO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gluScaleGO"].value);
  goGABAGOGOSynDepF = std::stof(s_file.parsed_var_sections["activity"]
                                    .param_map["goGABAGOGOSynDepF"]
                                    .value);
  goGABAGOGOSynRecTau = std::stof(s_file.parsed_var_sections["activity"]
                                      .param_map["goGABAGOGOSynRecTau"]
                                      .value);

  grEligBase = std::stof(
      s_file.parsed_var_sections["activity"].param_map["grEligBase"].value);
  grEligMax = std::stof(
      s_file.parsed_var_sections["activity"].param_map["grEligMax"].value);
  grEligExpScale = std::stof(
      s_file.parsed_var_sections["activity"].param_map["grEligExpScale"].value);
  grEligDecayTau = std::stof(
      s_file.parsed_var_sections["activity"].param_map["grEligDecayTau"].value);
  grStpMax = std::stof(
      s_file.parsed_var_sections["activity"].param_map["grStpMax"].value);
  grStpDecayTau = std::stof(
      s_file.parsed_var_sections["activity"].param_map["grStpDecayTau"].value);
  grStpInc = std::stof(
      s_file.parsed_var_sections["activity"].param_map["grStpInc"].value);

  fracSynWLow = std::stof(
      s_file.parsed_var_sections["activity"].param_map["fracSynWLow"].value);
  fracLowState = std::stof(
      s_file.parsed_var_sections["activity"].param_map["fracLowState"].value);
  cascPlastProbMin = std::stof(s_file.parsed_var_sections["activity"]
                                   .param_map["cascPlastProbMin"]
                                   .value);
  cascPlastProbMax = std::stof(s_file.parsed_var_sections["activity"]
                                   .param_map["cascPlastProbMax"]
                                   .value);
  cascPlastWeightLow = std::stof(s_file.parsed_var_sections["activity"]
                                     .param_map["cascPlastWeightLow"]
                                     .value);
  cascPlastWeightHigh = std::stof(s_file.parsed_var_sections["activity"]
                                      .param_map["cascPlastWeightHigh"]
                                      .value);
  binPlastProbMin = std::stof(s_file.parsed_var_sections["activity"]
                                  .param_map["binPlastProbMin"]
                                  .value);
  binPlastProbMax = std::stof(s_file.parsed_var_sections["activity"]
                                  .param_map["binPlastProbMax"]
                                  .value);
  binPlastWeightLow = std::stof(s_file.parsed_var_sections["activity"]
                                    .param_map["binPlastWeightLow"]
                                    .value);
  binPlastWeightHigh = std::stof(s_file.parsed_var_sections["activity"]
                                     .param_map["binPlastWeightHigh"]
                                     .value);
  synLTDStepSizeGRtoPC = std::stof(s_file.parsed_var_sections["activity"]
                                       .param_map["synLTDStepSizeGRtoPC"]
                                       .value);
  synLTPStepSizeGRtoPC = std::stof(s_file.parsed_var_sections["activity"]
                                       .param_map["synLTPStepSizeGRtoPC"]
                                       .value);
  mGluRDecayGO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["mGluRDecayGO"].value);
  mGluRScaleGO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["mGluRScaleGO"].value);
  maxExtIncVIO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["maxExtIncVIO"].value);
  gmaxAMPADecTauMFtoNC = std::stof(s_file.parsed_var_sections["activity"]
                                       .param_map["gmaxAMPADecTauMFtoNC"]
                                       .value);
  synLTDStepSizeMFtoNC = std::stof(s_file.parsed_var_sections["activity"]
                                       .param_map["synLTDStepSizeMFtoNC"]
                                       .value);
  synLTDPCPopActThreshMFtoNC =
      std::stof(s_file.parsed_var_sections["activity"]
                    .param_map["synLTDPCPopActThreshMFtoNC"]
                    .value);
  synLTPStepSizeMFtoNC = std::stof(s_file.parsed_var_sections["activity"]
                                       .param_map["synLTPStepSizeMFtoNC"]
                                       .value);
  synLTPPCPopActThreshMFtoNC =
      std::stof(s_file.parsed_var_sections["activity"]
                    .param_map["synLTPPCPopActThreshMFtoNC"]
                    .value);
  gmaxNMDADecTauMFtoNC = std::stof(s_file.parsed_var_sections["activity"]
                                       .param_map["gmaxNMDADecTauMFtoNC"]
                                       .value);
  msLTDDurationIO = std::stof(s_file.parsed_var_sections["activity"]
                                  .param_map["msLTDDurationIO"]
                                  .value);
  msLTDStartAPIO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["msLTDStartAPIO"].value);
  msLTPEndAPIO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["msLTPEndAPIO"].value);
  msLTPStartAPIO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["msLTPStartAPIO"].value);
  msPerHistBinGR = std::stof(
      s_file.parsed_var_sections["activity"].param_map["msPerHistBinGR"].value);
  msPerHistBinMF = std::stof(
      s_file.parsed_var_sections["activity"].param_map["msPerHistBinMF"].value);
  relPDecT0ofNCtoIO = std::stof(s_file.parsed_var_sections["activity"]
                                    .param_map["relPDecT0ofNCtoIO"]
                                    .value);
  relPDecTSofNCtoIO = std::stof(s_file.parsed_var_sections["activity"]
                                    .param_map["relPDecTSofNCtoIO"]
                                    .value);
  relPDecTTofNCtoIO = std::stof(s_file.parsed_var_sections["activity"]
                                    .param_map["relPDecTTofNCtoIO"]
                                    .value);
  relPIncNCtoIO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["relPIncNCtoIO"].value);
  relPIncTauNCtoIO = std::stof(s_file.parsed_var_sections["activity"]
                                   .param_map["relPIncTauNCtoIO"]
                                   .value);
  gIncPCtoBC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gIncPCtoBC"].value);
  gIncGRtoBC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gIncGRtoBC"].value);
  gIncGRtoSC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gIncGRtoSC"].value);
  rawGLeakBC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["rawGLeakBC"].value);
  rawGLeakGO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["rawGLeakGO"].value);
  rawGLeakGR = std::stof(
      s_file.parsed_var_sections["activity"].param_map["rawGLeakGR"].value);
  rawGLeakIO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["rawGLeakIO"].value);
  rawGLeakNC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["rawGLeakNC"].value);
  rawGLeakPC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["rawGLeakPC"].value);
  rawGLeakSC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["rawGLeakSC"].value);
  rawGMFAMPAIncNC = std::stof(s_file.parsed_var_sections["activity"]
                                  .param_map["rawGMFAMPAIncNC"]
                                  .value);
  rawGMFNMDAIncNC = std::stof(s_file.parsed_var_sections["activity"]
                                  .param_map["rawGMFNMDAIncNC"]
                                  .value);
  threshDecTauBC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["threshDecTauBC"].value);
  threshDecTauGO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["threshDecTauGO"].value);
  threshDecTauUBC = std::stof(s_file.parsed_var_sections["activity"]
                                  .param_map["threshDecTauUBC"]
                                  .value);
  threshDecTauGR = std::stof(
      s_file.parsed_var_sections["activity"].param_map["threshDecTauGR"].value);
  threshDecTauIO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["threshDecTauIO"].value);
  threshDecTauNC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["threshDecTauNC"].value);
  threshDecTauPC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["threshDecTauPC"].value);
  threshDecTauSC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["threshDecTauSC"].value);
  threshMaxBC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["threshMaxBC"].value);
  threshMaxGO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["threshMaxGO"].value);
  threshMaxGR = std::stof(
      s_file.parsed_var_sections["activity"].param_map["threshMaxGR"].value);
  threshMaxIO = std::stof(
      s_file.parsed_var_sections["activity"].param_map["threshMaxIO"].value);
  threshMaxNC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["threshMaxNC"].value);
  threshMaxPC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["threshMaxPC"].value);
  threshMaxSC = std::stof(
      s_file.parsed_var_sections["activity"].param_map["threshMaxSC"].value);
  weightScale = std::stof(
      s_file.parsed_var_sections["activity"].param_map["weightScale"].value);
  rawGRGOW = std::stof(
      s_file.parsed_var_sections["activity"].param_map["rawGRGOW"].value);
  rawMFGOW = std::stof(
      s_file.parsed_var_sections["activity"].param_map["rawMFGOW"].value);
  gogrW = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gogrW"].value);
  gogoW = std::stof(
      s_file.parsed_var_sections["activity"].param_map["gogoW"].value);

  /* derived act params */
  // assume that we have initialized conparams already, else will get float
  // error

  grEligDecay = 1.0 - exp(-msPerTimeStep / grEligDecayTau);
  grStpDecay = exp(-msPerTimeStep / grStpDecayTau);

  numTSinMFHist = msPerHistBinMF / msPerTimeStep;
  gLeakGO = rawGLeakGO; // / (6 - msPerTimeStep);
  gDecMFtoGO = exp(-msPerTimeStep / gDecTauMFtoGO);
  gDecayMFtoGONMDA = exp(-msPerTimeStep / gDecTauMFtoGONMDA);
  gDecGRtoGO = exp(-msPerTimeStep / gDecTauGRtoGO);
  gGABADecGOtoGO = exp(-msPerTimeStep / gGABADecTauGOtoGO);
  goGABAGOGOSynRec = 1 - exp(-msPerTimeStep / goGABAGOGOSynRecTau);
  threshDecGO = 1 - exp(-msPerTimeStep / threshDecTauGO);
  gDirectDecMFtoGR = exp(-msPerTimeStep / gDirectTauMFtoGR);
  gSpilloverDecMFtoGR = exp(-msPerTimeStep / gSpilloverTauMFtoGR);
  gDirectDecGOtoGR = exp(-msPerTimeStep / gDirectTauGOtoGR);
  gSpilloverDecGOtoGR = exp(-msPerTimeStep / gSpilloverTauGOtoGR);
  threshDecGR = 1 - exp(-msPerTimeStep / threshDecTauGR);
  tsPerHistBinGR = msPerHistBinGR / msPerTimeStep;
  gLeakSC = rawGLeakSC / (6 - msPerTimeStep);
  gDecGRtoSC = exp(-msPerTimeStep / gDecTauGRtoSC);
  threshDecSC = 1 - exp(-msPerTimeStep / threshDecTauSC);
  gDecGRtoBC = exp(-msPerTimeStep / gDecTauGRtoBC);
  gDecPCtoBC = exp(-msPerTimeStep / gDecTauPCtoBC);
  threshDecBC = 1 - exp(-msPerTimeStep / threshDecTauBC);
  threshDecPC = 1 - exp(-msPerTimeStep / threshDecTauPC);
  gLeakPC = rawGLeakPC / (6 - msPerTimeStep);
  gDecGRtoPC = exp(-msPerTimeStep / gDecTauGRtoPC);
  gDecBCtoPC = exp(-msPerTimeStep / gDecTauBCtoPC);
  gDecSCtoPC = exp(-msPerTimeStep / gDecTauSCtoPC);
  tsPopHistPC = 40 / msPerTimeStep;
  tsPerPopHistBinPC = 5 / msPerTimeStep,
  // numPopHistBinsPC    =  8.0; tsPopHistPC / tsPerPopHistBinPC
      gLeakIO = rawGLeakIO / (6 - msPerTimeStep);
  threshDecIO = 1 - exp(-msPerTimeStep / threshDecTauIO);
  tsLTDDurationIO = msLTDDurationIO / msPerTimeStep;
  tsLTDstartAPIO = msLTDStartAPIO / msPerTimeStep;
  tsLTPstartAPIO = msLTPStartAPIO / msPerTimeStep;
  tsLTPEndAPIO = msLTPEndAPIO / msPerTimeStep;
  grPCHistCheckBinIO = abs(msLTPEndAPIO / msPerHistBinGR);
  gmaxNMDADecMFtoNC = exp(-msPerTimeStep / gmaxNMDADecTauMFtoNC);
  gmaxAMPADecMFtoNC = exp(-msPerTimeStep / gmaxAMPADecTauMFtoNC);
  gNMDAIncMFtoNC = rawGMFNMDAIncNC; // 1 - exp(-msPerTimeStep /
                                    // rawGMFNMDAIncNC); // modified 09/29/2022
  gAMPAIncMFtoNC = rawGMFAMPAIncNC; // 1 - exp(-msPerTimeStep /
                                    // rawGMFAMPAIncNC); // modified 09/29/2022
  gDecPCtoNC = exp(-msPerTimeStep / gDecTauPCtoNC);
  gLeakNC = rawGLeakNC / (6 - msPerTimeStep);
  threshDecNC = 1 - exp(-msPerTimeStep / threshDecTauNC);
  gLeakBC = rawGLeakBC;
  grgoW = rawGRGOW * weightScale;
  mfgoW = rawMFGOW * weightScale;

  act_params_populated = true;
}

void read_act_params(std::fstream &in_param_buf) {
  in_param_buf.read((char *)&coupleRiRjRatioGO, sizeof(float));
  in_param_buf.read((char *)&coupleRiRjRatioIO, sizeof(float));
  in_param_buf.read((char *)&eBCtoPC, sizeof(float));
  in_param_buf.read((char *)&eGABAGO, sizeof(float));
  in_param_buf.read((char *)&eGOGR, sizeof(float));
  in_param_buf.read((char *)&eMFGR, sizeof(float));
  in_param_buf.read((char *)&eMGluRGO, sizeof(float));
  in_param_buf.read((char *)&eNCtoIO, sizeof(float));
  in_param_buf.read((char *)&ePCtoBC, sizeof(float));
  in_param_buf.read((char *)&ePCtoNC, sizeof(float));
  in_param_buf.read((char *)&eSCtoPC, sizeof(float));
  in_param_buf.read((char *)&gDecTauBCtoPC, sizeof(float));
  in_param_buf.read((char *)&gIncBCtoPC, sizeof(float));
  in_param_buf.read((char *)&gGABADecTauGOtoGO, sizeof(float));
  in_param_buf.read((char *)&gIncDirectGOtoGR, sizeof(float));
  in_param_buf.read((char *)&gDirectTauGOtoGR, sizeof(float));
  in_param_buf.read((char *)&gIncFracSpilloverGOtoGR, sizeof(float));
  in_param_buf.read((char *)&gSpilloverTauGOtoGR, sizeof(float));
  in_param_buf.read((char *)&gGABAIncGOtoGO, sizeof(float));
  in_param_buf.read((char *)&gDecTauGRtoGO, sizeof(float));
  in_param_buf.read((char *)&gIncGRtoGO, sizeof(float));
  in_param_buf.read((char *)&gDecTauMFtoGO, sizeof(float));
  in_param_buf.read((char *)&gIncMFtoGO, sizeof(float));
  in_param_buf.read((char *)&gConstGO, sizeof(float));
  in_param_buf.read((char *)&NMDA_AMPAratioMFGO, sizeof(float));
  in_param_buf.read((char *)&gDecTauMFtoGONMDA, sizeof(float));
  in_param_buf.read((char *)&gIncDirectMFtoGR, sizeof(float));
  in_param_buf.read((char *)&gDirectTauMFtoGR, sizeof(float));
  in_param_buf.read((char *)&gIncFracSpilloverMFtoGR, sizeof(float));
  in_param_buf.read((char *)&gSpilloverTauMFtoGR, sizeof(float));
  in_param_buf.read((char *)&recoveryTauMF, sizeof(float));
  in_param_buf.read((char *)&fracDepMF, sizeof(float));
  in_param_buf.read((char *)&recoveryTauGO, sizeof(float));
  in_param_buf.read((char *)&fracDepGO, sizeof(float));
  in_param_buf.read((char *)&gIncMFtoUBC, sizeof(float));
  in_param_buf.read((char *)&gIncGOtoUBC, sizeof(float));
  in_param_buf.read((char *)&gIncUBCtoUBC, sizeof(float));
  in_param_buf.read((char *)&gIncUBCtoGO, sizeof(float));
  in_param_buf.read((char *)&gIncUBCtoGR, sizeof(float));
  in_param_buf.read((char *)&gKIncUBC, sizeof(float));
  in_param_buf.read((char *)&gKTauUBC, sizeof(float));
  in_param_buf.read((char *)&gConstUBC, sizeof(float));
  in_param_buf.read((char *)&threshTauUBC, sizeof(float));
  in_param_buf.read((char *)&gMGluRDecGRtoGO, sizeof(float));
  in_param_buf.read((char *)&gMGluRIncDecayGO, sizeof(float));
  in_param_buf.read((char *)&gMGluRIncScaleGO, sizeof(float));
  in_param_buf.read((char *)&gMGluRScaleGRtoGO, sizeof(float));
  in_param_buf.read((char *)&gDecT0ofNCtoIO, sizeof(float));
  in_param_buf.read((char *)&gDecTSofNCtoIO, sizeof(float));
  in_param_buf.read((char *)&gDecTTofNCtoIO, sizeof(float));
  in_param_buf.read((char *)&gIncNCtoIO, sizeof(float));
  in_param_buf.read((char *)&gIncTauNCtoIO, sizeof(float));
  in_param_buf.read((char *)&gDecTauPCtoBC, sizeof(float));
  in_param_buf.read((char *)&gDecTauPCtoNC, sizeof(float));
  in_param_buf.read((char *)&gIncAvgPCtoNC, sizeof(float));
  in_param_buf.read((char *)&gDecTauGRtoBC, sizeof(float));
  in_param_buf.read((char *)&gDecTauGRtoPC, sizeof(float));
  in_param_buf.read((char *)&gDecTauGRtoSC, sizeof(float));
  in_param_buf.read((char *)&gIncGRtoPC, sizeof(float));
  in_param_buf.read((char *)&gDecTauSCtoPC, sizeof(float));
  in_param_buf.read((char *)&gIncSCtoPC, sizeof(float));
  in_param_buf.read((char *)&gluDecayGO, sizeof(float));
  in_param_buf.read((char *)&gluScaleGO, sizeof(float));
  in_param_buf.read((char *)&goGABAGOGOSynDepF, sizeof(float));
  in_param_buf.read((char *)&goGABAGOGOSynRecTau, sizeof(float));

  in_param_buf.read((char *)&grEligBase, sizeof(float));
  in_param_buf.read((char *)&grEligMax, sizeof(float));
  in_param_buf.read((char *)&grEligExpScale, sizeof(float));
  in_param_buf.read((char *)&grEligDecayTau, sizeof(float));
  in_param_buf.read((char *)&grEligDecay, sizeof(float));
  in_param_buf.read((char *)&grStpMax, sizeof(float));
  in_param_buf.read((char *)&grStpDecayTau, sizeof(float));
  in_param_buf.read((char *)&grStpDecay, sizeof(float));
  in_param_buf.read((char *)&grStpInc, sizeof(float));

  in_param_buf.read((char *)&fracSynWLow, sizeof(float));
  in_param_buf.read((char *)&fracLowState, sizeof(float));
  in_param_buf.read((char *)&cascPlastProbMin, sizeof(float));
  in_param_buf.read((char *)&cascPlastProbMax, sizeof(float));
  in_param_buf.read((char *)&cascPlastWeightLow, sizeof(float));
  in_param_buf.read((char *)&cascPlastWeightHigh, sizeof(float));
  in_param_buf.read((char *)&binPlastProbMin, sizeof(float));
  in_param_buf.read((char *)&binPlastProbMax, sizeof(float));
  in_param_buf.read((char *)&binPlastWeightLow, sizeof(float));
  in_param_buf.read((char *)&binPlastWeightHigh, sizeof(float));
  in_param_buf.read((char *)&synLTDStepSizeGRtoPC, sizeof(float));
  in_param_buf.read((char *)&synLTPStepSizeGRtoPC, sizeof(float));
  in_param_buf.read((char *)&mGluRDecayGO, sizeof(float));
  in_param_buf.read((char *)&mGluRScaleGO, sizeof(float));
  in_param_buf.read((char *)&maxExtIncVIO, sizeof(float));
  in_param_buf.read((char *)&gmaxAMPADecTauMFtoNC, sizeof(float));
  in_param_buf.read((char *)&synLTDStepSizeMFtoNC, sizeof(float));
  in_param_buf.read((char *)&synLTDPCPopActThreshMFtoNC, sizeof(float));
  in_param_buf.read((char *)&synLTPStepSizeMFtoNC, sizeof(float));
  in_param_buf.read((char *)&synLTPPCPopActThreshMFtoNC, sizeof(float));
  in_param_buf.read((char *)&gmaxNMDADecTauMFtoNC, sizeof(float));
  in_param_buf.read((char *)&msLTDDurationIO, sizeof(float));
  in_param_buf.read((char *)&msLTDStartAPIO, sizeof(float));
  in_param_buf.read((char *)&msLTPEndAPIO, sizeof(float));
  in_param_buf.read((char *)&msLTPStartAPIO, sizeof(float));
  in_param_buf.read((char *)&msPerHistBinGR, sizeof(float));
  in_param_buf.read((char *)&msPerHistBinMF, sizeof(float));
  in_param_buf.read((char *)&relPDecT0ofNCtoIO, sizeof(float));
  in_param_buf.read((char *)&relPDecTSofNCtoIO, sizeof(float));
  in_param_buf.read((char *)&relPDecTTofNCtoIO, sizeof(float));
  in_param_buf.read((char *)&relPIncNCtoIO, sizeof(float));
  in_param_buf.read((char *)&relPIncTauNCtoIO, sizeof(float));
  in_param_buf.read((char *)&gIncPCtoBC, sizeof(float));
  in_param_buf.read((char *)&gIncGRtoBC, sizeof(float));
  in_param_buf.read((char *)&gIncGRtoSC, sizeof(float));
  in_param_buf.read((char *)&rawGLeakBC, sizeof(float));
  in_param_buf.read((char *)&rawGLeakGO, sizeof(float));
  in_param_buf.read((char *)&rawGLeakGR, sizeof(float));
  in_param_buf.read((char *)&rawGLeakIO, sizeof(float));
  in_param_buf.read((char *)&rawGLeakNC, sizeof(float));
  in_param_buf.read((char *)&rawGLeakPC, sizeof(float));
  in_param_buf.read((char *)&rawGLeakSC, sizeof(float));
  in_param_buf.read((char *)&rawGMFAMPAIncNC, sizeof(float));
  in_param_buf.read((char *)&rawGMFNMDAIncNC, sizeof(float));
  in_param_buf.read((char *)&threshDecTauBC, sizeof(float));
  in_param_buf.read((char *)&threshDecTauGO, sizeof(float));
  in_param_buf.read((char *)&threshDecTauUBC, sizeof(float));
  in_param_buf.read((char *)&threshDecTauGR, sizeof(float));
  in_param_buf.read((char *)&threshDecTauIO, sizeof(float));
  in_param_buf.read((char *)&threshDecTauNC, sizeof(float));
  in_param_buf.read((char *)&threshDecTauPC, sizeof(float));
  in_param_buf.read((char *)&threshDecTauSC, sizeof(float));
  in_param_buf.read((char *)&threshMaxBC, sizeof(float));
  in_param_buf.read((char *)&threshMaxGO, sizeof(float));
  in_param_buf.read((char *)&threshMaxGR, sizeof(float));
  in_param_buf.read((char *)&threshMaxIO, sizeof(float));
  in_param_buf.read((char *)&threshMaxNC, sizeof(float));
  in_param_buf.read((char *)&threshMaxPC, sizeof(float));
  in_param_buf.read((char *)&threshMaxSC, sizeof(float));
  in_param_buf.read((char *)&weightScale, sizeof(float));
  in_param_buf.read((char *)&rawGRGOW, sizeof(float));
  in_param_buf.read((char *)&rawMFGOW, sizeof(float));
  in_param_buf.read((char *)&gogrW, sizeof(float));
  in_param_buf.read((char *)&gogoW, sizeof(float));

  /* derived params */
  in_param_buf.read((char *)&numTSinMFHist, sizeof(float));
  in_param_buf.read((char *)&gLeakGO, sizeof(float));
  in_param_buf.read((char *)&gDecMFtoGO, sizeof(float));
  in_param_buf.read((char *)&gDecayMFtoGONMDA, sizeof(float));
  in_param_buf.read((char *)&gDecGRtoGO, sizeof(float));
  in_param_buf.read((char *)&gGABADecGOtoGO, sizeof(float));
  in_param_buf.read((char *)&goGABAGOGOSynRec, sizeof(float));
  in_param_buf.read((char *)&threshDecGO, sizeof(float));
  in_param_buf.read((char *)&gDirectDecMFtoGR, sizeof(float));
  in_param_buf.read((char *)&gSpilloverDecMFtoGR, sizeof(float));
  in_param_buf.read((char *)&gDirectDecGOtoGR, sizeof(float));
  in_param_buf.read((char *)&gSpilloverDecGOtoGR, sizeof(float));
  in_param_buf.read((char *)&threshDecGR, sizeof(float));
  in_param_buf.read((char *)&tsPerHistBinGR, sizeof(float));
  in_param_buf.read((char *)&gLeakSC, sizeof(float));
  in_param_buf.read((char *)&gDecGRtoSC, sizeof(float));
  in_param_buf.read((char *)&threshDecSC, sizeof(float));
  in_param_buf.read((char *)&gDecGRtoBC, sizeof(float));
  in_param_buf.read((char *)&gDecPCtoBC, sizeof(float));
  in_param_buf.read((char *)&threshDecBC, sizeof(float));
  in_param_buf.read((char *)&threshDecPC, sizeof(float));
  in_param_buf.read((char *)&gLeakPC, sizeof(float));
  in_param_buf.read((char *)&gDecGRtoPC, sizeof(float));
  in_param_buf.read((char *)&gDecBCtoPC, sizeof(float));
  in_param_buf.read((char *)&gDecSCtoPC, sizeof(float));
  in_param_buf.read((char *)&tsPopHistPC, sizeof(float));
  in_param_buf.read((char *)&tsPerPopHistBinPC, sizeof(float));
  // in_param_buf.read((char *)&numPopHistBinsPC, sizeof(float));
  in_param_buf.read((char *)&gLeakIO, sizeof(float));
  in_param_buf.read((char *)&threshDecIO, sizeof(float));
  in_param_buf.read((char *)&tsLTDDurationIO, sizeof(float));
  in_param_buf.read((char *)&tsLTDstartAPIO, sizeof(float));
  in_param_buf.read((char *)&tsLTPstartAPIO, sizeof(float));
  in_param_buf.read((char *)&tsLTPEndAPIO, sizeof(float));
  in_param_buf.read((char *)&grPCHistCheckBinIO, sizeof(float));
  in_param_buf.read((char *)&gmaxNMDADecMFtoNC, sizeof(float));
  in_param_buf.read((char *)&gmaxAMPADecMFtoNC, sizeof(float));
  in_param_buf.read((char *)&gNMDAIncMFtoNC, sizeof(float));
  in_param_buf.read((char *)&gAMPAIncMFtoNC, sizeof(float));
  in_param_buf.read((char *)&gDecPCtoNC, sizeof(float));
  in_param_buf.read((char *)&gLeakNC, sizeof(float));
  in_param_buf.read((char *)&threshDecNC, sizeof(float));
  in_param_buf.read((char *)&gLeakBC, sizeof(float));
  in_param_buf.read((char *)&grgoW, sizeof(float));
  in_param_buf.read((char *)&mfgoW, sizeof(float));

  act_params_populated = true;
}

void write_act_params(std::fstream &out_param_buf) {
  out_param_buf.write((char *)&coupleRiRjRatioGO, sizeof(float));
  out_param_buf.write((char *)&coupleRiRjRatioIO, sizeof(float));
  out_param_buf.write((char *)&eBCtoPC, sizeof(float));
  out_param_buf.write((char *)&eGABAGO, sizeof(float));
  out_param_buf.write((char *)&eGOGR, sizeof(float));
  out_param_buf.write((char *)&eMFGR, sizeof(float));
  out_param_buf.write((char *)&eMGluRGO, sizeof(float));
  out_param_buf.write((char *)&eNCtoIO, sizeof(float));
  out_param_buf.write((char *)&ePCtoBC, sizeof(float));
  out_param_buf.write((char *)&ePCtoNC, sizeof(float));
  out_param_buf.write((char *)&eSCtoPC, sizeof(float));
  out_param_buf.write((char *)&gDecTauBCtoPC, sizeof(float));
  out_param_buf.write((char *)&gIncBCtoPC, sizeof(float));
  out_param_buf.write((char *)&gGABADecTauGOtoGO, sizeof(float));
  out_param_buf.write((char *)&gIncDirectGOtoGR, sizeof(float));
  out_param_buf.write((char *)&gDirectTauGOtoGR, sizeof(float));
  out_param_buf.write((char *)&gIncFracSpilloverGOtoGR, sizeof(float));
  out_param_buf.write((char *)&gSpilloverTauGOtoGR, sizeof(float));
  out_param_buf.write((char *)&gGABAIncGOtoGO, sizeof(float));
  out_param_buf.write((char *)&gDecTauGRtoGO, sizeof(float));
  out_param_buf.write((char *)&gIncGRtoGO, sizeof(float));
  out_param_buf.write((char *)&gDecTauMFtoGO, sizeof(float));
  out_param_buf.write((char *)&gIncMFtoGO, sizeof(float));
  out_param_buf.write((char *)&gConstGO, sizeof(float));
  out_param_buf.write((char *)&NMDA_AMPAratioMFGO, sizeof(float));
  out_param_buf.write((char *)&gDecTauMFtoGONMDA, sizeof(float));
  out_param_buf.write((char *)&gIncDirectMFtoGR, sizeof(float));
  out_param_buf.write((char *)&gDirectTauMFtoGR, sizeof(float));
  out_param_buf.write((char *)&gIncFracSpilloverMFtoGR, sizeof(float));
  out_param_buf.write((char *)&gSpilloverTauMFtoGR, sizeof(float));
  out_param_buf.write((char *)&recoveryTauMF, sizeof(float));
  out_param_buf.write((char *)&fracDepMF, sizeof(float));
  out_param_buf.write((char *)&recoveryTauGO, sizeof(float));
  out_param_buf.write((char *)&fracDepGO, sizeof(float));
  out_param_buf.write((char *)&gIncMFtoUBC, sizeof(float));
  out_param_buf.write((char *)&gIncGOtoUBC, sizeof(float));
  out_param_buf.write((char *)&gIncUBCtoUBC, sizeof(float));
  out_param_buf.write((char *)&gIncUBCtoGO, sizeof(float));
  out_param_buf.write((char *)&gIncUBCtoGR, sizeof(float));
  out_param_buf.write((char *)&gKIncUBC, sizeof(float));
  out_param_buf.write((char *)&gKTauUBC, sizeof(float));
  out_param_buf.write((char *)&gConstUBC, sizeof(float));
  out_param_buf.write((char *)&threshTauUBC, sizeof(float));
  out_param_buf.write((char *)&gMGluRDecGRtoGO, sizeof(float));
  out_param_buf.write((char *)&gMGluRIncDecayGO, sizeof(float));
  out_param_buf.write((char *)&gMGluRIncScaleGO, sizeof(float));
  out_param_buf.write((char *)&gMGluRScaleGRtoGO, sizeof(float));
  out_param_buf.write((char *)&gDecT0ofNCtoIO, sizeof(float));
  out_param_buf.write((char *)&gDecTSofNCtoIO, sizeof(float));
  out_param_buf.write((char *)&gDecTTofNCtoIO, sizeof(float));
  out_param_buf.write((char *)&gIncNCtoIO, sizeof(float));
  out_param_buf.write((char *)&gIncTauNCtoIO, sizeof(float));
  out_param_buf.write((char *)&gDecTauPCtoBC, sizeof(float));
  out_param_buf.write((char *)&gDecTauPCtoNC, sizeof(float));
  out_param_buf.write((char *)&gIncAvgPCtoNC, sizeof(float));
  out_param_buf.write((char *)&gDecTauGRtoBC, sizeof(float));
  out_param_buf.write((char *)&gDecTauGRtoPC, sizeof(float));
  out_param_buf.write((char *)&gDecTauGRtoSC, sizeof(float));
  out_param_buf.write((char *)&gIncGRtoPC, sizeof(float));
  out_param_buf.write((char *)&gDecTauSCtoPC, sizeof(float));
  out_param_buf.write((char *)&gIncSCtoPC, sizeof(float));
  out_param_buf.write((char *)&gluDecayGO, sizeof(float));
  out_param_buf.write((char *)&gluScaleGO, sizeof(float));
  out_param_buf.write((char *)&goGABAGOGOSynDepF, sizeof(float));
  out_param_buf.write((char *)&goGABAGOGOSynRecTau, sizeof(float));

  out_param_buf.write((char *)&grEligBase, sizeof(float));
  out_param_buf.write((char *)&grEligMax, sizeof(float));
  out_param_buf.write((char *)&grEligExpScale, sizeof(float));
  out_param_buf.write((char *)&grEligDecayTau, sizeof(float));
  out_param_buf.write((char *)&grEligDecay, sizeof(float));
  out_param_buf.write((char *)&grStpMax, sizeof(float));
  out_param_buf.write((char *)&grStpDecayTau, sizeof(float));
  out_param_buf.write((char *)&grStpDecay, sizeof(float));
  out_param_buf.write((char *)&grStpInc, sizeof(float));

  out_param_buf.write((char *)&fracSynWLow, sizeof(float));
  out_param_buf.write((char *)&fracLowState, sizeof(float));
  out_param_buf.write((char *)&cascPlastProbMin, sizeof(float));
  out_param_buf.write((char *)&cascPlastProbMax, sizeof(float));
  out_param_buf.write((char *)&cascPlastWeightLow, sizeof(float));
  out_param_buf.write((char *)&cascPlastWeightHigh, sizeof(float));
  out_param_buf.write((char *)&binPlastProbMin, sizeof(float));
  out_param_buf.write((char *)&binPlastProbMax, sizeof(float));
  out_param_buf.write((char *)&binPlastWeightLow, sizeof(float));
  out_param_buf.write((char *)&binPlastWeightHigh, sizeof(float));
  out_param_buf.write((char *)&synLTDStepSizeGRtoPC, sizeof(float));
  out_param_buf.write((char *)&synLTPStepSizeGRtoPC, sizeof(float));
  out_param_buf.write((char *)&mGluRDecayGO, sizeof(float));
  out_param_buf.write((char *)&mGluRScaleGO, sizeof(float));
  out_param_buf.write((char *)&maxExtIncVIO, sizeof(float));
  out_param_buf.write((char *)&gmaxAMPADecTauMFtoNC, sizeof(float));
  out_param_buf.write((char *)&synLTDStepSizeMFtoNC, sizeof(float));
  out_param_buf.write((char *)&synLTDPCPopActThreshMFtoNC, sizeof(float));
  out_param_buf.write((char *)&synLTPStepSizeMFtoNC, sizeof(float));
  out_param_buf.write((char *)&synLTPPCPopActThreshMFtoNC, sizeof(float));
  out_param_buf.write((char *)&gmaxNMDADecTauMFtoNC, sizeof(float));
  out_param_buf.write((char *)&msLTDDurationIO, sizeof(float));
  out_param_buf.write((char *)&msLTDStartAPIO, sizeof(float));
  out_param_buf.write((char *)&msLTPEndAPIO, sizeof(float));
  out_param_buf.write((char *)&msLTPStartAPIO, sizeof(float));
  out_param_buf.write((char *)&msPerHistBinGR, sizeof(float));
  out_param_buf.write((char *)&msPerHistBinMF, sizeof(float));
  out_param_buf.write((char *)&relPDecT0ofNCtoIO, sizeof(float));
  out_param_buf.write((char *)&relPDecTSofNCtoIO, sizeof(float));
  out_param_buf.write((char *)&relPDecTTofNCtoIO, sizeof(float));
  out_param_buf.write((char *)&relPIncNCtoIO, sizeof(float));
  out_param_buf.write((char *)&relPIncTauNCtoIO, sizeof(float));
  out_param_buf.write((char *)&gIncPCtoBC, sizeof(float));
  out_param_buf.write((char *)&gIncGRtoBC, sizeof(float));
  out_param_buf.write((char *)&gIncGRtoSC, sizeof(float));
  out_param_buf.write((char *)&rawGLeakBC, sizeof(float));
  out_param_buf.write((char *)&rawGLeakGO, sizeof(float));
  out_param_buf.write((char *)&rawGLeakGR, sizeof(float));
  out_param_buf.write((char *)&rawGLeakIO, sizeof(float));
  out_param_buf.write((char *)&rawGLeakNC, sizeof(float));
  out_param_buf.write((char *)&rawGLeakPC, sizeof(float));
  out_param_buf.write((char *)&rawGLeakSC, sizeof(float));
  out_param_buf.write((char *)&rawGMFAMPAIncNC, sizeof(float));
  out_param_buf.write((char *)&rawGMFNMDAIncNC, sizeof(float));
  out_param_buf.write((char *)&threshDecTauBC, sizeof(float));
  out_param_buf.write((char *)&threshDecTauGO, sizeof(float));
  out_param_buf.write((char *)&threshDecTauUBC, sizeof(float));
  out_param_buf.write((char *)&threshDecTauGR, sizeof(float));
  out_param_buf.write((char *)&threshDecTauIO, sizeof(float));
  out_param_buf.write((char *)&threshDecTauNC, sizeof(float));
  out_param_buf.write((char *)&threshDecTauPC, sizeof(float));
  out_param_buf.write((char *)&threshDecTauSC, sizeof(float));
  out_param_buf.write((char *)&threshMaxBC, sizeof(float));
  out_param_buf.write((char *)&threshMaxGO, sizeof(float));
  out_param_buf.write((char *)&threshMaxGR, sizeof(float));
  out_param_buf.write((char *)&threshMaxIO, sizeof(float));
  out_param_buf.write((char *)&threshMaxNC, sizeof(float));
  out_param_buf.write((char *)&threshMaxPC, sizeof(float));
  out_param_buf.write((char *)&threshMaxSC, sizeof(float));
  out_param_buf.write((char *)&weightScale, sizeof(float));
  out_param_buf.write((char *)&rawGRGOW, sizeof(float));
  out_param_buf.write((char *)&rawMFGOW, sizeof(float));
  out_param_buf.write((char *)&gogrW, sizeof(float));
  out_param_buf.write((char *)&gogoW, sizeof(float));

  /* derived act params */
  out_param_buf.write((char *)&numTSinMFHist, sizeof(float));
  out_param_buf.write((char *)&gLeakGO, sizeof(float));
  out_param_buf.write((char *)&gDecMFtoGO, sizeof(float));
  out_param_buf.write((char *)&gDecayMFtoGONMDA, sizeof(float));
  out_param_buf.write((char *)&gDecGRtoGO, sizeof(float));
  out_param_buf.write((char *)&gGABADecGOtoGO, sizeof(float));
  out_param_buf.write((char *)&goGABAGOGOSynRec, sizeof(float));
  out_param_buf.write((char *)&threshDecGO, sizeof(float));
  out_param_buf.write((char *)&gDirectDecMFtoGR, sizeof(float));
  out_param_buf.write((char *)&gSpilloverDecMFtoGR, sizeof(float));
  out_param_buf.write((char *)&gDirectDecGOtoGR, sizeof(float));
  out_param_buf.write((char *)&gSpilloverDecGOtoGR, sizeof(float));
  out_param_buf.write((char *)&threshDecGR, sizeof(float));
  out_param_buf.write((char *)&tsPerHistBinGR, sizeof(float));
  out_param_buf.write((char *)&gLeakSC, sizeof(float));
  out_param_buf.write((char *)&gDecGRtoSC, sizeof(float));
  out_param_buf.write((char *)&threshDecSC, sizeof(float));
  out_param_buf.write((char *)&gDecGRtoBC, sizeof(float));
  out_param_buf.write((char *)&gDecPCtoBC, sizeof(float));
  out_param_buf.write((char *)&threshDecBC, sizeof(float));
  out_param_buf.write((char *)&threshDecPC, sizeof(float));
  out_param_buf.write((char *)&gLeakPC, sizeof(float));
  out_param_buf.write((char *)&gDecGRtoPC, sizeof(float));
  out_param_buf.write((char *)&gDecBCtoPC, sizeof(float));
  out_param_buf.write((char *)&gDecSCtoPC, sizeof(float));
  out_param_buf.write((char *)&tsPopHistPC, sizeof(float));
  out_param_buf.write((char *)&tsPerPopHistBinPC, sizeof(float));
  // out_param_buf.write((char *)&numPopHistBinsPC, sizeof(float));
  out_param_buf.write((char *)&gLeakIO, sizeof(float));
  out_param_buf.write((char *)&threshDecIO, sizeof(float));
  out_param_buf.write((char *)&tsLTDDurationIO, sizeof(float));
  out_param_buf.write((char *)&tsLTDstartAPIO, sizeof(float));
  out_param_buf.write((char *)&tsLTPstartAPIO, sizeof(float));
  out_param_buf.write((char *)&tsLTPEndAPIO, sizeof(float));
  out_param_buf.write((char *)&grPCHistCheckBinIO, sizeof(float));
  out_param_buf.write((char *)&gmaxNMDADecMFtoNC, sizeof(float));
  out_param_buf.write((char *)&gmaxAMPADecMFtoNC, sizeof(float));
  out_param_buf.write((char *)&gNMDAIncMFtoNC, sizeof(float));
  out_param_buf.write((char *)&gAMPAIncMFtoNC, sizeof(float));
  out_param_buf.write((char *)&gDecPCtoNC, sizeof(float));
  out_param_buf.write((char *)&gLeakNC, sizeof(float));
  out_param_buf.write((char *)&threshDecNC, sizeof(float));
  out_param_buf.write((char *)&gLeakBC, sizeof(float));
  out_param_buf.write((char *)&grgoW, sizeof(float));
  out_param_buf.write((char *)&mfgoW, sizeof(float));
}
