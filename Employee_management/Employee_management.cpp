//main
#include "Utility.h"

/*-------------------------------------------------
 M_menu(): 메인 메뉴
-------------------------------------------------*/
int M_menu() {
	int num;

	cout << "인사관리" << endl << endl;
	cout << "1.사원관리      2.기초정보관리" << endl;
	cout << "3.가족사항등록  4.퇴직자등록" << endl;
	cout << "5.인사정보      6.등록된 회원번호" << endl;
	cout << "7.종료" << endl;
	cin >> num;
	return num;
}

int main() {
	Employee emp_E;
	Basic_info bas;
	Retiree rtr_R;
	int num;

	Load_Data(emp_E,rtr_R,bas);

	while ((num = M_menu()) != M::Quit) {
		switch (num) {
			case M::Emp:	//사원관리
				E_main(emp_E,bas,rtr_R);
				break;
			case M::Bas:	//기초정보관리
				B_main(bas);
				break;
			case M::Fam:	//가족사항등록
				F_main(emp_E,rtr_R);
				break;
			case M::Ret:	//퇴직자등록
				R_main(emp_E,rtr_R,bas);
				break;
			case M::Hri:	//인사정보
				H_main(emp_E,rtr_R);
				break;
			case M::Test:	//등록된 사원번호 출력
				emp_E.all_show();
				break;
			default:		//다시입력
				system("cls");
				emp_E.add();
				cout << "다시 입력해주세요"<<endl;
		}
	
	}

	Save_Data(emp_E,rtr_R);
	return 0;
}
