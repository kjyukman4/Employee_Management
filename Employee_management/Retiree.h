#ifndef __RETIREE__
#define __RETIREE__
#include "Employee.h"

//������ Ŭ����
class R_Data {
private:
	string r_company_number;	//������ ��ȣ
	string r_date;				//���� ����
	string r_reason;			//��������(����, ���, �������� <��1>)
	string r_department;		//�����μ�
	string r_position;			//������å
public:
	R_Data(string );
	R_Data();
	~R_Data();
	string get_date();
	string get_number();
	string get_reason();
	string get_department();
	string get_position();
	void set_data(Basic_info&);
	void get_data();
	void modify_data();
	void set_c_num(string);
	void set_date(string);
	void set_reason(string);
	void set_department(string);
	void set_position(string);
};

class Retiree {
private:
	vector<R_Data> rtr;
public:
	Retiree();
	~Retiree();
	void set_rtr(string );
	bool rtr_check1();
	bool rtr_check2();
	void set_rtr_data(Basic_info&);
	void show_rtr_data();
	void modify_rtr_data();
	void set_data_RET(Employee&);
	void f_set_rtr();
	void f_get_rtr();
};

#endif 