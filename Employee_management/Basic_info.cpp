#include "Basic_info.h"
B_I_Data::B_I_Data()
:code(""),information(""){}

B_I_Data::~B_I_Data() {}

void B_I_Data::set_code(string code) {
	this->code = code;
}

void B_I_Data::set_information(string information) {
	this->information = information;
}

string B_I_Data::get_code() {
	return code;
}

string B_I_Data::get_information() {
	return information;
}

void B_I_Data::update_information(string information) {
	this -> information = information;
}

void B_I_Data::update_code(string code) {
	this -> code = code;
}

Basic_info::Basic_info() {}

Basic_info::~Basic_info() {}

/*-------------------------------------------------
 Basic_info::set_dep(): �μ� ���
-------------------------------------------------*/
void Basic_info::set_dep() {
	B_I_Data D;
	string code,information;

	while (1) {
		cout << "����� �μ����� �Է��ϼ���:";
		cin >> information;
		if (compare_information(information, 0) == false) {
			D.set_information(information);
			break;
		}
		else {
			cout << "�ߺ��� �μ��� �����մϴ�." << endl;
		}
	}
	while (1) {
		cout << "����� �ڵ��� �Է��ϼ���(ex:GR):";
		cin >> code;
		if (code.size() == 2) {
			if (isalpha(code[0]) == 1 && isalpha(code[1]) == 1) {
				if (compare_code(code, 0) == false) {
					D.set_code(code);
					department.push_back(D);
					f_set_dep();
					break;
				}
				else {
					cout << "�ߺ��� �ڵ尡 �����մϴ�." << endl;
				}
			}
			else {
				cout << "�ڵ�� ���� �빮���Դϴ�." << endl;
			}
		}
		else {
			cout << "�ڵ�� 2�����Դϴ�." << endl;
		}
	}
}

/*-------------------------------------------------
 Basic_info::set_rel(): ���� ���
-------------------------------------------------*/
void Basic_info::set_rel() {
	B_I_Data D;
	string code, information;

	while (1) {
		cout << "����� ������ �Է��ϼ���:";
		cin >> information;
		if (compare_information(information, 1) == false) {
			D.set_information(information);
			break;
		}
		else {
			cout << "�ߺ��� ������ �����մϴ�." << endl;
		}
	}
	while (1) {
		cout << "����� �ڵ��� �Է��ϼ���(ex:01):";
		cin >> code;
		if (code.size() == 2) {
			if ((code[0] >= '0' && code[0] <= '9') && (code[1] >= '0' && code[1] <= '9')) {
				if (compare_code(code, 1) == false) {
					D.set_code(code);
					religion.push_back(D);
					f_set_rel();
					break;
				}
				else {
					cout << "�ߺ��� �ڵ尡 �����մϴ�." << endl;
				}
			}
			else {
				cout << "�ڵ�� �����Դϴ�." << endl;
			}
		}
		else {
			cout << "�ڵ�� 2�����Դϴ�." << endl;
		}
	}
}

/*-------------------------------------------------
 Basic_info::set_pos(): ���� ���
-------------------------------------------------*/
void Basic_info::set_pos() {
	B_I_Data D;
	string code, information;

	while (1) {
		cout << "����� ������ �Է��ϼ���:";
		cin >> information;
		if (compare_information(information, 2) == false) {
			D.set_information(information);
			break;
		}
		else {
			cout << "�ߺ��� ������ �����մϴ�." << endl;
		}
	}
	while (1) {
		cout << "����� �ڵ��� �Է��ϼ���(ex:GR):";
		cin >> code;
		if (code.size() == 2) {
			if (isalpha(code[0]) == 1 && isalpha(code[1]) == 1) {
				if (compare_code(code, 2) == false) {
					D.set_code(code);
					position.push_back(D);
					f_set_pos();
					break;
				}
				else {
					cout << "�ߺ��� �ڵ尡 �����մϴ�." << endl;
				}
			}
			else {
				cout << "�ڵ�� ���� �빮���Դϴ�." << endl;
			}
		}
		else {
			cout << "�ڵ�� 2�����Դϴ�." << endl;
		}
	}
}

/*-------------------------------------------------
 Basic_info::choice_dep(): �μ� ����
-------------------------------------------------*/
string Basic_info::choice_dep() {
	vector<B_I_Data>::iterator iter;
	
	int i, n;

	while (1) {
		cout << "��ȣ�� �Է��ϼ���:";
		cin >> n;
		i = 0;

		for (iter = department.begin(); iter != department.end(); ++iter) {
			i++;
			if (i == n) {
				return iter->get_information();
			}
		}
		cout << "�߸��Է��Ͽ����ϴ�." << endl;
	}
}

/*-------------------------------------------------
 Basic_info::choice_rel(): ���� ����
-------------------------------------------------*/
string Basic_info::choice_rel() {
	vector<B_I_Data>::iterator iter;

	int i, n;

	while (1) {
		cout << "��ȣ�� �Է��ϼ���:";
		cin >> n;
		i = 0;

		for (iter = religion.begin(); iter != religion.end(); ++iter) {
			i++;
			if (i == n) {
				return iter->get_information();
			}
		}
		cout << "�߸��Է��Ͽ����ϴ�." << endl;
	}
}

/*-------------------------------------------------
 Basic_info::choice_pos(): ���� ����
-------------------------------------------------*/
string Basic_info::choice_pos() {
	vector<B_I_Data>::iterator iter;
	
	int i, n;

	while (1) {
		cout << "��ȣ�� �Է��ϼ���:";
		cin >> n;
		i = 0;

		for (iter = position.begin(); iter != position.end(); ++iter) {
			i++;
			if (i == n) {
				return iter->get_information();
			}
		}
		cout << "�߸��Է��Ͽ����ϴ�." << endl;
	}
}

/*-------------------------------------------------
 Basic_info::show_dep(): ��ϵ� �μ� ���
-------------------------------------------------*/
void Basic_info::show_dep() {
	vector<B_I_Data>::iterator iter;

	string MIX;

	cout << setw(10) << "�μ�" << endl;

	for (iter = department.begin(); iter != department.end(); ++iter) {
		MIX = "";
		MIX = iter->get_code() + ":" + iter->get_information();
		cout << setw(10) << MIX << endl;
	}
}

/*-------------------------------------------------
 Basic_info::show_rel(): ��ϵ� ���� ���
-------------------------------------------------*/
void Basic_info::show_rel() {
	vector<B_I_Data>::iterator iter;

	string MIX;

	cout << setw(10) << "����" << endl;

	for (iter = religion.begin(); iter != religion.end(); ++iter) {
		MIX = "";
		MIX = iter->get_code() + ":" + iter->get_information();
		cout << setw(10) << MIX << endl;
	}
}

/*-------------------------------------------------
 Basic_info::show_pos(): ��ϵ� ���� ���
-------------------------------------------------*/
void Basic_info::show_pos() {
	vector<B_I_Data>::iterator iter;

	string MIX;

	cout << setw(10) << "����" << endl;

	for (iter = position.begin(); iter != position.end(); ++iter) {
		MIX = "";
		MIX = iter->get_code() + ":" + iter->get_information();
		cout << setw(10) << MIX << endl;
	}
}

/*-------------------------------------------------
 Basic_info::update_dep(): �μ� ����
-------------------------------------------------*/
void Basic_info::update_dep() {
	vector<B_I_Data>::iterator iter;
	unsigned int i, n;
	string information, code;

	while (1) {
		cout << "������ �μ��� �Է��ϼ���:";
		cin >> information;
		if (compare_information(information, 0) == false) {
			while (1) {
				cout << "������ �ڵ��� �Է��ϼ���(ex:GR) :";
				cin >> code;
				if (code.size() != 2) {
					if (isalpha(code[0]) == 1 && isalpha(code[1]) == 1) {
						if (compare_code(code, 0) == false) {
							while (1) {
								cout << "��ȣ�� �Է��ϼ���:";
								cin >> n;
								i = 0;
								if (0 < n && n <= department.size()) {
									for (iter = department.begin(); iter != department.end(); ++iter) {
										i++;
										if (i == n) {
											iter->update_information(information);
											iter->update_code(code);
											f_set_dep();
											break;
										}
										break;
									}
								}
								cout << "�߸��Է��Ͽ����ϴ�." << endl;
							}
						}
					}
					else {
						cout << "�ڵ�� ���� �빮���Դϴ�." << endl;
					}
				}
				else {
					cout << "�ڵ�� 2�����Դϴ�." << endl;
				}
			}
		}
	}
}

/*-------------------------------------------------
 Basic_info::update_rel(): ���� ����
-------------------------------------------------*/
void Basic_info::update_rel() {
	vector<B_I_Data>::iterator iter;
	unsigned int i, n;
	string information, code;


	while (1) {
		cout << "������ ������ �Է��ϼ���:";
		cin >> information;
		if (compare_information(information, 1) == false) {
			while (1) {
				cout << "������ �ڵ��� �Է��ϼ���(ex:GR) :";
				cin >> code;
				if (code.size() != 2) {
					if ((code[0] >= '0' && code[0] <= '9') && (code[1] >= '0' && code[1] <= '9')) {
						if (compare_code(code, 1) == false) {
							while (1) {
								cout << "��ȣ�� �Է��ϼ���:";
								cin >> n;
								i = 0;
								if (0 < n && n <= religion.size()) {
									for (iter = religion.begin(); iter != religion.end(); ++iter) {
										i++;
										if (i == n) {
											iter->update_information(information);
											iter->update_code(code);
											f_set_rel();
											break;
										}
									}
									break;
								}
								cout << "�߸��Է��Ͽ����ϴ�." << endl;
							}
						}
					}
					else {
						cout << "�ڵ�� ���� �빮���Դϴ�." << endl;
					}
				}
				else {
					cout << "�ڵ�� 2�����Դϴ�." << endl;
				}
			}
		}
	}
}

/*-------------------------------------------------
 Basic_info::update_pos(): ���� ����
-------------------------------------------------*/
void Basic_info::update_pos() {
	vector<B_I_Data>::iterator iter;
	unsigned int i, n;
	string information, code;

	while (1) {
		cout << "������ ������ �Է��ϼ���:";
		cin >> information;
		if (compare_information(information, 2) == false) {
			while (1) {
				cout << "������ �ڵ��� �Է��ϼ���(ex:GR) :";
				cin >> code;
				if (code.size() != 2) {
					if (isalpha(code[0]) == 1 && isalpha(code[1]) == 1) {
						if (compare_code(code, 2) == false) {
							while (1) {
								cout << "��ȣ�� �Է��ϼ���:";
								cin >> n;
								i = 0;
								if (0 < n && n <= position.size()) {
									for (iter = position.begin(); iter != position.end(); ++iter) {
										i++;
										if (i == n) {
											iter->update_information(information);
											iter->update_code(code);
											f_set_pos();
											break;
										}
									}
									break;
								}
								cout << "�߸��Է��Ͽ����ϴ�." << endl;
							}
						}
					}
					else {
						cout << "�ڵ�� ���� �빮���Դϴ�." << endl;
					}
				}
				else {
					cout << "�ڵ�� 2�����Դϴ�." << endl;
				}
			}
		}
	}
}

/*-------------------------------------------------
 Basic_info::delete_dep(): �μ� ����
-------------------------------------------------*/
void Basic_info::delete_dep() {
	vector<B_I_Data>::iterator iter;
	unsigned int n,i;

	while (1) {
		cout << "��ȣ�� �Է��ϼ���:";
		cin >> n;
		i = 0;
		if (0 < n && n <= department.size()) {
			for (iter = department.begin(); iter != department.end(); ++iter) {
				i++;
				if (i == n) {
					department.erase(department.begin() + i-1);
					f_set_dep();
					break;
				}
			}
			break;
		}
		cout << "�߸��Է��Ͽ����ϴ�." << endl;
	}
}

/*-------------------------------------------------
 Basic_info::delete_rel(): ���� ����
-------------------------------------------------*/
void Basic_info::delete_rel() {
	vector<B_I_Data>::iterator iter;
	unsigned int n,i;

	while (1) {
		cout << "��ȣ�� �Է��ϼ���:";
		cin >> n;
		i = 0;
		if (0 < n && n <= religion.size()) {
			for (iter = religion.begin(); iter != religion.end(); ++iter) {
				i++;
				if (i == n) {
					religion.erase(religion.begin() + i - 1);
					f_set_rel();
					break;
				}
			}
			break;
		}
		cout << "�߸��Է��Ͽ����ϴ�." << endl;
	}
}

/*-------------------------------------------------
 Basic_info::delete_pos(): ���� ����
-------------------------------------------------*/
void Basic_info::delete_pos() {
	vector<B_I_Data>::iterator iter;
	unsigned int n,i;

	while (1) {
		cout << "��ȣ�� �Է��ϼ���:";
		cin >> n;
		i = 0;
		if (0 < n && n <= position.size()) {
			for (iter = position.begin(); iter != position.end(); ++iter) {
				i++;
				if (i == n) {
					position.erase(position.begin() + i - 1);
					f_set_pos();
					break;
				}
			}
			break;
		}
		cout << "�߸��Է��Ͽ����ϴ�." << endl;
	}
}

/*-------------------------------------------------
 Basic_info::show_all(): �μ�, ����, ���� ���
-------------------------------------------------*/
void Basic_info::show_all() {
	vector<B_I_Data>::iterator iter1;
	vector<B_I_Data>::iterator iter2;
	vector<B_I_Data>::iterator iter3;
	
	unsigned int MAX = department.size();
	string MIX;

	iter1 = department.begin();
	iter2 = religion.begin();
	iter3 = position.begin();

	if (MAX < religion.size()) {
		MAX = religion.size();
		if (MAX < position.size()) {
			MAX = position.size();
		}
	}

	cout << setw(10) << "�μ�" << setw(10) << "����" << setw(10) << "����" << endl;

	for (unsigned int i = 0; i < MAX; i++) {
		if (iter1 != department.end()) {
			MIX = "";
			MIX = iter1->get_code() + ":" + iter1->get_information();
			cout << setw(10) << MIX;
			iter1++;
		}
		else {
			cout << setw(10) <<"";
		}
		if (iter2 != religion.end()) {
			MIX = "";
			MIX = iter2->get_code() + ":" + iter2->get_information();
			cout << setw(10) << MIX;
			iter2++;
		}
		else {
			cout << setw(10) << "";
		}
		if (iter3 != position.end()) {
			MIX = "";
			MIX = iter3->get_code() + ":" + iter3->get_information();
			cout << setw(10) << MIX;
			iter3++;
		}
		else {
			cout << setw(10) << "";
		}
		cout << endl;
	}
}

/*-------------------------------------------------
 Basic_info::D_trans_form(string): �μ�����
 �μ��ڵ�� ��ȯ
-------------------------------------------------*/
string Basic_info::D_trans_form(string p_department) {
	vector<B_I_Data>::iterator iter;

	for (iter = department.begin(); iter != department.end(); ++iter) {
		if (p_department == iter->get_information()) {
			return iter->get_code();
		}
	}
	return NULL;
}

/*-------------------------------------------------
 Basic_info::d_state(): �μ����� ����Ȯ��
-------------------------------------------------*/
bool Basic_info::d_state() {
	return department.size() != 0 ? true : false;
}

/*-------------------------------------------------
 Basic_info::r_state(): �������� ����Ȯ��
-------------------------------------------------*/
bool Basic_info::r_state() {
	return religion.size() != 0 ? true : false;
}

/*-------------------------------------------------
 Basic_info::p_state(): �������� ����Ȯ��
-------------------------------------------------*/
bool Basic_info::p_state() {
	return position.size() != 0 ? true : false;
}

/*-------------------------------------------------
 Basic_info::data_state(): �������� ����Ȯ��
-------------------------------------------------*/
bool Basic_info::data_state() {
	return (department.size() != 0 && religion.size() != 0 && position.size() != 0) ? true : false;
}

/*-------------------------------------------------
 Basic_info::compare_code(): ����ڵ� �ߺ�Ȯ��
-------------------------------------------------*/
bool Basic_info::compare_code(string code, int state) {
	vector<B_I_Data>::iterator iter;

	if (state == 0) {
		for (iter = department.begin(); iter != department.end(); ++iter) {
			if (code == iter->get_code()) return true;
		}
	}
	else if (state == 1) {
		for (iter = religion.begin(); iter != religion.end(); ++iter) {
			if (code == iter->get_code()) return true;
		}
	}
	else {
		for (iter = position.begin(); iter != position.end(); ++iter) {
			if (code == iter->get_code()) return true;
		}
	}
	return false;
}

/*-------------------------------------------------
 Basic_info::compare_information(): ������� �ߺ�Ȯ��
-------------------------------------------------*/
bool Basic_info::compare_information(string information, int state) {
	vector<B_I_Data>::iterator iter;

	if (state == 0) {
		for (iter = department.begin(); iter != department.end(); ++iter) {
			if (information == iter->get_information()) return true;
		}
	}
	else if (state == 1) {
		for (iter = religion.begin(); iter != religion.end(); ++iter) {
			if (information == iter->get_information()) return true;
		}
	}
	else {
		for (iter = position.begin(); iter != position.end(); ++iter) {
			if (information == iter->get_information()) return true;
		}
	}
	return false;
}

void Basic_info::f_set_dep() {
	vector<B_I_Data>::iterator iter;
	ofstream ost;
	ost.open("��������\\�μ�.txt",ios::out);

	for (iter = department.begin(); iter != department.end(); ++iter) {
		ost << iter->get_code() << "," << iter->get_information() << "\n";
	}

	ost.close();
}

void Basic_info::f_set_rel() {
	vector<B_I_Data>::iterator iter;
	ofstream ost;
	ost.open("��������\\����.txt", ios::out);

	for (iter = religion.begin(); iter != religion.end(); ++iter) {
		ost << iter->get_code() << "," << iter->get_information() << "\n";
	}

	ost.close();
}

void Basic_info::f_set_pos() {
	vector<B_I_Data>::iterator iter;
	ofstream ost;
	ost.open("��������\\����.txt", ios::out);

	for (iter = position.begin(); iter != position.end(); ++iter) {
		ost << iter->get_code() << "," << iter->get_information() << "\n";
	}

	ost.close();
}

void Basic_info::f_get_dep() {
	B_I_Data BD;
	ifstream ist;
	unsigned int i,s=0;
	string data,code,information;
	
	ist.open("��������\\�μ�.txt", ios::in);
	if (ist.is_open()) {
		while (getline(ist, data)) {
			for (i = 0; i < data.size(); i++) if (data[i] == ',') break;
			BD.set_code(data.substr(s, i));
			BD.set_information(data.substr(i + 1, data.size() + 1));
			department.push_back(BD);
		}
	}

	ist.close();
}

void Basic_info::f_get_rel() {
	B_I_Data BD;
	ifstream ist;
	int i, s = 0;
	string data, code, information;

	ist.open("��������\\����.txt", ios::in);
	
	if (ist.is_open()) {
		while (getline(ist, data)) {
			for (i = 0; i < data.size(); i++) if (data[i] == ',') break;
			BD.set_code(data.substr(s, i));
			BD.set_information(data.substr(i + 1, data.size() + 1));
			religion.push_back(BD);
		}
	}

	ist.close();
}

void Basic_info::f_get_pos() {
	B_I_Data BD;
	ifstream ist;
	int i, s = 0;
	string data, code, information;

	ist.open("��������\\����.txt", ios::in);
	if (ist.is_open()) {
		while (getline(ist, data)) {
			for (i = 0; i < data.size(); i++) if (data[i] == ',') break;
			BD.set_code(data.substr(s, i));
			BD.set_information(data.substr(i + 1, data.size() + 1));
			position.push_back(BD);
		}
	}

	ist.close();
}