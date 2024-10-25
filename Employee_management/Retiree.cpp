#include "Retiree.h"
R_Data::R_Data(string r_c_number)
:r_company_number(r_c_number), r_date(""), r_reason(""), r_department(""), r_position("") {

}

R_Data::R_Data(){

}

R_Data::~R_Data() {

}

Retiree::Retiree(){

}

string R_Data::get_date() {
	return r_date;
}

string R_Data::get_number() {
	return r_company_number;
}

string R_Data::get_reason() {
	return r_reason;
}

string R_Data::get_department() {
	return r_department;
}

string R_Data::get_position() {
	return r_position;
}

/*-------------------------------------------------
 R_Data::set_data(Basic_info&): 퇴직사유 입력
-------------------------------------------------*/
void R_Data::set_data(Basic_info& bas) {
	time_t timer = time(NULL);
	tm* t = localtime(&timer);
	int n;
	r_date += to_string(t->tm_year) + "-";
	r_date += to_string(t->tm_mon) + "-";
	r_date += to_string(t->tm_mday) + "-";
	r_date += to_string(t->tm_hour) + "-";
	r_date += to_string(t->tm_min) + "-";
	r_date += to_string(t->tm_sec);

	bas.show_dep();
	r_department = bas.choice_dep();

	bas.show_pos();
	r_position = bas.choice_pos();
	
	while (1) {
		cout << "퇴직사유" << endl;
		cout << "1.정년" << endl;
		cout << "2.희망" << endl;
		cout << "3.구조조정" << endl;

		cout << "번호를 입력하세요: ";
		cin >> n;

		switch (n) {
			case 1:
				r_reason = "정년";
				break;
			case 2:
				r_reason = "희망";
				break;
			case 3:
				r_reason = "구조조정";
				break;
			default:
				cout << "다시입력해주세요" << endl;
		}
		break;
	}

}

/*-------------------------------------------------
 R_Data::get_data(): 퇴직사유 출력
-------------------------------------------------*/
void R_Data::get_data() {
	cout << "  퇴직일자: " << r_date << "  퇴직사유: " << r_reason << endl;
}

/*-------------------------------------------------
 R_Data::modify_data(): 퇴직사유 수정
-------------------------------------------------*/
void R_Data::modify_data() {
	int n;

	while (1) {
		cout << "퇴직사유" << endl;
		cout << "1.정년" << endl;
		cout << "2.희망" << endl;
		cout << "3.구조조정" << endl;

		cout << "번호를 입력하세요: ";
		cin >> n;

		while (1) {
			switch (n) {
				case 1:
					r_reason = "정년";
					break;
				case 2:
					r_reason = "희망";
					break;
				case 3:
					r_reason = "구조조정";
					break;
				default:
					cout << "다시입력해주세요" << endl;
			}
			break;
		}
	}
}

void R_Data::set_c_num(string num) {
	this->r_company_number = num;
}

void R_Data::set_date(string date) {
	this->r_date = date;
}

void R_Data::set_reason(string reason) {
	this->r_reason = reason;
}

void R_Data::set_department(string department) {
	this->r_department = department;
}

void R_Data::set_position(string position) {
	this->r_position = position;
}

Retiree::~Retiree() {

}

/*-------------------------------------------------
 R_Data::set_rtr(string): 퇴직자 추가
-------------------------------------------------*/
void Retiree::set_rtr(string Rtr_num) {
	R_Data R(Rtr_num);
	rtr.push_back(R);
}

/*-------------------------------------------------
 R_Data::rtr_check1(): 퇴직유무 확인1
-------------------------------------------------*/
bool Retiree::rtr_check1() {
	vector<R_Data>::iterator iter;

	for (iter = rtr.begin(); iter != rtr.end(); ++iter) {
		if (iter->get_date() != "") {
			return true;
		}
	}
	return false;
}

/*-------------------------------------------------
 R_Data::rtr_check2(): 퇴직유무 확인2
-------------------------------------------------*/
bool Retiree::rtr_check2() {
	vector<R_Data>::iterator iter;

	for (iter = rtr.begin(); iter != rtr.end(); ++iter) {
		if (iter->get_date() == "") {
			return true;
		}
	}
	return false;
}

/*-------------------------------------------------
 R_Data::set_rtr_data(Basic_info&): 퇴직자 일자 지정
-------------------------------------------------*/
void Retiree::set_rtr_data(Basic_info& bas) {
	vector<R_Data>::iterator iter;

	for (iter = rtr.begin(); iter != rtr.end(); ++iter) {
		if (iter->get_date() == "") {
			cout << "사원번호: " << iter->get_number() << endl;
			iter->set_data(bas);
		}
	}
}

/*-------------------------------------------------
 R_Data::show_rtr_data(): 퇴직자 정보 출력
-------------------------------------------------*/
void Retiree::show_rtr_data() {
	vector<R_Data>::iterator iter;

	for (iter = rtr.begin(); iter != rtr.end(); ++iter) {
		if (iter->get_date() != "") {
			cout << "사원번호: " << iter->get_number() << endl;
			iter->get_data();
		}
	}
}

/*-------------------------------------------------
 R_Data::modify_rtr_data(): 퇴직자 정보 수정
-------------------------------------------------*/
void Retiree::modify_rtr_data() {
	vector<R_Data>::iterator iter;
	int i=0, n;

	show_rtr_data();

	cout << "수정할 번호를 입력하세요: ";
	cin >> n;

	for (iter = rtr.begin(); iter != rtr.end(); ++iter) {
		if (iter->get_date() != "") {
			i++;
			if (i == n) {
				iter->modify_data();
				break;
			}
		}
	}
}

/*-------------------------------------------------
 R_Data::set_data_RET(Employee&): 사원명부 출력(퇴직자)
-------------------------------------------------*/
void Retiree::set_data_RET(Employee& emp_E) {
	vector<R_Data>::iterator iter1;
	vector<E_Data>::iterator iter2;
	ofstream ost;
	string data,dep,pos,name;

	ost.open("사원명부\\사원명부(퇴직자).txt", ios::app);
	for (iter1 = rtr.begin(); iter1 != rtr.end(); ++iter1) {
		emp_E.get_emp_data(iter1->get_number(),dep,pos,name);
		data = "| " + iter1->get_number() + " |   " + dep + " | " + pos + " | " + iter1->get_date();
		data += " | " + name + " |";
		ost << data << "\n";
	}
	ost.close();
}

/*-------------------------------------------------
 Employee::f_set_rtr(): 퇴직자 정보 파일에 입력
-------------------------------------------------*/
void Retiree::f_set_rtr() {
	vector<R_Data>::iterator iter;
	ofstream ost;
	ost.open("퇴직자정보\\퇴직자정보.txt", ios::out);

	for (iter =rtr.begin(); iter != rtr.end(); ++iter) {
		ost << iter->get_number() << "," << iter->get_date() << "," << iter->get_reason() << "," << iter->get_department() << "," << iter->get_position() << "\n";
	}
	ost.close();
}

/*-------------------------------------------------
 Employee::f_get_rtr(): 퇴직자 정보 파일로부터
 가져오기
-------------------------------------------------*/
void Retiree::f_get_rtr() {
	string data,R[5];
	ifstream ist;
	R_Data RD;
	unsigned int i,s, cnt;
	ist.open("퇴직자정보\\퇴직자정보.txt", ios::in);

	while (getline(ist,data)) {
		s = 0;
		cnt = 0;
		for (i = 0; i < data.size(); i++) {
			if (data[i] == ',') {
				R[cnt++] = data.substr(s, i - s);
				s = i + 1;
			}
		}

		R[cnt] = data.substr(s, i - s);
		RD.set_c_num(R[0]);
		RD.set_date(R[1]);
		RD.set_reason(R[2]);
		RD.set_department(R[3]);
		RD.set_position(R[4]);

		rtr.push_back(RD);
	}
	ist.close();
}