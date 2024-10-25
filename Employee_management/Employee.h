#ifndef __EMPLOYEE__
#define __EMPLOYEE__

#include "Basic_info.h"
#include "Family.h"

class Employee;

// ��ü���� ����ü
typedef struct physical_details {
	double height;			//Ű
	double weight;			//������
	string blood_type;		//������
	double vision[2];		//�÷�(��,��)
}p_d;

// ���νŻ����� Ŭ����
class P_info {
private:
	vector<Family> f_relation;		//��������<���� ���>
	p_d p_physical;					//��ü����<����ü ���>
	string p_name[3];				//����
	string p_address;				//�ּ�
	string p_married;				//��ȥ����
	string E_mail;					//���ڿ���
	string p_num[2];				//����ó
	string p_sex;				    //����
public:
	P_info();
	~P_info();
	void set_P_info(Employee &);
	string get_sex();
	string get_name();
	void F_regist2();
	void emp_show_data2();
	void family_show2();
	void family_modify2();
	void family_delete2();
	void set_p_name(string, string, string);
	void set_p_address(string);
	void set_p_married(string);
	void set_p_E_mail(string);
	void set_p_num(string, string);
	void set_p_sex(string);
	void set_p_height(string);
	void set_p_weight(string);
	void set_p_blood_type(string);
	void set_p_vision(string, string);
	void f_set_fmy2(Family);
	void fmy_clear();
	bool e_check(string );
	bool p_check(string );
	bool h_check(string);
	bool e_mail_phone_check(string, Employee &, int);
	void u_P_info(Employee &);
	//����½�Ʈ��/////////////////
	void f_set_emp_bas2(string &);
	void f_set_fmy2(string);
	///////////////////////////////
};

// ��� ������ Ŭ����
class E_Data :public P_info {
private:
	// �������
								// ��������
	string p_department;			//�μ�
	string p_religion;				//����
	string p_position;				//����
	string p_birth;				//�������
	string p_join_date;			//�Ի���
	string p_company_number;	//�����ȣ
	string p_resident_number;	//�ֹε�Ϲ�ȣ
	bool p_retiree;				//��������
public:
	E_Data();
	~E_Data();
	void E_regist(Basic_info &, Employee &);
	void set_p_company_number(string);
	void set_p_num2(string);
	void set_p_resident_number(string);
	void set_p_department(string );
	void set_p_religion(string);
	void set_p_position(string);
	void set_p_birth(string);
	void set_p_join_date(string);
	void set_p_retiree(string);
	string get_p_company_number();
	string get_p_company_department();
	string get_p_company_position();
	string get_p_company_j_date();
	string get_p_company_birth();
	void print_C_N();
	void change_retiree();
	void u_department(Basic_info &);
	void u_religion(Basic_info &);
	void u_position(Basic_info &);
	void emp_show_data();
	bool r_check();
	bool p_check2(string );
	bool d_check2(string );
	void E_update(Basic_info&, Employee&);
	//����½�Ʈ��///////////////
	void f_set_emp_inf(string&, string&, string&);
	void f_set_emp_bas1(string &);
	/////////////////////////////
};

// ��� ���� Ŭ����
class Employee{
private:
	vector<E_Data> emp;
public:
	Employee();
	~Employee();
	void set_emp(Basic_info &, Employee &);
	void all_show();
	bool compare(string Emp_num);
	void F_regist1(string );
	string R_regist();
	string E_update();
	void emp_update(string ,Basic_info &,Employee&);
	bool emp_empty();
	void E_S_num();
	void E_S_name();
	void E_S_dep();
	void E_S_pos();
	bool family_empty(string );
	void family_show(string );
	void family_modify(string );
	void family_delete(string);
	void set_data_ALL();
	void add();
	void set_data_POS(string );
	void set_data_DEP(string );
	bool p_check1(string );
	int p_count(string );
	bool d_check1(string );
	int d_count(string );
	int count();
	int r_count();
	void get_emp_data(string, string&, string&, string&);
	bool phone_dup_check(string );
	bool email_dup_check(string );
	bool home_dup_check(string);
	//����½�Ʈ��///////////////
	void f_set_emp();
	void f_set_fmy1();
	void f_get_emp();
	/////////////////////////////
};
#endif
