#include "Family.h"
Family::Family() {

}

Family::~Family() {

}

/*-------------------------------------------------
 Family::set_information(): ���� ���� �Է�
-------------------------------------------------*/
void Family::set_information() {
	string M;

	cout << "����:";
	cin >> relation;

	cout << "�̸�:";
	cin >> name;
	
	cout << "�������(ex:1999.01.01):";
	cin >> birth;

	while (1) {
		cout << "��ȥ����(��ȥ/��ȥ):";
		cin >> M;
		if (M == "��ȥ" || M == "��ȥ") {
			married = M;
			break;
		}
		cout << "�ٽ��Է����ּ���" << endl;
	}

	cout << "�з�:";
	cin >> education;

	cout << "����:";
	cin >> job;

	cout << "�ٹ�ó:";
	cin >> work_place;
}

/*-------------------------------------------------
 Family::show_information(): ���� ���� ���
-------------------------------------------------*/
void Family::show_information() {
	cout << relation << name << birth << married << education << job << work_place << endl;
}

string Family::get_relation() {
	return relation;
}

string Family::get_name() {
	return name;
}

string Family::get_birth() {
	return birth;
}

string Family::get_marrid() {
	return married;
}

string Family::get_education() {
	return education;
}

string Family::get_job() {
	return job;
}

string Family::get_work_place() {
	return work_place;
}

void Family::set_relation(string relation) {
	this->relation = relation;
}

void Family::set_name(string name) {
	this->name = name;
}

void Family::set_birth(string birth) {
	this->birth = birth;
}

void Family::set_marrid(string married) {
	this->married = married;
}

void Family::set_education(string education) {
	this->education = education;
}

void Family::set_job(string job) {
	this->job = job;
}

void Family::set_work_place(string work_place) {
	this->work_place = work_place;
}
