#ifndef __UTIL__
#define __UTIL__
#include "HRI.h"

int E_menu();
void E_main(Employee&, Basic_info&, Retiree&);
int B_menu();
void B_main(Basic_info&);
int B_D_menu();
int B_R_menu();
int B_P_menu();
void B_D_main(Basic_info&);
void B_R_main(Basic_info&);
void B_P_main(Basic_info&);
int F_menu();
void F_main(Employee&, Retiree&);
int R_menu();
void R_main(Employee&,Retiree&,Basic_info&);
int S_menu();
void S_main(Employee&);
int H_menu();
void H_main(Employee&, Retiree&);
void Save_Data(Employee&,Retiree&);
void Load_Data(Employee&, Retiree&, Basic_info&);

#endif