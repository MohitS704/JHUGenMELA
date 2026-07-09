#ifndef _TMODJHUGENMELA_HH_
#define _TMODJHUGENMELA_HH_

#include "TCouplingsBase.hh"

// NOTE: LOGICAL==INT, LOGICAL*1==BOOL(!???): http://www.yolinux.com/TUTORIALS/LinuxTutorialMixingFortranAndC.html

extern "C" {

  void __modjhugenmela_MOD_setewparameters(double* inMZ, double* inMW, double* inGf, double* inalpha_QED, double* inxw);
  void __modjhugenmela_MOD_setdecaymodes(int idfirst[2], int idsecond[2]);
  void __modjhugenmela_MOD_setdistinguishwwcouplingsflag(int* doallow); // YES, THE ARGUMENT IS AN INT, NOT A BOOL!
  void __modjhugenmela_MOD_sethdk(int* flag);
  void __modjhugenmela_MOD_sethiggsmasswidth(double *mass, double *width);
  void __modjhugenmela_MOD_setmurenfac(double* muren, double* mufac);
  void __modjhugenmela_MOD_resetmubarhgabarh();
  void __modjhugenmela_MOD_resetamplitudeincludes();
  void __modjhugenmela_MOD_setmvgv();
  void __modjhugenmela_MOD_setmvgvfromvertex(int* idV);
  void __modjhugenmela_MOD_setspinonecouplings(double qqcoupl[SIZE_ZQQ][2], double vvcoupl[SIZE_ZVV][2]);
  //void __modjhugenmela_MOD_setspintwocouplings(double acoupl[SIZE_GGG][2], double vvcoupl[SIZE_GVV][2], double vvpcoupl[SIZE_GVV][2], double vpvpcoupl[SIZE_GVV][2], double qlr[SIZE_GQQ][2]);
  void __modjhugenmela_MOD_setspintwocouplings(double acoupl[SIZE_GGG][2], double vvcoupl[SIZE_GVV][2], double vvpcoupl[SIZE_GVV][2], double vpvpcoupl[SIZE_GVV][2], double qlr[SIZE_GQQ][2], int* calc_fAmp);
  void __modjhugenmela_MOD_setspinzeroggcouplings(double ggcoupl[SIZE_HGG][2]);
  void __modjhugenmela_MOD_setspinzeroqqcouplings(double qqcoupl[SIZE_HQQ][2]);

  //void __modjhugenmela_MOD_setspinzerovvcouplings(double vvcoupl[SIZE_HVV][2], double vvpcoupl[SIZE_HVV][2], double vpvpcoupl[SIZE_HVV][2], int cqsq[SIZE_HVV_CQSQ], double Lambda_qsq[SIZE_HVV_LAMBDAQSQ][SIZE_HVV_CQSQ], int* usewwcoupl); // YES, THE LAST ARGUMENT IS AN INT!
  void __modjhugenmela_MOD_setspinzerovvcouplings(double vvcoupl[SIZE_HVV][2], double vvpcoupl[SIZE_HVV][2], double vpvpcoupl[SIZE_HVV][2], int cqsq[SIZE_HVV_CQSQ], double Lambda_qsq[SIZE_HVV_LAMBDAQSQ][SIZE_HVV_CQSQ], int* usewwcoupl, double* HvvPLcoupl, double* HvvfPerpcoupl,double Hvv_as_coupl[SIZE_as_HVV][2], int* calc_fL);
  
  
  void __modjhugenmela_MOD_setx1x2spinzeroggcouplings(std::complex<double> ggcoupl[2*SIZE_HGG]);
  void __modjhugenmela_MOD_setx1x2spinzeroqqcouplings(std::complex<double> qqcoupl[2*SIZE_HQQ]);
  void __modjhugenmela_MOD_setx1x2spinzerovvcouplings(std::complex<double> vvcoupl[2*SIZE_HVV], double vvpcoupl[SIZE_HVV][2], double vpvpcoupl[SIZE_HVV][2], int cqsq[2][SIZE_HVV_CQSQ], double Lambda_qsq[2][SIZE_HVV_LAMBDAQSQ][SIZE_HVV_CQSQ], int* usewwcoupl, double HvvPLcoupl[2], double HvvfPerpcoupl[2],std::complex<double>  Hvv_as_coupl[2*SIZE_as_HVV], int calc_X_fL[2]);
  void __modjhugenmela_MOD_setx1x2spinonecouplings(std::complex<double> qqcoupl[2*SIZE_ZQQ], std::complex<double> vvcoupl[2*SIZE_ZVV]);
   void __modjhugenmela_MOD_setx1x2spintwocouplings(std::complex<double> acoupl[2*SIZE_GGG], std::complex<double> vvcoupl[2*SIZE_GVV], double vvpcoupl[SIZE_GVV][2], double vpvpcoupl[SIZE_GVV][2], std::complex<double> qlr[2*SIZE_GQQ], int calc_X_fAmp[2]);

  void __modjhugenmela_MOD_setvprimecontactcouplings(double Zpffcoupl[SIZE_Vpff][2], double Wpffcoupl[SIZE_Vpff][2]);
  void __modjhugenmela_MOD_setazffcouplings(double AZffcoupl[SIZE_AZff][2]);
  void __modjhugenmela_MOD_settopdecays(int* flag);

  void __modjhugenmela_MOD_getmvgv(double* mv, double* gv);
  void __modjhugenmela_MOD_getmvprimegvprime(double* mv, double* gv);
  void __modjhugenmela_MOD_getalphasalphasmz(double* val_as, double* val_asmz);
  void __modjhugenmela_MOD_getpdfconstants(double* pdfzmass, int* pdfnloops, int* pdfnf);
  void __modjhugenmela_MOD_getdecaycouplings(int* VVMode, int idordered[4], double* aL1, double* aR1, double* aL2, double* aR2);

}

#endif

