#include <iostream>
#include <stdexcept>
#include "MadMela.h"
#include "MELAStreamHelpers.hh"
#include "TLorentzVector.h"
#include "TUtil.hh"
#include "TVar.hh"
#include "TMCFM.hh"
using MELAStreamHelpers::MELAout;
using MELAStreamHelpers::MELAerr;
using namespace madMela;
std::map<std::pair<TVar::Process, TVar::Production>, MG_process_double>* madMela::updateMap;

/**
######################################################################
## PARAM_CARD AUTOMATICALY GENERATED BY MG5 FOLLOWING UFO MODEL   ####
######################################################################
##                                                                  ##
##  Width set on Auto will be computed following the information    ##
##        present in the decay.py files of the model.               ##
##        See  arXiv:1402.1178 for more details.                    ##
##                                                                  ##
######################################################################

###################################
## INFORMATION FOR CKMBLOCK
###################################
Block ckmblock 
    2 2.265000e-01 # CKMlambda 
    3 7.900000e-01 # CKMA 
    4 1.410000e-01 # CKMrho 
    5 3.570000e-01 # CKMeta 

###################################
## INFORMATION FOR MASS
###################################
Block mass 
    1 4.670000e-03 # MD 
    2 2.160000e-03 # MU 
    3 9.300000e-02 # MS 
    4 1.270000e+00 # MC 
    5 4.180000e+00 # MB 
    6 1.727600e+02 # MT 
   11 5.110000e-04 # Me 
   13 1.056600e-01 # MMU 
   15 1.777000e+00 # MTA 
   23 9.118760e+01 # MZ 
   25 1.250900e+02 # MH 
## Dependent parameters, given by model restrictions.
## Those values should be edited following the 
## analytical expression. MG5 ignores those values 
## but they are important for interfacing the output of MG5
## to external program such as Pythia.
  12 0.000000e+00 # ve : 0.0 
  14 0.000000e+00 # vm : 0.0 
  16 0.000000e+00 # vt : 0.0 
  21 0.000000e+00 # g : 0.0 
  22 0.000000e+00 # a : 0.0 
  24 7.983133e+01 # w+ : dMW*(1 - linearPropCorrections) + MWsm 
  9000005 9.118760e+01 # z1 : MZ 
  9000006 7.983133e+01 # w1+ : MWsm 
  9000007 1.727600e+02 # t1 : MT 
  9000008 1.250900e+02 # h1 : MH 

###################################
## INFORMATION FOR SMEFT
###################################
Block smeft 
    1 0.000000e+00 # cG 
    2 0.000000e+00 # cW 
    3 0.000000e+00 # cH 
    4 0.000000e+00 # cHbox 
    5 0.000000e+00 # cHDD 
    6 0.000000e+00 # cHG 
    7 0.000000e+00 # cHW 
    8 0.000000e+00 # cHB 
    9 0.000000e+00 # cHWB 
   10 0.000000e+00 # ceHRe 
   11 0.000000e+00 # cuHRe 
   12 0.000000e+00 # cdHRe 
   13 0.000000e+00 # ceWRe 
   14 0.000000e+00 # ceBRe 
   15 0.000000e+00 # cuGRe 
   16 0.000000e+00 # cuWRe 
   17 0.000000e+00 # cuBRe 
   18 0.000000e+00 # cdGRe 
   19 0.000000e+00 # cdWRe 
   20 0.000000e+00 # cdBRe 
   21 0.000000e+00 # cHl1 
   22 0.000000e+00 # cHl3 
   23 0.000000e+00 # cHe 
   24 0.000000e+00 # cHq1 
   25 0.000000e+00 # cHq3 
   26 0.000000e+00 # cHu 
   27 0.000000e+00 # cHd 
   28 0.000000e+00 # cHudRe 
   29 0.000000e+00 # cll 
   30 0.000000e+00 # cll1 
   31 0.000000e+00 # cqq1 
   32 0.000000e+00 # cqq11 
   33 0.000000e+00 # cqq3 
   34 0.000000e+00 # cqq31 
   35 0.000000e+00 # clq1 
   36 0.000000e+00 # clq3 
   37 0.000000e+00 # cee 
   38 0.000000e+00 # cuu 
   39 0.000000e+00 # cuu1 
   40 0.000000e+00 # cdd 
   41 0.000000e+00 # cdd1 
   42 0.000000e+00 # ceu 
   43 0.000000e+00 # ced 
   44 0.000000e+00 # cud1 
   45 0.000000e+00 # cud8 
   46 0.000000e+00 # cle 
   47 0.000000e+00 # clu 
   48 0.000000e+00 # cld 
   49 0.000000e+00 # cqe 
   50 0.000000e+00 # cqu1 
   51 0.000000e+00 # cqu8 
   52 0.000000e+00 # cqd1 
   53 0.000000e+00 # cqd8 
   54 0.000000e+00 # cledqRe 
   55 0.000000e+00 # cquqd1Re 
   56 0.000000e+00 # cquqd11Re 
   57 0.000000e+00 # cquqd8Re 
   58 0.000000e+00 # cquqd81Re 
   59 0.000000e+00 # clequ1Re 
   60 0.000000e+00 # clequ3Re 

###################################
## INFORMATION FOR SMEFTCPV
###################################
Block smeftcpv 
    1 0.000000e+00 # cGtil 
    2 0.000000e+00 # cWtil 
    3 0.000000e+00 # cHGtil 
    4 0.000000e+00 # cHWtil 
    5 0.000000e+00 # cHBtil 
    6 0.000000e+00 # cHWBtil 
    7 0.000000e+00 # ceWIm 
    8 0.000000e+00 # ceBIm 
    9 0.000000e+00 # cuGIm 
   10 0.000000e+00 # cuWIm 
   11 0.000000e+00 # cuBIm 
   12 0.000000e+00 # cdGIm 
   13 0.000000e+00 # cdWIm 
   14 0.000000e+00 # cdBIm 
   15 0.000000e+00 # cHudIm 
   16 0.000000e+00 # ceHIm 
   17 0.000000e+00 # cuHIm 
   18 0.000000e+00 # cdHIm 
   19 0.000000e+00 # cledqIm 
   20 0.000000e+00 # cquqd1Im 
   21 0.000000e+00 # cquqd8Im 
   22 0.000000e+00 # cquqd11Im 
   23 0.000000e+00 # cquqd81Im 
   24 0.000000e+00 # clequ1Im 
   25 0.000000e+00 # clequ3Im 

###################################
## INFORMATION FOR SMEFTCUTOFF
###################################
Block smeftcutoff 
    1 1.000000e+03 # LambdaSMEFT 

###################################
## INFORMATION FOR SMINPUTS
###################################
Block sminputs 
    1 7.815553e-03 # aEW 
    2 1.166379e-05 # Gf 
    3 1.179000e-01 # aS (Note that Parameter not used if you use a PDF set) 

###################################
## INFORMATION FOR SWITCHES
###################################
Block switches 
    1 0.000000e+00 # linearPropCorrections 

###################################
## INFORMATION FOR YUKAWA
###################################
Block yukawa 
    1 4.670000e-03 # ymdo 
    2 2.160000e-03 # ymup 
    3 9.300000e-02 # yms 
    4 1.270000e+00 # ymc 
    5 4.180000e+00 # ymb 
    6 1.727600e+02 # ymt 
   11 5.110000e-04 # yme 
   13 1.056600e-01 # ymm 
   15 1.777000e+00 # ymtau 

###################################
## INFORMATION FOR DECAY
###################################
DECAY   6 1.330000e+00 # WT 
DECAY  23 2.495200e+00 # WZ 
DECAY  24 2.085000e+00 # WW 
DECAY  25 4.070000e-03 # WH 
## Dependent parameters, given by model restrictions.
## Those values should be edited following the 
## analytical expression. MG5 ignores those values 
## but they are important for interfacing the output of MG5
## to external program such as Pythia.
DECAY  1 0.000000e+00 # d : 0.0 
DECAY  2 0.000000e+00 # u : 0.0 
DECAY  3 0.000000e+00 # s : 0.0 
DECAY  4 0.000000e+00 # c : 0.0 
DECAY  5 0.000000e+00 # b : 0.0 
DECAY  11 0.000000e+00 # e- : 0.0 
DECAY  12 0.000000e+00 # ve : 0.0 
DECAY  13 0.000000e+00 # mu- : 0.0 
DECAY  14 0.000000e+00 # vm : 0.0 
DECAY  15 0.000000e+00 # ta- : 0.0 
DECAY  16 0.000000e+00 # vt : 0.0 
DECAY  21 0.000000e+00 # g : 0.0 
DECAY  22 0.000000e+00 # a : 0.0 
DECAY  9000005 2.495200e+00 # z1 : WZ 
DECAY  9000006 2.085000e+00 # w1+ : WW 
DECAY  9000007 1.330000e+00 # t1 : WT 
DECAY  9000008 4.070000e-03 # h1 : WH 
#===========================================================
# QUANTUM NUMBERS OF NEW STATE(S) (NON SM PDG CODE)
#===========================================================

Block QNUMBERS 9000005  # z1 
        1 0  # 3 times electric charge
        2 3  # number of spin states (2S+1)
        3 1  # colour rep (1: singlet, 3: triplet, 8: octet)
        4 0  # Particle/Antiparticle distinction (0=own anti)
Block QNUMBERS 9000006  # w1+ 
        1 3  # 3 times electric charge
        2 3  # number of spin states (2S+1)
        3 1  # colour rep (1: singlet, 3: triplet, 8: octet)
        4 1  # Particle/Antiparticle distinction (0=own anti)
Block QNUMBERS 9000007  # t1 
        1 2  # 3 times electric charge
        2 2  # number of spin states (2S+1)
        3 3  # colour rep (1: singlet, 3: triplet, 8: octet)
        4 1  # Particle/Antiparticle distinction (0=own anti)
Block QNUMBERS 9000008  # h1 
        1 0  # 3 times electric charge
        2 1  # number of spin states (2S+1)
        3 1  # colour rep (1: singlet, 3: triplet, 8: octet)
        4 0  # Particle/Antiparticle distinction (0=own anti)

*/
void madMela::setDefaultMadgraphValues(){
    //Now WIPE all the couplings!!!
    params_r_.mdl_cg = 0;
    params_r_.mdl_cw = 0;
    params_r_.mdl_ch = 0;
    params_r_.mdl_chbox = 0;
    params_r_.mdl_chdd = 0;
    params_r_.mdl_chg = 0;
    params_r_.mdl_chw = 0;
    params_r_.mdl_chb = 0;
    params_r_.mdl_chwb = 0;
    params_r_.mdl_cehre = 0;
    params_r_.mdl_cuhre = 0;
    params_r_.mdl_cdhre = 0;
    params_r_.mdl_cewre = 0;
    params_r_.mdl_cebre = 0;
    params_r_.mdl_cugre = 0;
    params_r_.mdl_cuwre = 0;
    params_r_.mdl_cubre = 0;
    params_r_.mdl_cdgre = 0;
    params_r_.mdl_cdwre = 0;
    params_r_.mdl_cdbre = 0;
    params_r_.mdl_chl1 = 0;
    params_r_.mdl_chl3 = 0;
    params_r_.mdl_che = 0;
    params_r_.mdl_chq1 = 0;
    params_r_.mdl_chq3 = 0;
    params_r_.mdl_chu = 0;
    params_r_.mdl_chd = 0;
    params_r_.mdl_chudre = 0;
    params_r_.mdl_cll = 0;
    params_r_.mdl_cll1 = 0;
    params_r_.mdl_cqq1 = 0;
    params_r_.mdl_cqq11 = 0;
    params_r_.mdl_cqq3 = 0;
    params_r_.mdl_cqq31 = 0;
    params_r_.mdl_clq1 = 0;
    params_r_.mdl_clq3 = 0;
    params_r_.mdl_cee = 0;
    params_r_.mdl_cuu = 0;
    params_r_.mdl_cuu1 = 0;
    params_r_.mdl_cdd = 0;
    params_r_.mdl_cdd1 = 0;
    params_r_.mdl_ceu = 0;
    params_r_.mdl_ced = 0;
    params_r_.mdl_cud1 = 0;
    params_r_.mdl_cud8 = 0;
    params_r_.mdl_cle = 0;
    params_r_.mdl_clu = 0;
    params_r_.mdl_cld = 0;
    params_r_.mdl_cqe = 0;
    params_r_.mdl_cqu1 = 0;
    params_r_.mdl_cqu8 = 0;
    params_r_.mdl_cqd1 = 0;
    params_r_.mdl_cqd8 = 0;
    params_r_.mdl_cledqre = 0;
    params_r_.mdl_cquqd1re = 0;
    params_r_.mdl_cquqd11re = 0;
    params_r_.mdl_cquqd8re = 0;
    params_r_.mdl_cquqd81re = 0;
    params_r_.mdl_clequ1re = 0;
    params_r_.mdl_clequ3re = 0;

    params_r_.mdl_cgtil = 0;
    params_r_.mdl_cwtil = 0;
    params_r_.mdl_chgtil = 0;
    params_r_.mdl_chwtil = 0;
    params_r_.mdl_chbtil = 0;
    params_r_.mdl_chwbtil = 0;
    params_r_.mdl_cewim = 0;
    params_r_.mdl_cebim = 0;
    params_r_.mdl_cugim = 0;
    params_r_.mdl_cuwim = 0;
    params_r_.mdl_cubim = 0;
    params_r_.mdl_cdgim = 0;
    params_r_.mdl_cdwim = 0;
    params_r_.mdl_cdbim = 0;
    params_r_.mdl_chudim = 0;
    params_r_.mdl_cehim = 0;
    params_r_.mdl_cuhim = 0;
    params_r_.mdl_cdhim = 0;
    params_r_.mdl_cledqim = 0;
    params_r_.mdl_cquqd1im = 0;
    params_r_.mdl_cquqd8im = 0;
    params_r_.mdl_cquqd11im = 0;
    params_r_.mdl_cquqd81im = 0;
    params_r_.mdl_clequ1im = 0;
    params_r_.mdl_clequ3im = 0;
}

void madMela::initialize_madMELA(){

    params_r_.mdl_ckmlambda = 2.265000e-01;
    params_r_.mdl_ckma = 7.900000e-01;
    params_r_.mdl_ckmrho = 1.410000e-01;
    params_r_.mdl_ckmeta = 0;

    params_r_.mdl_lambdasmeft = 1.000000e+03;
    params_r_.mdl_linearpropcorrections = 0;

    //Trying to set all the masses the same as the rest of MELA!
    mad_masses_.mdl_md =  TUtil::GetMass(1); //4.670000e-03;
    mad_masses_.mdl_mu =  TUtil::GetMass(2); //2.160000e-03;
    mad_masses_.mdl_ms =  TUtil::GetMass(3); //9.300000e-02;
    mad_masses_.mdl_mc =  TUtil::GetMass(4); //1.270000e+00;
    mad_masses_.mdl_mb =  TUtil::GetMass(5); //4.180000e+00;
    mad_masses_.mdl_mt =  TUtil::GetMass(6); //1.727600e+02;

    mad_masses_.mdl_me =  TUtil::GetMass(11);  //5.110000e-04;
    mad_masses_.mdl_mmu = TUtil::GetMass(13);  //1.056600e-01;
    mad_masses_.mdl_mta = TUtil::GetMass(15);  //1.777000e+00;

    mad_masses_.mdl_mz =  TUtil::GetMass(23);  //9.118760e+01;
    mad_masses_.mdl_mw =  TUtil::GetMass(24);  //7.983133e+01;
    mad_masses_.mdl_mh =  TUtil::GetMass(25);  //1.250900e+02;

    widths_.mdl_wt = TUtil::GetDecayWidth(6);
    widths_.mdl_wz = TUtil::GetDecayWidth(23);
    widths_.mdl_ww = TUtil::GetDecayWidth(24);
    widths_.mdl_wh = TUtil::GetDecayWidth(25);

    params_r_.mdl_ymdo = TUtil::GetMass(1);
    params_r_.mdl_ymup = TUtil::GetMass(2);
    params_r_.mdl_yms =  TUtil::GetMass(3);
    params_r_.mdl_ymc =  TUtil::GetMass(4);
    params_r_.mdl_ymb =  TUtil::GetMass(5);
    params_r_.mdl_ymt =  TUtil::GetMass(6);
    
    params_r_.mdl_yme =   TUtil::GetMass(11);
    params_r_.mdl_ymm =   TUtil::GetMass(13);
    params_r_.mdl_ymtau = TUtil::GetMass(15);

    params_r_.mdl_aew = 7.815553e-03;
    params_r_.mdl_gf = 1.166379e-05;
    params_r_.as = qcdcouple_.as; //1.179000e-01;

    setDefaultMadgraphValues();

    updateMap = new std::map<std::pair<TVar::Process, TVar::Production>, MG_process_double>;

    MG_process_double ggFSIG = {
        ggFSIG_smatrixhel_,
        ggFSIG_update_all_coup_,
    };
    (*updateMap)[std::make_pair(TVar::Madgraph_sig, TVar::ZZGG)] = ggFSIG;

    MG_process_double qq4lSIG = {
        qq4lSIG_smatrixhel_,
        qq4lSIG_update_all_coup_,
    };
    (*updateMap)[std::make_pair(TVar::Madgraph_sig, TVar::ZZQQB)] = qq4lSIG;

    MG_process_double qq4lBKG = {
        qq4lBKG_smatrixhel_,
        qq4lBKG_update_all_coup_,
    };
    (*updateMap)[std::make_pair(TVar::Madgraph_bkg, TVar::ZZQQB)] = qq4lBKG;

    MG_process_double qq4lBSI = {
        qq4lBSI_smatrixhel_,
        qq4lBSI_update_all_coup_,
    };
    (*updateMap)[std::make_pair(TVar::Madgraph_bsi, TVar::ZZQQB)] = qq4lBSI;
}

void madMela::update_all_coup(const TVar::Process& process, const TVar::Production& production){
    std::pair<TVar::Process, TVar::Production> key = std::make_pair(process, production);
    if ((*updateMap).find(key) == (*updateMap).end()){
        MELAerr << "madMela::update_all_coup: Incorrect key used!"
            " The keys provided were process=" << TVar::ProcessName(process) << 
            ", production=" << TVar::ProductionName(production) << 
            std::endl;
        return;
    }
    auto updateFunc = (*updateMap)[key].second;
    updateFunc();
}

void madMela::smatrixhel(
    const TVar::Process& process, const TVar::Production& production,
    int pdgs[], int& procid, const int& npdg, double* p, double& alphas, 
    double& scale2, int& nhel, double& ans
    ){
    std::pair<TVar::Process, TVar::Production> key = std::make_pair(process, production);
    if ((*updateMap).find(key) == (*updateMap).end()){
        MELAerr << "madMela::smatrixhel: Incorrect key used!"
            " The keys provided were " << process << ", " << production << std::endl;
        ans = 0;
        return;
    }
    auto computeFunc = (*updateMap)[std::make_pair(process, production)].first;
    computeFunc(pdgs, procid, npdg, p, alphas, scale2, nhel, ans);
}
