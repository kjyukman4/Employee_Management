#include "Retiree.h"


P_info::P_info():
p_address(""),p_married(""),E_mail(""),p_sex("")
{
	for (int i = 0; i < 3; i++)	p_name[i] = "";
	for (int i = 0; i < 2; i++) p_num[i] = "";
	p_physical.height = 0.0;
	p_physical.weight = 0.0;
	p_physical.blood_type = "";
	p_physical.vision[0] = 0.0;	//좌
	p_physical.vision[1] = 0.0;	//우
}

P_info::~P_info() {

}

/*-------------------------------------------------
 P_info::set_P_info(Employee &): 사원 정보 입력
-------------------------------------------------*/
void P_info::set_P_info(Employee &emp_E) {
	unsigned int N,F1,F2;
	//성함 입력
	cout << "이름(한글):" << endl;
	getline(cin,p_name[0]);

	cout << "이름(영문):" << endl;
	getline(cin,p_name[1]);
	
	cout << "이름(한자):" << endl;
	getline(cin,p_name[2]);

	//주소 입력
	cout << "주소:" << endl;
	getline(cin,p_address);

	//결혼관계
	while (1) {
		cout << "결혼여부(1.미혼:2.기혼):" << endl;
		cin >> N;
		fflush(stdin);

		switch (N) {
			case 1:
				p_married = "미혼";
				break;
			case 2:
				p_married = "기혼";
				break;
			default:
				cout << "다시입력해주세요" << endl;
		}
		break;
	}

	//E_mail
	while (1) {
		cout << "E_mail(xxxxx@xxx.xx):";
		cin >> E_mail;
		fflush(stdin);
		if (e_mail_phone_check(E_mail, emp_E, 2) == false) {
			F1 = E_mail.find("@", 1);
			if (F1 >= 1 && F1 <= E_mail.size() - 1) {
				F2 = E_mail.find(".", F1 + 1);
				if (F2 >= F1 + 1 && F2 <= E_mail.size() - 1) {
					break;
				}
			}
			cout << "형식이 맞지않습니다." << endl;
		}
		else {
			cout << "중복된 이메일입니다." << endl;
		}
	}

	//연락처
	while (1) {
		cout << "연락처(핸드폰 11자리):";
		cin >> p_num[0];
		fflush(stdin);
		if (p_num[0].size() == 11) {
			if (e_mail_phone_check(p_num[0], emp_E, 1) == false) break;
			cout << "중복된 연락처입니다." << endl;
		}
		cout << "연락처는 11자리입니다." << endl;
	}
	while (1) {
		cout << "연락처(집 10자리):";
		cin >> p_num[1];
		fflush(stdin);
		if (p_num[1].size() == 10) {
			if (e_mail_phone_check(p_num[1], emp_E, 3) == false) break;
			cout << "중복된 연락처입니다." << endl;
		}
		else {
			cout << "연락처는 10자리입니다." << endl;
		}
	}

	//성별
	while (1) {
		cout << "성별(1.남:2.여):";
		cin >> N;
		fflush(stdin);

		switch (N) {
			case 1:
				p_sex = "남";
				break;
			case 2:
				p_sex = "여";
				break;
			default:
				cout << "다시입력해주세요" << endl;
		}
		break;
	}

	//신체사항
	cout << "신장(cm):";
	cin >> p_physical.height;
	fflush(stdin);

	cout << "체중(kg):";
	cin >> p_physical.weight;
	fflush(stdin);

	while (1) {
		cout << "혈액형(A,B,O,AB):";
		cin >> N;
		fflush(stdin);

		switch (N) {
			case 1:
				set_p_blood_type("A");
				break;
			case 2:
				set_p_blood_type("B");
				break;
			case 3:
				set_p_blood_type("O");
				break;
			case 4:
				set_p_blood_type("AB");
				break;
			default:
				cout << "다시입력해주세요" << endl;
		}
		break;
	}

	cout << "시력(좌):";
	cin >> p_physical.vision[0];	//좌
	fflush(stdin);
	cout << "시력(우):";
	cin >> p_physical.vision[1];	//우
	fflush(stdin);
}

string P_info::get_sex() {
	return p_sex;
}

string P_info::get_name() {
	return p_name[0];
}

/*-------------------------------------------------
 P_info::F_regist2(): 가족정보 벡터 삽입
-------------------------------------------------*/
void P_info::F_regist2() {
	Family F;

	F.set_information();

	f_relation.push_back(F);
}

/*-------------------------------------------------
 P_info::emp_show_data2(): 사원 한글 이름 출력
-------------------------------------------------*/
void P_info::emp_show_data2() {
	cout << p_name[0];
}

/*-------------------------------------------------
 P_info::family_show2(): 전체 가족 출력
-------------------------------------------------*/
void P_info::family_show2() {
	vector<Family>::iterator iter;
	for (iter = f_relation.begin(); iter != f_relation.end(); ++iter) {
		iter->show_information();
	}
}

/*-------------------------------------------------
 P_info::family_modify2(): 가족 정보 수정
-------------------------------------------------*/
void P_info::family_modify2() {
	vector<Family>::iterator iter;
	unsigned int i,n;

	while (1) {
		cout << "번호를 입력하세요:";
		cin >> n;

		i = 0;
		if (0 < n && n <= f_relation.size()) {
			for (iter = f_relation.begin(); iter != f_relation.end(); ++iter) {
				i++;
				if (i == n) {
					iter->set_information();
					break;
				}
			}
			break;
		}
		cout << "잘못입력하였습니다." << endl;
	}
}

/*-------------------------------------------------
 P_info::family_delete2(): 가족 정보 삭제
-------------------------------------------------*/
void P_info::family_delete2() {
	vector<Family>::iterator iter;
	unsigned int n, i;

	while (1) {
		cout << "번호를 입력하세요:";
		cin >> n;
		i = 0;
		if (0 < n && n <= f_relation.size()) {
			for (iter = f_relation.begin(); iter != f_relation.end(); ++iter) {
				i++;
				if (i == n) {
					f_relation.erase(f_relation.begin() + i - 1);
					break;
				}
			}
			break;
		}
		cout << "잘못입력하였습니다." << endl;
	}
}

void P_info::set_p_name(string name0, string name1, string name2) {
	p_name[0] = name0;
	p_name[1] = name1;
	p_name[2] = name2;
}

void P_info::set_p_address(string adr) {
	p_address = adr;
}

void P_info::set_p_married(string married) {
	p_married = married;
}

void P_info::set_p_E_mail(string E_m) {
	E_mail = E_m;
}

void P_info::set_p_num(string num0, string num1) {
	p_num[0] = num0;
	p_num[1] = num1;
}

void P_info::set_p_sex(string s) {
	p_sex = s;
}

void P_info::set_p_height(string height) {
	p_physical.height = stod(height);
}

void P_info::set_p_weight(string weight) {
	p_physical.weight = stod(weight);
}

void P_info::set_p_blood_type(string blood) {
	p_physical.blood_type = blood;
}

void P_info::set_p_vision(string v0, string v1) {
	p_physical.vision[0] = stod(v0);
	p_physical.vision[1] = stod(v1);
}

void P_info::f_set_fmy2(Family FD) {
	f_relation.push_back(FD);
}

void P_info::fmy_clear() {
	f_relation.clear();
}

/*-------------------------------------------------
 P_info::e_check(string) : 이메일 중복 체크
-------------------------------------------------*/
bool P_info::e_check(string St) {
	return (St == E_mail) ? true : false;
}

/*-------------------------------------------------
 P_info::p_check(string): 번호 중복 체크
-------------------------------------------------*/
bool P_info::p_check(string St) {
	return (St == p_num[0]) ? true : false;
}

/*-------------------------------------------------
 P_info::h_check(string): 주소 중복 체크
-------------------------------------------------*/
bool P_info::h_check(string St) {
	return (St == p_address) ? true : false;
}

/*-------------------------------------------------
 P_info::e_mail_phone_check(string, Employee &,int) 
 주소, 이메일, 번호 중복 체크
-------------------------------------------------*/
bool P_info::e_mail_phone_check(string St, Employee &emp_E, int s) {
	switch (s) {
		case 1:
			return emp_E.phone_dup_check(St);
		case 2:
			return emp_E.email_dup_check(St);
		case 3:
			return emp_E.home_dup_check(St);
		default:
			break;
	}
	return false;
}

/*-------------------------------------------------
 P_info::u_P_info(Employee&): 사원 신상 정보 수정
-------------------------------------------------*/
void P_info::u_P_info(Employee& emp_E) {
	unsigned int N, F1, F2;
	string T;

	cout << "\'#\'입력후 엔터치면 생략" << endl;
	//성함 입력
	cout << "이름(한글):" << endl;
	getline(cin, T);
	if (T != "#") {
		p_name[0] = T;
	}

	cout << "이름(영문):" << endl;
	getline(cin, T);
	if (T != "#") {
		p_name[1] = T;
	}

	cout << "이름(한자):" << endl;
	getline(cin, T);
	if (T != "#") {
		p_name[2] = T;
	}

	//주소 입력
	cout << "주소:" << endl;
	getline(cin, T);
	if (T != "#") {
		p_address = T;
	}

	//결혼관계
	while (1) {
		cout << "결혼여부(1.미혼:2.기혼):" << endl;
		cin >> T;
		fflush(stdin);
		if (T != "#") {
			N = stoi(T);
			switch (N) {
				case 1:
					p_married = "미혼";
					break;
				case 2:
					p_married = "기혼";
					break;
				default:
					cout << "다시입력해주세요" << endl;
				}
				break;
		}
		else {
			break;
		}
	}

	//E_mail
	while (1) {
		cout << "E_mail(xxxxx@xxx.xx):";
		cin >> T;
		fflush(stdin);
		if (T != "#") {
			if (e_mail_phone_check(E_mail, emp_E, 2) == false) {
				F1 = E_mail.find("@", 1);
				if (F1 >= 1 && F1 <= E_mail.size() - 1) {
					F2 = E_mail.find(".", F1 + 1);
					if (F2 >= F1 + 1 && F2 <= E_mail.size() - 1) {
						E_mail = T;
						break;
					}
				}
				cout << "형식이 맞지않습니다." << endl;
			}
			else {
				cout << "중복된 이메일입니다." << endl;
			}
		}
		else {
			break;
		}
	}

	//연락처
	while (1) {
		cout << "연락처(핸드폰 11자리):";
		cin >> T;
		fflush(stdin);
		if(T != "#"){
			if (p_num[0].size() == 11) {
				if (e_mail_phone_check(p_num[0], emp_E, 1) == false) {
					p_num[0] = T;
					break;
				}
				cout << "중복된 연락처입니다." << endl;
			}
			cout << "연락처는 11자리입니다." << endl;
		}
		else {
			break;
		}
	}
	while (1) {
		cout << "연락처(집 10자리):";
		cin >> T;
		fflush(stdin);
		if (T != "#") {
			if (p_num[1].size() == 10) {
				if (e_mail_phone_check(p_num[1], emp_E, 3) == false) {
					p_num[1] = T;
					break;
				}
				cout << "중복된 연락처입니다." << endl;
			}
			else {
				cout << "연락처는 10자리입니다." << endl;
			}
		}
		else {
			break;
		}
	}

	//성별
	while (1) {
		cout << "성별(1.남:2.여):";
		cin >> T;
		fflush(stdin);
		if (T != "#") {
			N = stoi(T);
			switch (N) {
				case 1:
					p_sex = "남";
					break;
				case 2:
					p_sex = "여";
					break;
				default:
					cout << "다시입력해주세요" << endl;
			}
			break;
		}
		else {
			break;
		}
	}

	//신체사항
	cout << "신장(cm):";
	cin >> T;
	fflush(stdin);
	if (T != "#") {
		p_physical.height = stof(T);
	}

	cout << "체중(kg):";
	cin >> T;
	fflush(stdin);
	if (T != "#") {
		p_physical.weight = stof(T);
	}

	while (1) {
		cout << "혈액형(A,B,O,AB):";
		cin >> T;
		fflush(stdin);
		if (T != "#") {
			N = stoi(T);
			switch (N) {
				case 1:
					set_p_blood_type("A");
					break;
				case 2:
					set_p_blood_type("B");
					break;
				case 3:
					set_p_blood_type("O");
					break;
				case 4:
					set_p_blood_type("AB");
					break;
				default:
					cout << "다시입력해주세요" << endl;
			}
			break;
		}
		else {
			break;
		}
	}

	cout << "시력(좌):";
	cin >> T;
	fflush(stdin);
	if (T != "#") {
		p_physical.vision[0] = stof(T);
	}

	cout << "시력(우):";
	cin >> T;
	fflush(stdin);
	if (T != "#") {
		p_physical.vision[1] = stof(T);
	}

}

/*-------------------------------------------------
 P_info::f_set_emp_bas2(): 사원정보 TEXT화
-------------------------------------------------*/
void P_info::f_set_emp_bas2(string &sub_data) {
	sub_data = p_name[0] + "," + p_name[1] + "," + p_name[2] + ",";
	sub_data += p_address + "," + p_married + "," + E_mail + "," + p_num[0] + "," + p_num[1] + "," + p_sex + ",";
	sub_data += to_string(p_physical.height) + "," + to_string(p_physical.weight) + "," + p_physical.blood_type + "," + to_string(p_physical.vision[0]) + "," + to_string(p_physical.vision[1]) + ",";
}

/*-------------------------------------------------
 P_info::f_set_fmy2(): 가족정보 TEXT화
-------------------------------------------------*/
void P_info::f_set_fmy2(string e_num) {
	vector<Family>::iterator iter;
	ofstream ost;
	string data;

	ost.open("사원기초정보\\가족정보.txt",ios::app);

	for (iter = f_relation.begin(); iter != f_relation.end(); ++iter) {
		ost << e_num << "," << iter->get_relation() << "," << iter->get_name() << "," << iter->get_birth() << "," << iter->get_marrid() << "," << iter->get_education() << "," << iter->get_job() << "," << iter->get_work_place() << "\n";
	}

	ost.close();
}

E_Data::E_Data():
p_department(""),p_religion(""),p_position(""),p_birth(""),p_join_date(""),
p_company_number(""),p_resident_number(""),p_retiree(false){

}

E_Data::~E_Data() {

}

/*-------------------------------------------------
 E_Data::E_regist(Basic_info&, Employee&): 사원등록
-------------------------------------------------*/
void E_Data::E_regist(Basic_info &bas ,Employee &emp_E) {
	string S,s,num;
	//사원신상 정보 등록
	set_P_info(emp_E);
	
	//사원정보 등록
	while(1) {
		cout << "생년월일(ex:1999.01.01):";
		cin >> p_birth;
		fflush(stdin);
		if (p_birth.size() == 10) {
			if (isdigit(p_birth[0]) != 0 && isdigit(p_birth[1]) != 0 && isdigit(p_birth[2]) != 0 && isdigit(p_birth[3]) != 0 && p_birth[4] == '.' && isdigit(p_birth[5]) != 0 && isdigit(p_birth[6]) != 0 && p_birth[7] == '.' && isdigit(p_birth[8]) != 0 && isdigit(p_birth[9]) != 0) {
				break;
			}
		}
		cout << "잘못된 형식입니다." << endl;
	}

	while (1) {
		cout << "입사일(ex:1999.01.01):";
		cin >> p_join_date;
		fflush(stdin);
		if (p_join_date.size() == 10) {
			if (isdigit(p_join_date[0]) != 0 && isdigit(p_join_date[1]) != 0 && isdigit(p_join_date[2]) != 0 && isdigit(p_join_date[3]) != 0 && p_join_date[4] == '.' && isdigit(p_join_date[5]) != 0 && isdigit(p_join_date[6]) != 0 && p_join_date[7] == '.' && isdigit(p_join_date[8]) != 0 && isdigit(p_join_date[9]) != 0) {
				break;
			}
		}
		cout << "잘못된 형식입니다." << endl;
	}
	
	S = p_join_date.substr(2, 2);
	S += p_join_date.substr(5, 2);
	S += p_join_date.substr(8, 2);

	s = (get_sex() == "남") ? "1": "2";
	
	while (1) {
		cout << "주민등록번호(" << S << "-" << s << "xxxxxx):";
		cin >> num;
		fflush(stdin);
		if (isdigit(num[0])!=0 && isdigit(num[1]) != 0 && isdigit(num[2]) != 0 && isdigit(num[3]) != 0 && isdigit(num[4]) != 0 && isdigit(num[5]) != 0 && num.size() == 6) {
			p_resident_number = S;
			p_resident_number += "-";
			p_resident_number += s;
			p_resident_number += num;
			break;
		}
		cout << "형식이 잘못되었습니다." << endl;
	}

	//기초 정보 등록
	bas.show_dep();
	p_department = bas.choice_dep();
	bas.show_rel();
	p_religion = bas.choice_rel();
	bas.show_pos();
	p_position = bas.choice_pos();

	//사원번호등록
	p_company_number += p_join_date.substr(0, 4);
	p_company_number += bas.D_trans_form(p_department);
	p_company_number += s;
}


/*-------------------------------------------------
 E_Data::set_p_company_number(string): 사원번호부여
-------------------------------------------------*/
void E_Data::set_p_company_number(string emp_num) {
	p_company_number += emp_num;
}
/*-------------------------------------------------
 E_Data::set_p_num2(string): 사원번호부여(수동)
-------------------------------------------------*/
void E_Data::set_p_num2(string num) {
	p_company_number = num;
}

void E_Data::set_p_resident_number(string resient_num) {
	p_resident_number = resient_num;
}

void E_Data::set_p_department(string department) {
	p_department = department;
}

void E_Data::set_p_religion(string religion) {
	p_religion = religion;
}

void E_Data::set_p_position(string position) {
	p_position = position;
}

void E_Data::set_p_birth(string birth) {
	p_birth = birth;
}

void E_Data::set_p_join_date(string join_date) {
	p_join_date = join_date;
}

void E_Data::set_p_retiree(string retiree) {
	if (retiree == "1") {
		p_retiree = true;
	}
	else {
		p_retiree = false;
	}
}

string E_Data::get_p_company_number() {
	return p_company_number;
}

string E_Data::get_p_company_department() {
	return p_department;
}

string E_Data::get_p_company_position() {
	return p_position;
}

string E_Data::get_p_company_j_date() {
	return p_join_date;
}

string E_Data::get_p_company_birth() {
	return p_birth;
}

void E_Data::print_C_N() {
	cout << p_company_number << endl;
}

void E_Data::change_retiree() {
	p_retiree = true;
}

/*-------------------------------------------------
 E_Data::u_department(Basic_info&): 부서 업데이트
-------------------------------------------------*/
void E_Data::u_department(Basic_info &bas) {
	p_department = bas.choice_dep();
}

/*-------------------------------------------------
 E_Data::u_religion(Basic_info&): 종교 업데이트
-------------------------------------------------*/
void E_Data::u_religion(Basic_info& bas) {
	p_religion = bas.choice_rel();
}

/*-------------------------------------------------
 E_Data::u_position(Basic_info&): 직위 업데이트
-------------------------------------------------*/
void E_Data::u_position(Basic_info& bas) {
	p_position = bas.choice_pos();
}

/*-------------------------------------------------
 E_Data::emp_show_data(): 사원 정보 출력
-------------------------------------------------*/
void E_Data::emp_show_data() {
	emp_show_data2();
	cout << p_department << p_religion << p_position << p_company_number << endl;
}

/*-------------------------------------------------
 E_Data::r_check(): 퇴직/복직 처리
-------------------------------------------------*/
bool E_Data::r_check() {
	return (p_retiree == false) ? true : false;
}

/*-------------------------------------------------
 E_Data::p_check2(string): 직위 존재 여부 확인 
-------------------------------------------------*/
bool E_Data::p_check2(string POS) {
	return (POS == p_position) ? true : false;
}

/*-------------------------------------------------
 E_Data::d_check2(string): 부서 존재 여부 확인
-------------------------------------------------*/
bool E_Data::d_check2(string DEP) {
	return (DEP == p_department) ? true : false;
}

/*-------------------------------------------------
 E_Data::E_update(Basic_info&, Employee&): 사원
 정보 수정
-------------------------------------------------*/
void E_Data::E_update(Basic_info& bas, Employee& emp_E) {
	string S, s, num,T;
	//사원신상 정보 등록
	u_P_info(emp_E);

	//사원정보 등록
	cout << "\'#\' 입력후 엔터를 누르면 생략" << endl;
	while (1) {
		cout << "생년월일(ex:1999.01.01):";
		cin >> T;
		fflush(stdin);
		if (T != "#") {
			p_birth = T;
			if (p_birth.size() == 10) {
				if (isdigit(p_birth[0]) != 0 && isdigit(p_birth[1]) != 0 && isdigit(p_birth[2]) != 0 && isdigit(p_birth[3]) != 0 && p_birth[4] == '.' && isdigit(p_birth[5]) != 0 && isdigit(p_birth[6]) != 0 && p_birth[7] == '.' && isdigit(p_birth[8]) != 0 && isdigit(p_birth[9]) != 0) {
					break;
				}
			}
			cout << "잘못된 형식입니다." << endl;
		}
		else {
			break;
		}
	}

	while (1) {
		cout << "입사일(ex:1999.01.01):";
		cin >> T;
		fflush(stdin);
		if (T != "#") {
			p_join_date = T;
			if (p_join_date.size() == 10) {
				if (isdigit(p_join_date[0]) != 0 && isdigit(p_join_date[1]) != 0 && isdigit(p_join_date[2]) != 0 && isdigit(p_join_date[3]) != 0 && p_join_date[4] == '.' && isdigit(p_join_date[5]) != 0 && isdigit(p_join_date[6]) != 0 && p_join_date[7] == '.' && isdigit(p_join_date[8]) != 0 && isdigit(p_join_date[9]) != 0) {
					break;
				}
			}
			cout << "잘못된 형식입니다." << endl;
		}
		else {
			break;
		}
	}

	S = p_join_date.substr(2, 2);
	S += p_join_date.substr(5, 2);
	S += p_join_date.substr(8, 2);

	s = (get_sex() == "남") ? "1" : "2";

	while (1) {
		cout << "주민등록번호(" << S << "-" << s << "xxxxxx):";
		cin >> T;
		fflush(stdin);
		if (T != "#") {
			num = T;
			if (isdigit(num[0]) != 0 && isdigit(num[1]) != 0 && isdigit(num[2]) != 0 && isdigit(num[3]) != 0 && isdigit(num[4]) != 0 && isdigit(num[5]) != 0 && num.size() == 6) {
				p_resident_number = S;
				p_resident_number += "-";
				p_resident_number += s;
				p_resident_number += num;
				break;
			}
			cout << "형식이 잘못되었습니다." << endl;
		}
		else {
			break;
		}
	}

	//기초 정보 등록
	bas.show_dep();
	p_department = bas.choice_dep();
	bas.show_rel();
	p_religion = bas.choice_rel();
	bas.show_pos();
	p_position = bas.choice_pos();

	//사원번호등록
	p_company_number += p_join_date.substr(0, 4);
	p_company_number += bas.D_trans_form(p_department);
	p_company_number += s;
}

void E_Data::f_set_emp_inf(string &POS, string &j_date, string &DEP) {
	POS = p_position;
	j_date = p_join_date;
	DEP = p_department;
}

void E_Data::f_set_emp_bas1(string &data) {
	string sub;
	f_set_emp_bas2(sub);
	data = sub;
	data += p_birth + "," + p_resident_number + "," + p_religion + ",";
	p_retiree == false ? data += "0\n" : data += "1\n";
}

Employee::Employee() {

}

Employee::~Employee() {

}

/*-------------------------------------------------
 Employee::set_emp(Basic_info&, Employee&): 사원
 번호 부여
-------------------------------------------------*/
void Employee::set_emp(Basic_info &bas, Employee &emp_E) {
	E_Data E;
	E.E_regist(bas,emp_E);
	if (emp.size()<10) {
		E.set_p_company_number("000" + to_string(emp.size() + 1));
	}
	else if (emp.size()<100) {
		E.set_p_company_number("00" + to_string(emp.size() + 1));
	}
	else if (emp.size() < 1000) {
		E.set_p_company_number("0" + to_string(emp.size() + 1));
	}
	else {
		E.set_p_company_number(to_string(emp.size() + 1));
	}
	emp.push_back(E);
	cout << E.get_name() << "의 사원번호는 " << E.get_p_company_number() << " 입니다." << endl;
}

/*-------------------------------------------------
 Employee::all_show(): 모든 사원 번호 출력
-------------------------------------------------*/
void Employee::all_show() {
	vector<E_Data>::iterator iter;

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		iter->print_C_N();
	}
}

/*-------------------------------------------------
 Employee::compare(string): 사원번호 존재 유무 확인
-------------------------------------------------*/
bool Employee::compare(string Emp_num) {
	vector<E_Data>::iterator iter;
	
	if (emp.size() != 0) {
		for (iter = emp.begin(); iter != emp.end(); ++iter) {
			if (iter->get_p_company_number() == Emp_num) return true;
		}
	}
	return false;
}

/*-------------------------------------------------
 Employee::F_regist1(string): r가족사항 등록
-------------------------------------------------*/
void Employee::F_regist1(string Emp_num) {
	vector<E_Data>::iterator iter;

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		if (iter->get_p_company_number() == Emp_num) {
			iter->F_regist2();
			break;
		}
	}

}

/*-------------------------------------------------
 Employee::R_regist(): 퇴직처리
-------------------------------------------------*/
string Employee::R_regist() {
	vector<E_Data>::iterator iter;
	string Rtr_num;

	cout << "사원번호:";
	cin >> Rtr_num;

	if (compare(Rtr_num) == true) {
		for (iter = emp.begin(); iter != emp.end(); ++iter) {
			if (iter->get_p_company_number() == Rtr_num && iter->r_check() == true) {
				iter->change_retiree();
				return Rtr_num;
			}
		}
	}
	else {
		cout << "존재하지않는 사원입니다." << endl;
	}

	return "";
}

/*-------------------------------------------------
 Employee::E_update(): 사원검색
-------------------------------------------------*/
string Employee::E_update() {
	vector<E_Data>::iterator iter;
	string Rtr_num;

	cout << "사원번호:";
	cin >> Rtr_num;

	if (compare(Rtr_num) == true) {
		for (iter = emp.begin(); iter != emp.end(); ++iter) {
			if (iter->get_p_company_number() == Rtr_num && iter->r_check() == true) {
				return Rtr_num;
			}
		}
	}
	else {
		cout << "존재하지않는 사원입니다." << endl;
	}

	return "";
}

/*-------------------------------------------------
 Employee::emp_update(string, Basic_info&, Employee&):
 사원기초정보 수정
-------------------------------------------------*/
void Employee::emp_update(string Rtr_num ,Basic_info &bas,Employee& emp_E) {
	vector<E_Data>::iterator iter;

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		if (iter->get_p_company_number() == Rtr_num) {
			iter->E_update(bas, emp_E);
		}
	}
	cout << "수정이 완료되었습니다." << endl;
}

/*-------------------------------------------------
 Employee::emp_empty(): 사원 존재유무 확인
-------------------------------------------------*/
bool Employee::emp_empty() {
	return emp.empty();
}

/*-------------------------------------------------
 Employee::E_S_num(): 사원 번호 검색
-------------------------------------------------*/
void Employee::E_S_num() {
	vector<E_Data>::iterator iter;
	string num;
	
	cout << "사원번호:";
	cin >> num;

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		if (iter->get_p_company_number() == num && iter->r_check() == true) {
			iter->emp_show_data();
		}
	}

}

/*-------------------------------------------------
 Employee::E_S_name(): 사원 이름 검색
-------------------------------------------------*/
void Employee::E_S_name() {
	vector<E_Data>::iterator iter;
	string name;

	cout << "사원이름:";
	cin >> name;

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		if (iter->get_name() == name && iter->r_check() == true) {
			iter->emp_show_data();
		}
	}
}

/*-------------------------------------------------
 Employee::E_S_dep(): 사원 부서 검색
-------------------------------------------------*/
void Employee::E_S_dep() {
	vector<E_Data>::iterator iter;
	string dep;

	cout << "부서:";
	cin >> dep;

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		if (iter->get_p_company_department() == dep && iter->r_check() == true) {
			iter->emp_show_data();
		}
	}
}

/*-------------------------------------------------
 Employee::E_S_pos(): 사원 직책 검색
-------------------------------------------------*/
void Employee::E_S_pos() {
	vector<E_Data>::iterator iter;
	string pos;

	cout << "직책:";
	cin >> pos;

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		if (iter->get_p_company_position() == pos && iter->r_check() == true) {
			iter->emp_show_data();
		}
	}
}

/*-------------------------------------------------
 Employee::family_empty(string): 가족 등록 유무 확인
-------------------------------------------------*/
bool Employee::family_empty(string Emp_num) {
	vector<E_Data>::iterator iter;

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		if (iter->get_p_company_number() == Emp_num) {
			return true;
		}
	}
	return false;
}

/*-------------------------------------------------
 Employee::family_show(string): 등록 가족 출력
-------------------------------------------------*/
void Employee::family_show(string Emp_num) {
	vector<E_Data>::iterator iter;

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		if (iter->get_p_company_number() == Emp_num) {
			iter->family_show2();
			break;
		}
	}
}

/*-------------------------------------------------
 Employee::family_modify(string): 가족 정보 수정
-------------------------------------------------*/
void Employee::family_modify(string Emp_num) {
	vector<E_Data>::iterator iter;

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		if (iter->get_p_company_number() == Emp_num) {
			iter->family_show2();
			iter->family_modify2();
			break;
		}
	}
}

/*-------------------------------------------------
 Employee::family_delete(string): 가족 정보 삭제
-------------------------------------------------*/
void Employee::family_delete(string Emp_num) {
	vector<E_Data>::iterator iter;

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		if (iter->get_p_company_number() == Emp_num) {
			iter->family_show2();
			iter->family_delete2();
			break;
		}
	}
}

/*-------------------------------------------------
 Employee::set_data_ALL(): 사원명부 출력(전체)
-------------------------------------------------*/
void Employee::set_data_ALL() {
	vector<E_Data>::iterator iter;
	ofstream ost;
	string data;

	ost.open("사원명부\\사원명부(전체).txt", ios::app);

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		if (iter->r_check() == true) {
			data = "| " + iter->get_p_company_number() + " |   " + iter->get_name() + " | " + iter->get_p_company_department() + " | " + iter->get_p_company_position() + "|" + iter->get_p_company_j_date() + " | " + iter->get_p_company_birth() + " |";
			ost << data << "\n";
		}
	}

	ost.close();
}

/*-------------------------------------------------
 Employee::add(): 사원 추가
-------------------------------------------------*/
void Employee::add() {

	vector<E_Data>::iterator iter;
	string POS, j_date, DEP, data;

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		iter->f_set_emp_inf(POS, j_date, DEP);
		iter->f_set_emp_bas1(data);
		cout << iter->get_p_company_number() << endl; 
		cout << POS << endl;
		cout << j_date << endl;
		cout << DEP << endl;
		cout << data << endl;
	}
}

/*-------------------------------------------------
 Employee::set_data_POS(string): 사원명부 출력(직위)
-------------------------------------------------*/
void Employee::set_data_POS(string POS) {
	vector<E_Data>::iterator iter;
	ofstream ost;
	string data;

	ost.open("사원명부\\사원명부(직위).txt", ios::app);

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		if (iter->r_check() == true) {
			if (iter->p_check2(POS) == true) {
				data = "| " + iter->get_p_company_number() + " |   " + iter->get_name() + " | " + iter->get_p_company_department() + " | " + iter->get_p_company_j_date() + " | " + iter->get_p_company_birth() + " |";
				ost << data << "\n";
			}
		}
	}
	ost.close();
}

/*-------------------------------------------------
 Employee::set_data_DEP(string): 사원명부 출력(부서)
-------------------------------------------------*/
void Employee::set_data_DEP(string DEP) {
	vector<E_Data>::iterator iter;
	ofstream ost;
	string data;

	ost.open("사원명부\\사원명부(부서).txt", ios::app);

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		if (iter->r_check() == true) {
			if (iter->d_check2(DEP) == true) {
				data = "| " + iter->get_p_company_number() + " |   " + iter->get_name() + " | " + iter->get_p_company_position() + " | " + iter->get_p_company_j_date() + " | " + iter->get_p_company_birth() + " |";
				ost << data << "\n";
			}
		}
	}
	ost.close();
}

/*-------------------------------------------------
 Employee::p_check1(string): 직위 존재 유무 확인
-------------------------------------------------*/
bool Employee::p_check1(string POS) {
	vector<E_Data>::iterator iter;

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		if (iter->p_check2(POS) == true) {
			return true;
		}
	}
	return false;
}

/*-------------------------------------------------
 Employee::p_count(string): 등록된 직위 개수 리턴
-------------------------------------------------*/
int Employee::p_count(string POS) {
	vector<E_Data>::iterator iter;
	int cnt=0;

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		if (iter->r_check() == true) {
			if (iter->p_check2(POS) == true) {
				cnt++;
			}
		}
	}
	return cnt;
}

/*-------------------------------------------------
 Employee::d_check1(string): 부서 존재 유무 확인
-------------------------------------------------*/
bool Employee::d_check1(string DEP) {
	vector<E_Data>::iterator iter;

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		if (iter->d_check2(DEP) == true) {
			return true;
		}
	}
	return false;
}

/*-------------------------------------------------
 Employee::d_count(string): 등록 부서 개수 리턴
-------------------------------------------------*/
int Employee::d_count(string DES) {
	vector<E_Data>::iterator iter;
	int cnt = 0;

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		if (iter->r_check() == true) {
			if (iter->d_check2(DES) == true) {
				cnt++;
			}
		}
	}
	return cnt;
}

/*-------------------------------------------------
 Employee::count(): 재직 사원 개수 리턴
-------------------------------------------------*/
int Employee::count() {
	vector<E_Data>::iterator iter;
	int cnt = 0;

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		if (iter->r_check() == true) {
			cnt++;
		}
	}
	return cnt;
}

/*-------------------------------------------------
 Employee::r_count(): 퇴직 사원 개수 리턴
-------------------------------------------------*/
int Employee::r_count() {
	vector<E_Data>::iterator iter;
	int cnt = 0;

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		if (iter->r_check() == false) {
			cnt++;
		}
	}
	return cnt;
}

/*-------------------------------------------------
 Employee::get_emp_data(string, string&, string&, string&):
 사원 데이터 가져오기
-------------------------------------------------*/
void Employee::get_emp_data(string e_num, string &dep, string &pos, string &name) {
	vector<E_Data>::iterator iter;

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		if (iter->get_p_company_number() == e_num) {
			dep = iter->get_p_company_department();
			pos = iter->get_p_company_position();
			name = iter->get_name();
			break;
		}
	}
}

/*-------------------------------------------------
 Employee::phone_dup_check(string): 핸드폰 번호
 중복 체크
-------------------------------------------------*/
bool Employee::phone_dup_check(string St) {
	vector<E_Data>::iterator iter;

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		if (iter->p_check(St) == true) return true;
	}
	return false;
}

/*-------------------------------------------------
 Employee::email_dup_check(string): 이메일 중복 체크
-------------------------------------------------*/
bool Employee::email_dup_check(string St) {
	vector<E_Data>::iterator iter;
	
	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		if (iter->e_check(St) == true) return true;
	}
	return false;
}

/*-------------------------------------------------
 Employee::home_dup_check(string): 주소 중복 체크
-------------------------------------------------*/
bool Employee::home_dup_check(string St) {
	vector<E_Data>::iterator iter;

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		if (iter->h_check(St) == true) return true;
	}
	return false;
}

/*-------------------------------------------------
 Employee::f_set_emp(): 사원 기초정보 파일 입력
-------------------------------------------------*/
void Employee::f_set_emp() {
	vector<E_Data>::iterator iter;
	string POS, j_date, DEP, data;
	ofstream ost;
	ost.open("사원기초정보\\사원정보.txt",ios::out);
	
	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		iter->f_set_emp_inf(POS, j_date, DEP);
		iter->f_set_emp_bas1(data);
		ost << iter->get_p_company_number() << "," << POS << "," << j_date << "," << DEP << "," << data;
	}

	ost.close();
}

/*-------------------------------------------------
 Employee::f_set_fmy1(): 사원 가족정보 파일 입력
-------------------------------------------------*/
void Employee ::f_set_fmy1() {
	vector<E_Data>::iterator iter;
	ofstream ost;
	ost.open("사원기초정보\\가족정보.txt",ios::out);
	ost.close();

	for (iter = emp.begin(); iter != emp.end(); ++iter) {
		iter->f_set_fmy2(iter->get_p_company_number());
	}
}

/*-------------------------------------------------
 Employee::f_get_emp(): 사원 정보 파일로 부터
 가져오기
-------------------------------------------------*/
void Employee::f_get_emp() {
	E_Data ED;
	Family FD;

	ifstream ist1, ist2;
	unsigned int i, cnt, s;
	string data1, data2, c_num, POS, j_date, DEP, D[22], F[8];

	ist1.open("사원기초정보\\사원정보.txt", ios::in);
	if (ist1.is_open()) {
		while (getline(ist1, data1)) {
			s = 0;
			cnt = 0;
			for (i = 0; i < data1.size(); i++) {
				if (data1[i] == ',') {
					D[cnt++] = data1.substr(s, i - s);
					s = i + 1;
				}
			}

			D[cnt] = data1.substr(s, i - s);
			ED.set_p_num2(D[0]);
			ED.set_p_position(D[1]);
			ED.set_p_join_date(D[2]);
			ED.set_p_department(D[3]);
			ED.set_p_name(D[4], D[5], D[6]);
			ED.set_p_address(D[7]);
			ED.set_p_married(D[8]);
			ED.set_p_E_mail(D[9]);
			ED.set_p_num(D[10], D[11]);
			ED.set_p_sex(D[12]);
			ED.set_p_height(D[13]);
			ED.set_p_weight(D[14]);
			ED.set_p_blood_type(D[15]);
			ED.set_p_vision(D[16], D[17]);
			ED.set_p_birth(D[18]);
			ED.set_p_resident_number(D[19]);
			ED.set_p_religion(D[20]);
			ED.set_p_retiree(D[21]);
			
			ist2.open("사원기초정보\\가족정보.txt", ios::in);
			if (ist2.is_open()) {
				while (getline(ist2, data2)) {
					s = 0;
					cnt = 0;
					for (i = 0; i < data2.size(); i++) {
						if (data2[i] == ',') {
							F[cnt++] = data2.substr(s, i - s);
							s = i + 1;
						}
					}
					
					F[cnt] = data2.substr(s, i - s);
					if (F[0] == D[0]) {
						FD.set_relation(F[1]);
						FD.set_name(F[2]);
						FD.set_birth(F[3]);
						FD.set_marrid(F[4]);
						FD.set_education(F[5]);
						FD.set_job(F[6]);
						FD.set_work_place(F[7]);

						ED.f_set_fmy2(FD);
					}
				}
				ist2.close();
			}
			
			emp.push_back(ED);
			ED.fmy_clear();
		}
	}
	ist1.close();
}