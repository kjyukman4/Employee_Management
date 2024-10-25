#ifndef __FAMILY__
#define __FAMILY__
#include <vector>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//가족 클래스
class Family {
private:
	string relation;	//관계
	string name;		//성명
	string birth;		//생년월일
	string married;		//결혼여부
	string education;	//학력
	string job;			//직업
	string work_place;	//근무처
public:
	Family();
	~Family();
	void set_information();
	void show_information();
	string get_relation();
	string get_name();
	string get_birth();
	string get_marrid();
	string get_education();
	string get_job();
	string get_work_place();
	void set_relation(string);
	void set_name(string);
	void set_birth(string);
	void set_marrid(string);
	void set_education(string);
	void set_job(string);
	void set_work_place(string);
};
#endif
