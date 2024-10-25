#include "HRI.h"

/*-------------------------------------------------
 F_All_print(Employee &): 사원정보 출력(전체)
-------------------------------------------------*/
void F_All_print(Employee &emp_E) {
	ofstream ost;
	string data;

	if (emp_E.count() > 0) {
		ost.open("사원명부\\사원명부(전체).txt", ios::out);

		//사원번호 11자리 성명 2~4자리 부서 3자리 직위 2~3자리 입사일자 10자리 생년월일 10자리
		ost << "|  사원번호  |   성명   |  부서  |  직위  |  입사일자  |  생년월일  |\n";
		ost << "----------------------------------------------------------------------\n";
		ost.close();

		emp_E.set_data_ALL();
		cout << "파일이 출력되었습니다." << endl;
	}
	else {
		cout << "출력할 정보가 없습니다." << endl;
	}
}

/*-------------------------------------------------
 F_Pos_print(Employee &): 사원정보 출력(직위)
-------------------------------------------------*/
void F_Pos_print(Employee &emp_E) {
	ofstream ost;
	string data,POS;

	cout << "직위명을 입력하세요: ";
	cin >> POS;
	if (emp_E.p_count(POS) > 0) {
		if (emp_E.p_check1(POS) == true) {
			ost.open("사원명부\\사원명부(직위).txt", ios::out);
			ost << "직위명: " << POS;
			ost << "총원: " << emp_E.p_count(POS);

			ost << "|  사원번호  |   성명   |  부서  |  입사일자  |  생년월일  |\n";
			ost << "----------------------------------------------------------------------\n";
			ost.close();
			emp_E.set_data_POS(POS);
			cout << "파일이 출력되었습니다." << endl;
		}
		cout << "존재하지않는 직위명 입니다." << endl;
	}
	else {
		cout << "출력할 정보가 없습니다." << endl;
	}
}

/*-------------------------------------------------
 F_Dep_print(Employee &): 사원정보 출력(부서)
-------------------------------------------------*/
void F_Dep_print(Employee &emp_E) {
	ofstream ost;
	string data, DEP;

	cout << "부서명을 입력하세요: ";
	cin >> DEP;
	if (emp_E.d_count(DEP) > 0) {
		if (emp_E.d_check1(DEP) == true) {
			ost.open("사원명부\\사원명부(부서).txt", ios::out);
			ost << "부서명: " << DEP;
			ost << "총원: " << emp_E.d_count(DEP);

			ost << "|  사원번호  |   성명   |  직위  |  입사일자  |  생년월일  |\n";
			ost << "----------------------------------------------------------------------\n";
			ost.close();
			emp_E.set_data_DEP(DEP);
			cout << "파일이 출력되었습니다." << endl;
		}
		cout << "존재하지않는 직위명 입니다." << endl;
	}
	else {
		cout << "출력할 정보가 없습니다." << endl;
	}
}

/*-------------------------------------------------
 F_Ret_print(Employee &, Retiree &): 사원정보 출력(퇴직자)
-------------------------------------------------*/
void F_Ret_print(Employee &emp_E, Retiree &rtr_R) {
	ofstream ost;
	string data;
	if (emp_E.r_count() > 0) {
		ost.open("사원명부\\사원명부(퇴직자).txt", ios::out);

		//사원번호 11자리 성명 2~4자리 부서 3자리 직위 2~3자리 입사일자 10자리 생년월일 10자리
		ost << "|  사원번호  |  부서  |  직위  |  퇴사일자  |   성명   |\n";
		ost << "----------------------------------------------------------------------\n";
		ost.close();

		rtr_R.set_data_RET(emp_E);
		cout << "파일이 출력되었습니다." << endl;
	}
	else {
		cout << "출력할 정보가 없습니다." << endl;
	}
}