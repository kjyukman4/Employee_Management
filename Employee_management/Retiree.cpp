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
 R_Data::set_data(Basic_info&): �������� �Է�
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
		cout << "��������" << endl;
		cout << "1.����" << endl;
		cout << "2.���" << endl;
		cout << "3.��������" << endl;

		cout << "��ȣ�� �Է��ϼ���: ";
		cin >> n;

		switch (n) {
			case 1:
				r_reason = "����";
				break;
			case 2:
				r_reason = "���";
				break;
			case 3:
				r_reason = "��������";
				break;
			default:
				cout << "�ٽ��Է����ּ���" << endl;
		}
		break;
	}

}

/*-------------------------------------------------
 R_Data::get_data(): �������� ���
-------------------------------------------------*/
void R_Data::get_data() {
	cout << "  ��������: " << r_date << "  ��������: " << r_reason << endl;
}

/*-------------------------------------------------
 R_Data::modify_data(): �������� ����
-------------------------------------------------*/
void R_Data::modify_data() {
	int n;

	while (1) {
		cout << "��������" << endl;
		cout << "1.����" << endl;
		cout << "2.���" << endl;
		cout << "3.��������" << endl;

		cout << "��ȣ�� �Է��ϼ���: ";
		cin >> n;

		while (1) {
			switch (n) {
				case 1:
					r_reason = "����";
					break;
				case 2:
					r_reason = "���";
					break;
				case 3:
					r_reason = "��������";
					break;
				default:
					cout << "�ٽ��Է����ּ���" << endl;
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
 R_Data::set_rtr(string): ������ �߰�
-------------------------------------------------*/
void Retiree::set_rtr(string Rtr_num) {
	R_Data R(Rtr_num);
	rtr.push_back(R);
}

/*-------------------------------------------------
 R_Data::rtr_check1(): �������� Ȯ��1
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
 R_Data::rtr_check2(): �������� Ȯ��2
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
 R_Data::set_rtr_data(Basic_info&): ������ ���� ����
-------------------------------------------------*/
void Retiree::set_rtr_data(Basic_info& bas) {
	vector<R_Data>::iterator iter;

	for (iter = rtr.begin(); iter != rtr.end(); ++iter) {
		if (iter->get_date() == "") {
			cout << "�����ȣ: " << iter->get_number() << endl;
			iter->set_data(bas);
		}
	}
}

/*-------------------------------------------------
 R_Data::show_rtr_data(): ������ ���� ���
-------------------------------------------------*/
void Retiree::show_rtr_data() {
	vector<R_Data>::iterator iter;

	for (iter = rtr.begin(); iter != rtr.end(); ++iter) {
		if (iter->get_date() != "") {
			cout << "�����ȣ: " << iter->get_number() << endl;
			iter->get_data();
		}
	}
}

/*-------------------------------------------------
 R_Data::modify_rtr_data(): ������ ���� ����
-------------------------------------------------*/
void Retiree::modify_rtr_data() {
	vector<R_Data>::iterator iter;
	int i=0, n;

	show_rtr_data();

	cout << "������ ��ȣ�� �Է��ϼ���: ";
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
 R_Data::set_data_RET(Employee&): ������ ���(������)
-------------------------------------------------*/
void Retiree::set_data_RET(Employee& emp_E) {
	vector<R_Data>::iterator iter1;
	vector<E_Data>::iterator iter2;
	ofstream ost;
	string data,dep,pos,name;

	ost.open("������\\������(������).txt", ios::app);
	for (iter1 = rtr.begin(); iter1 != rtr.end(); ++iter1) {
		emp_E.get_emp_data(iter1->get_number(),dep,pos,name);
		data = "| " + iter1->get_number() + " |   " + dep + " | " + pos + " | " + iter1->get_date();
		data += " | " + name + " |";
		ost << data << "\n";
	}
	ost.close();
}

/*-------------------------------------------------
 Employee::f_set_rtr(): ������ ���� ���Ͽ� �Է�
-------------------------------------------------*/
void Retiree::f_set_rtr() {
	vector<R_Data>::iterator iter;
	ofstream ost;
	ost.open("����������\\����������.txt", ios::out);

	for (iter =rtr.begin(); iter != rtr.end(); ++iter) {
		ost << iter->get_number() << "," << iter->get_date() << "," << iter->get_reason() << "," << iter->get_department() << "," << iter->get_position() << "\n";
	}
	ost.close();
}

/*-------------------------------------------------
 Employee::f_get_rtr(): ������ ���� ���Ϸκ���
 ��������
-------------------------------------------------*/
void Retiree::f_get_rtr() {
	string data,R[5];
	ifstream ist;
	R_Data RD;
	unsigned int i,s, cnt;
	ist.open("����������\\����������.txt", ios::in);

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