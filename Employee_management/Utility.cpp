#include "Utility.h"

/*-------------------------------------------------
 E_menu(): 사원 메뉴
-------------------------------------------------*/
int E_menu() {
	int num;

	cout << "사원정보" << endl << endl;
	cout << "1.사원등록" << endl;
	cout << "2.사원수정" << endl;
	cout << "3.사원삭제" << endl;
	cout << "4.사원검색" << endl;
	cout << "5.뒤로가기" << endl;
	cin >> num;
	fflush(stdin);
	return num;
}

/*-------------------------------------------------
 E_main(Employee&, Basic_info&, Retiree&): 사원 메인
-------------------------------------------------*/
void E_main(Employee& emp_E, Basic_info& bas, Retiree& rtr_R) {
	system("cls");
	int num;
	string Rtr_num;

	while ((num = E_menu()) != E::Exit) {
		fflush(stdin);
		/*현재 한글이름 입력할때 씹힘*/
		switch (num) {
			case E::Reg: //사원등록
				if (bas.data_state() == true) {
					emp_E.set_emp(bas,emp_E);
				}
				else {
					cout << "기초데이터가 없습니다." << endl;
				}
				break;
			case E::Mod: //사원수정
				if ((Rtr_num=emp_E.E_update()) != "") {
					emp_E.emp_update(Rtr_num,bas,emp_E);
				}
				break;
			case E::Del: //사원삭제
				if ((Rtr_num=emp_E.R_regist()) != "") {
					rtr_R.set_rtr(Rtr_num);
				}
				break;
			case E::Ser: //사원검색
				if (emp_E.emp_empty() == false) {
					S_main(emp_E);
				}
				else {
					cout << "등록된 사원이 없습니다." << endl;
				}
				break;
			default:	 //다시입력
				system("cls");
				cout << "다시 입력해주세요" << endl;
		}
	}
	Save_Data(emp_E, rtr_R);
}

/*-------------------------------------------------
 B_menu(): 기초정보 메뉴
-------------------------------------------------*/
int B_menu() {
	int num;

	cout << "기초정보" << endl << endl;
	cout << "1.부서등록" << endl;
	cout << "2.종교등록" << endl;
	cout << "3.직위등록" << endl;
	cout << "4.뒤로가기" << endl;
	cin >> num;
	return num;
}

/*-------------------------------------------------
 B_main(Basic_info& ): 기초정보 메인
-------------------------------------------------*/
void B_main(Basic_info& bas) {
	system("cls");

	int num;

	while ((num = B_menu()) != B::Exit) {
		switch (num) {
			case B::Dep: //부서등록
				bas.set_dep();
				break;

			case B::Rel: //종교등록
				bas.set_rel();
				break;

			case B::Pos: //직위등록
				bas.set_pos();
				break;

			default:	 //다시입력
				bas.show_all();
				/*system("cls");
				cout << "다시 입력해주세요" << endl;*/
		}

	}
}

/*-------------------------------------------------
 B_D_menu(): 부서등록 메뉴
-------------------------------------------------*/
int B_D_menu() {
	int num;

	cout << "부서등록" << endl << endl;
	cout << "1.부서검색" << endl;
	cout << "2.부서입력" << endl;
	cout << "3.부서수정" << endl;
	cout << "4.부서삭제" << endl;
	cout << "5.뒤로가기" << endl;
	cin >> num;
	return num;
}

/*-------------------------------------------------
 B_R_menu(): 종교등록 메뉴
-------------------------------------------------*/
int B_R_menu() {
	int num;

	cout << "종교등록" << endl << endl;
	cout << "1.종교검색" << endl;
	cout << "2.종교입력" << endl;
	cout << "3.종교수정" << endl;
	cout << "4.종교삭제" << endl;
	cout << "5.뒤로가기" << endl;
	cin >> num;
	return num;
}

/*-------------------------------------------------
 B_P_menu(): 직위등록 메뉴
-------------------------------------------------*/
int B_P_menu() {
	int num;

	cout << "직위등록" << endl << endl;
	cout << "1.직위검색" << endl;
	cout << "2.직위입력" << endl;
	cout << "3.직위수정" << endl;
	cout << "4.직위삭제" << endl;
	cout << "5.뒤로가기" << endl;
	cin >> num;
	return num;
}

/*-------------------------------------------------
 B_D_main(Basic_info& ): 부서등록 메인
-------------------------------------------------*/
void B_D_main(Basic_info& bas) {
	system("cls");

	int num;

	while ((num = B_D_menu()) != B_sub::Exit) {
		switch (num) {
			case B_sub::Ser: //부서조회
				if (bas.d_state() == true) {
					bas.show_dep();
				}
				else {
					cout << "조회할 부서가 없습니다." << endl;
				}
				break;

			case B_sub::Ins: //부서입력
				bas.set_dep();
				break;

			case B_sub::Mod: //부서수정
				if (bas.d_state() == true) {
					bas.show_dep();
					bas.update_dep();
				}
				else {
					cout << "수정할 부서가 없습니다." << endl;
				}
				break;

			case B_sub::Del: //부서삭제
				if (bas.d_state() == true) {
					bas.show_dep();
				}
				else {
					cout << "삭제할 부서가 없습니다." << endl;
				}
				break;

			default:	 //다시입력
				system("cls");
				cout << "다시 입력해주세요" << endl;
		}

	}
}

/*-------------------------------------------------
 B_R_main(Basic_info& ): 종교등록 메인
-------------------------------------------------*/
void B_R_main(Basic_info& bas) {
	system("cls");

	int num;

	while ((num = B_R_menu()) != B_sub::Exit) {
		switch (num) {
			case B_sub::Ser: //종교조회
				if (bas.r_state() == true) {
					bas.show_rel();
				}
				else {
					cout << "조회할 부서가 없습니다." << endl;
				}

				break;

			case B_sub::Ins: //종교입력
				bas.set_rel();
				break;

			case B_sub::Mod: //종교수정
				if (bas.r_state() == true) {
					bas.show_rel();
					bas.update_rel();
				}
				else {
					cout << "수정할 종교가 없습니다." << endl;
				}
				break;

			case B_sub::Del: //종교삭제
				if (bas.r_state() == true) {
					bas.show_rel();
					
				}
				else {
					cout << "수정할 종교가 없습니다." << endl;
				}
				break;

			default:	 //다시입력
				system("cls");
				cout << "다시 입력해주세요" << endl;
		}

	}
}

/*-------------------------------------------------
 B_P_main(Basic_info& ): 직위등록 메인
-------------------------------------------------*/
void B_P_main(Basic_info& bas) {
	system("cls");

	int num;

	while ((num = B_P_menu()) != B_sub::Exit) {
		switch (num) {
			case B_sub::Ser: //직위조회
				if (bas.p_state() == true) {
					bas.show_pos();
				}
				else {
					cout << "조회할 종교가 없습니다." << endl;
				}
				break;

			case B_sub::Ins: //직위입력
				bas.set_pos();
				break;

			case B_sub::Mod: //직위수정
				if (bas.p_state() == true) {
					bas.show_pos();
					bas.update_pos();
				}
				else {
					cout << "수정할 부서가 없습니다." << endl;
				}
				break;

			case B_sub::Del: //직위삭제
				if (bas.p_state() == true) {
					bas.show_pos();
				}
				else {
					cout << "삭제할 부서가 없습니다." << endl;
				}
				break;

			default:	 //다시입력
				system("cls");
				cout << "다시 입력해주세요" << endl;
		}

	}
}

/*-------------------------------------------------
 F_menu(): 가족등록 메뉴
-------------------------------------------------*/
int F_menu() {
	int num;

	cout << "가족사항등록" << endl << endl;
	cout << "1.가족사항입력" << endl;
	cout << "2.가족사항조회" << endl;
	cout << "3.가족사항수정" << endl;
	cout << "4.가족사항삭제" << endl;
	cout << "5.뒤로가기" << endl;
	cin >> num;

	return num;
}

/*-------------------------------------------------
 F_main(Employee&, Retiree&): 가족등록 메인
-------------------------------------------------*/
void F_main(Employee& emp_E, Retiree& rtr_R) {
	int num;
	string Emp_num;

	cout << "사원번호:";
	cin >> Emp_num;
	system("cls");

	if (emp_E.compare(Emp_num) == true) {
		while ((num = F_menu()) != F::Exit) {
			switch (num) {
				case F::Reg:	//가족사항입력
					emp_E.F_regist1(Emp_num);
					break;
				case F::Ser:	//가족사항조회
					if (emp_E.family_empty(Emp_num) == true) {
						emp_E.family_show(Emp_num);
					}
					else {
						cout << "등록된 가족사항이 없습니다." << endl;
					}
					break;
				case F::Mod:	//가족사항수정
					if (emp_E.family_empty(Emp_num) == true) {
						emp_E.family_modify(Emp_num);
					}
					else {
						cout << "등록된 가족사항이 없습니다." << endl;
					}
					break;
				case F::Del:	//가족사항삭제
					if (emp_E.family_empty(Emp_num) == true) {
						emp_E.family_delete(Emp_num);
					}
					else {
						cout << "등록된 가족사항이 없습니다." << endl;
					}
					break;
				default:		//다시입력
					system("cls");
					cout << "다시 입력해주세요" << endl;
			}

		}
		Save_Data(emp_E, rtr_R);
	}
	else {
		cout << "존재하지않는 사원입니다." << endl;
	}
}

/*-------------------------------------------------
 R_menu(): 퇴직자 메뉴
-------------------------------------------------*/
int R_menu() {
	int num;

	cout << "퇴직자 등록" << endl << endl;
	cout << "1.퇴직자 명단 조회" << endl;
	cout << "2.퇴직자 명단 생성" << endl;
	cout << "3.퇴직자 명단 수정" << endl;
	cout << "4.뒤로가기" << endl;
	cin >> num;
	return num;
}

/*-------------------------------------------------
 R_main(Employee&, Retiree&, Basic_info&): 퇴직자 메인
-------------------------------------------------*/
void R_main(Employee& emp_E, Retiree& rtr_R ,Basic_info& bas) {
	int num;
	system("cls");

	while ((num = R_menu()) != R::Exit) {
		switch (num) {
			case R::Ser:	//퇴직자 명단 조회
				if (rtr_R.rtr_check1() == true) {
					rtr_R.show_rtr_data();
				}
				else {
					cout << "조회할 퇴직사원이 없습니다." << endl;
				}
				break;
			case R::Cre:	//퇴직자 명단 생성
				if (rtr_R.rtr_check2() == true) {
					rtr_R.set_rtr_data(bas);
				}
				else {
					cout << "생성할 퇴직사원이 없습니다." << endl;
				}
				break;
			case R::Mod:	//퇴직자 명단 수정
				if (rtr_R.rtr_check1() == true) {
					rtr_R.modify_rtr_data();
				}
				else {
					cout << "수정할 퇴직사원이 없습니다." << endl;
				}
				break;
			default:		//다시입력
				system("cls");
				cout << "다시 입력해주세요" << endl;
		}
	}
	Save_Data(emp_E, rtr_R);
}

/*-------------------------------------------------
 S_menu(): 사원검색 메뉴
-------------------------------------------------*/
int S_menu() {
	int num;

	cout << "사원 검색" << endl << endl;
	cout << "1.사원번호 검색" << endl;
	cout << "2.사원이름 검색" << endl;
	cout << "3.사원부서 검색" << endl;
	cout << "4.사원직잭 검색" << endl;
	cout << "5.뒤로가기" << endl;
	cin >> num;
	return num;
}

/*-------------------------------------------------
 S_main(): 사원검색 메인
-------------------------------------------------*/
void S_main(Employee &emp_E) {
	int num;
	system("cls");

	while ((num = S_menu()) != S::Exit) {
		switch (num) {
			case S::Num: //사원번호 검색
				emp_E.E_S_num();
				break;
			case S::Nam: //사원이름 검색
				emp_E.E_S_name();
				break;
			case S::Dep: //사원부서 검색
				emp_E.E_S_dep();
				break;
			case S::Pos: //사원직책 검색
				emp_E.E_S_pos();
				break;
			default:	 //다시입력
				system("cls");
				cout << "다시 입력해주세요" << endl;
			}

	}
}

/*-------------------------------------------------
 H_menu(): 인사검색 메뉴
-------------------------------------------------*/
int H_menu() {
	int num;
	cout << "인사 정보" << endl << endl;
	cout << "1.사원명부(전체)" << endl;
	cout << "2.사원명부(직위)" << endl;
	cout << "3.사원명부(부서)" << endl;
	cout << "4.퇴직자명부" << endl;
	cout << "5.뒤로가기" << endl;
	cin >> num;
	return num;
}

/*-------------------------------------------------
 H_main(Employee&, Retiree&): 인사검색 메인
-------------------------------------------------*/
void H_main(Employee &emp_E, Retiree &rtr_R) {
	int num;
	system("cls");

	while ((num = H_menu()) != H::Exit) {
		switch (num) {
		case H::All: //사원명부(전체) 출력
			F_All_print(emp_E);
			break;
		case H::Pos: //사원명부(직위) 출력
			F_Pos_print(emp_E);
			break;
		case H::Dep: //사원명부(부서) 출력
			F_Dep_print(emp_E);
			break;
		case H::Ret: //퇴직자명부 출력
			F_Ret_print(emp_E, rtr_R);
			break;
		default:	 //다시입력
			system("cls");
			cout << "다시 입력해주세요" << endl;
		}

	}
}

/*-------------------------------------------------
 Save_Data(Employee&, Retiree&): 데이터 저장하기
-------------------------------------------------*/
void Save_Data(Employee& emp_E, Retiree& rtr_R) {
	emp_E.f_set_emp();
	emp_E.f_set_fmy1();
	rtr_R.f_set_rtr();
}

/*-------------------------------------------------
 Load_Data(Employee&, Retiree&, Basic_info& ): 
 데이터 불러오기
-------------------------------------------------*/
void Load_Data(Employee &emp_E, Retiree &rtr_R, Basic_info &bas) {
	bas.f_get_dep();
	bas.f_get_rel();
	bas.f_get_pos();
	emp_E.f_get_emp();
	rtr_R.f_get_rtr();
}