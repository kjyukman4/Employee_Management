#include "Family.h"
Family::Family() {

}

Family::~Family() {

}

/*-------------------------------------------------
 Family::set_information(): 가족 정보 입력
-------------------------------------------------*/
void Family::set_information() {
	string M;

	cout << "관계:";
	cin >> relation;

	cout << "이름:";
	cin >> name;
	
	cout << "생년월일(ex:1999.01.01):";
	cin >> birth;

	while (1) {
		cout << "결혼여부(미혼/기혼):";
		cin >> M;
		if (M == "미혼" || M == "기혼") {
			married = M;
			break;
		}
		cout << "다시입력해주세요" << endl;
	}

	cout << "학력:";
	cin >> education;

	cout << "직업:";
	cin >> job;

	cout << "근무처:";
	cin >> work_place;
}

/*-------------------------------------------------
 Family::show_information(): 가족 정보 출력
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
