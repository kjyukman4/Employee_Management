#ifndef __BASICINFO__
#define __BASICINFO__

#include "Menu_vision.h"
#include <vector>

//�������� ������ Ŭ����
class B_I_Data {
private:
	string code; //������ �ڵ�
	string information; //�ڵ��� ����
public:
	B_I_Data();
	~B_I_Data();
	void set_code(string );
	void set_information(string );
	string get_code();
	string get_information();
	void update_information(string );
	void update_code(string );
};

// �������� ���� Ŭ����
class Basic_info{
private:
	vector<B_I_Data> department; //�μ�
	vector<B_I_Data> religion;   //����
	vector<B_I_Data> position;   //����
public:
	Basic_info();
	~Basic_info();
	void set_dep();
	void set_rel();
	void set_pos();
	string choice_dep();
	string choice_rel();
	string choice_pos();
	void show_dep();
	void show_rel();
	void show_pos();
	void update_dep();
	void update_rel();
	void update_pos();
	void delete_dep();
	void delete_rel();
	void delete_pos();
	void show_all();
	string D_trans_form(string );
	bool d_state();
	bool r_state();
	bool p_state();
	bool data_state();
	bool compare_code(string, int);
	bool compare_information(string, int);

	//����� ��Ʈ��/////////////////
	void f_set_dep();
	void f_set_rel();
	void f_set_pos();
	void f_get_dep();
	void f_get_rel();
	void f_get_pos();
	////////////////////////////////
};
#endif