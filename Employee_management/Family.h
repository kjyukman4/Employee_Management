#ifndef __FAMILY__
#define __FAMILY__
#include <vector>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//���� Ŭ����
class Family {
private:
	string relation;	//����
	string name;		//����
	string birth;		//�������
	string married;		//��ȥ����
	string education;	//�з�
	string job;			//����
	string work_place;	//�ٹ�ó
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
