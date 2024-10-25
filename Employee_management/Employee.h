#ifndef __EMPLOYEE__
#define __EMPLOYEE__

#include "Basic_info.h"
#include "Family.h"

class Employee;

// 신체사항 구조체
typedef struct physical_details {
	double height;			//키
	double weight;			//몸무게
	string blood_type;		//혈액형
	double vision[2];		//시력(좌,우)
}p_d;

// 개인신상정보 클래스
class P_info {
private:
	vector<Family> f_relation;		//가족관계<벡터 사용>
	p_d p_physical;					//신체사항<구조체 사용>
	string p_name[3];				//성명
	string p_address;				//주소
	string p_married;				//결혼관계
	string E_mail;					//전자우편
	string p_num[2];				//연락처
	string p_sex;				    //성별
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
	//입출력스트림/////////////////
	void f_set_emp_bas2(string &);
	void f_set_fmy2(string);
	///////////////////////////////
};

// 사원 데이터 클래스
class E_Data :public P_info {
private:
	// 사원정보
								// 기초정보
	string p_department;			//부서
	string p_religion;				//종교
	string p_position;				//직위
	string p_birth;				//생년월일
	string p_join_date;			//입사일
	string p_company_number;	//사원번호
	string p_resident_number;	//주민등록번호
	bool p_retiree;				//퇴직여부
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
	//입출력스트림///////////////
	void f_set_emp_inf(string&, string&, string&);
	void f_set_emp_bas1(string &);
	/////////////////////////////
};

// 사원 예비 클래스
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
	//입출력스트림///////////////
	void f_set_emp();
	void f_set_fmy1();
	void f_get_emp();
	/////////////////////////////
};
#endif
