#include "Utility.h"

/*-------------------------------------------------
 E_menu(): ��� �޴�
-------------------------------------------------*/
int E_menu() {
	int num;

	cout << "�������" << endl << endl;
	cout << "1.������" << endl;
	cout << "2.�������" << endl;
	cout << "3.�������" << endl;
	cout << "4.����˻�" << endl;
	cout << "5.�ڷΰ���" << endl;
	cin >> num;
	fflush(stdin);
	return num;
}

/*-------------------------------------------------
 E_main(Employee&, Basic_info&, Retiree&): ��� ����
-------------------------------------------------*/
void E_main(Employee& emp_E, Basic_info& bas, Retiree& rtr_R) {
	system("cls");
	int num;
	string Rtr_num;

	while ((num = E_menu()) != E::Exit) {
		fflush(stdin);
		/*���� �ѱ��̸� �Է��Ҷ� ����*/
		switch (num) {
			case E::Reg: //������
				if (bas.data_state() == true) {
					emp_E.set_emp(bas,emp_E);
				}
				else {
					cout << "���ʵ����Ͱ� �����ϴ�." << endl;
				}
				break;
			case E::Mod: //�������
				if ((Rtr_num=emp_E.E_update()) != "") {
					emp_E.emp_update(Rtr_num,bas,emp_E);
				}
				break;
			case E::Del: //�������
				if ((Rtr_num=emp_E.R_regist()) != "") {
					rtr_R.set_rtr(Rtr_num);
				}
				break;
			case E::Ser: //����˻�
				if (emp_E.emp_empty() == false) {
					S_main(emp_E);
				}
				else {
					cout << "��ϵ� ����� �����ϴ�." << endl;
				}
				break;
			default:	 //�ٽ��Է�
				system("cls");
				cout << "�ٽ� �Է����ּ���" << endl;
		}
	}
	Save_Data(emp_E, rtr_R);
}

/*-------------------------------------------------
 B_menu(): �������� �޴�
-------------------------------------------------*/
int B_menu() {
	int num;

	cout << "��������" << endl << endl;
	cout << "1.�μ����" << endl;
	cout << "2.�������" << endl;
	cout << "3.�������" << endl;
	cout << "4.�ڷΰ���" << endl;
	cin >> num;
	return num;
}

/*-------------------------------------------------
 B_main(Basic_info& ): �������� ����
-------------------------------------------------*/
void B_main(Basic_info& bas) {
	system("cls");

	int num;

	while ((num = B_menu()) != B::Exit) {
		switch (num) {
			case B::Dep: //�μ����
				bas.set_dep();
				break;

			case B::Rel: //�������
				bas.set_rel();
				break;

			case B::Pos: //�������
				bas.set_pos();
				break;

			default:	 //�ٽ��Է�
				bas.show_all();
				/*system("cls");
				cout << "�ٽ� �Է����ּ���" << endl;*/
		}

	}
}

/*-------------------------------------------------
 B_D_menu(): �μ���� �޴�
-------------------------------------------------*/
int B_D_menu() {
	int num;

	cout << "�μ����" << endl << endl;
	cout << "1.�μ��˻�" << endl;
	cout << "2.�μ��Է�" << endl;
	cout << "3.�μ�����" << endl;
	cout << "4.�μ�����" << endl;
	cout << "5.�ڷΰ���" << endl;
	cin >> num;
	return num;
}

/*-------------------------------------------------
 B_R_menu(): ������� �޴�
-------------------------------------------------*/
int B_R_menu() {
	int num;

	cout << "�������" << endl << endl;
	cout << "1.�����˻�" << endl;
	cout << "2.�����Է�" << endl;
	cout << "3.��������" << endl;
	cout << "4.��������" << endl;
	cout << "5.�ڷΰ���" << endl;
	cin >> num;
	return num;
}

/*-------------------------------------------------
 B_P_menu(): ������� �޴�
-------------------------------------------------*/
int B_P_menu() {
	int num;

	cout << "�������" << endl << endl;
	cout << "1.�����˻�" << endl;
	cout << "2.�����Է�" << endl;
	cout << "3.��������" << endl;
	cout << "4.��������" << endl;
	cout << "5.�ڷΰ���" << endl;
	cin >> num;
	return num;
}

/*-------------------------------------------------
 B_D_main(Basic_info& ): �μ���� ����
-------------------------------------------------*/
void B_D_main(Basic_info& bas) {
	system("cls");

	int num;

	while ((num = B_D_menu()) != B_sub::Exit) {
		switch (num) {
			case B_sub::Ser: //�μ���ȸ
				if (bas.d_state() == true) {
					bas.show_dep();
				}
				else {
					cout << "��ȸ�� �μ��� �����ϴ�." << endl;
				}
				break;

			case B_sub::Ins: //�μ��Է�
				bas.set_dep();
				break;

			case B_sub::Mod: //�μ�����
				if (bas.d_state() == true) {
					bas.show_dep();
					bas.update_dep();
				}
				else {
					cout << "������ �μ��� �����ϴ�." << endl;
				}
				break;

			case B_sub::Del: //�μ�����
				if (bas.d_state() == true) {
					bas.show_dep();
				}
				else {
					cout << "������ �μ��� �����ϴ�." << endl;
				}
				break;

			default:	 //�ٽ��Է�
				system("cls");
				cout << "�ٽ� �Է����ּ���" << endl;
		}

	}
}

/*-------------------------------------------------
 B_R_main(Basic_info& ): ������� ����
-------------------------------------------------*/
void B_R_main(Basic_info& bas) {
	system("cls");

	int num;

	while ((num = B_R_menu()) != B_sub::Exit) {
		switch (num) {
			case B_sub::Ser: //������ȸ
				if (bas.r_state() == true) {
					bas.show_rel();
				}
				else {
					cout << "��ȸ�� �μ��� �����ϴ�." << endl;
				}

				break;

			case B_sub::Ins: //�����Է�
				bas.set_rel();
				break;

			case B_sub::Mod: //��������
				if (bas.r_state() == true) {
					bas.show_rel();
					bas.update_rel();
				}
				else {
					cout << "������ ������ �����ϴ�." << endl;
				}
				break;

			case B_sub::Del: //��������
				if (bas.r_state() == true) {
					bas.show_rel();
					
				}
				else {
					cout << "������ ������ �����ϴ�." << endl;
				}
				break;

			default:	 //�ٽ��Է�
				system("cls");
				cout << "�ٽ� �Է����ּ���" << endl;
		}

	}
}

/*-------------------------------------------------
 B_P_main(Basic_info& ): ������� ����
-------------------------------------------------*/
void B_P_main(Basic_info& bas) {
	system("cls");

	int num;

	while ((num = B_P_menu()) != B_sub::Exit) {
		switch (num) {
			case B_sub::Ser: //������ȸ
				if (bas.p_state() == true) {
					bas.show_pos();
				}
				else {
					cout << "��ȸ�� ������ �����ϴ�." << endl;
				}
				break;

			case B_sub::Ins: //�����Է�
				bas.set_pos();
				break;

			case B_sub::Mod: //��������
				if (bas.p_state() == true) {
					bas.show_pos();
					bas.update_pos();
				}
				else {
					cout << "������ �μ��� �����ϴ�." << endl;
				}
				break;

			case B_sub::Del: //��������
				if (bas.p_state() == true) {
					bas.show_pos();
				}
				else {
					cout << "������ �μ��� �����ϴ�." << endl;
				}
				break;

			default:	 //�ٽ��Է�
				system("cls");
				cout << "�ٽ� �Է����ּ���" << endl;
		}

	}
}

/*-------------------------------------------------
 F_menu(): ������� �޴�
-------------------------------------------------*/
int F_menu() {
	int num;

	cout << "�������׵��" << endl << endl;
	cout << "1.���������Է�" << endl;
	cout << "2.����������ȸ" << endl;
	cout << "3.�������׼���" << endl;
	cout << "4.�������׻���" << endl;
	cout << "5.�ڷΰ���" << endl;
	cin >> num;

	return num;
}

/*-------------------------------------------------
 F_main(Employee&, Retiree&): ������� ����
-------------------------------------------------*/
void F_main(Employee& emp_E, Retiree& rtr_R) {
	int num;
	string Emp_num;

	cout << "�����ȣ:";
	cin >> Emp_num;
	system("cls");

	if (emp_E.compare(Emp_num) == true) {
		while ((num = F_menu()) != F::Exit) {
			switch (num) {
				case F::Reg:	//���������Է�
					emp_E.F_regist1(Emp_num);
					break;
				case F::Ser:	//����������ȸ
					if (emp_E.family_empty(Emp_num) == true) {
						emp_E.family_show(Emp_num);
					}
					else {
						cout << "��ϵ� ���������� �����ϴ�." << endl;
					}
					break;
				case F::Mod:	//�������׼���
					if (emp_E.family_empty(Emp_num) == true) {
						emp_E.family_modify(Emp_num);
					}
					else {
						cout << "��ϵ� ���������� �����ϴ�." << endl;
					}
					break;
				case F::Del:	//�������׻���
					if (emp_E.family_empty(Emp_num) == true) {
						emp_E.family_delete(Emp_num);
					}
					else {
						cout << "��ϵ� ���������� �����ϴ�." << endl;
					}
					break;
				default:		//�ٽ��Է�
					system("cls");
					cout << "�ٽ� �Է����ּ���" << endl;
			}

		}
		Save_Data(emp_E, rtr_R);
	}
	else {
		cout << "���������ʴ� ����Դϴ�." << endl;
	}
}

/*-------------------------------------------------
 R_menu(): ������ �޴�
-------------------------------------------------*/
int R_menu() {
	int num;

	cout << "������ ���" << endl << endl;
	cout << "1.������ ��� ��ȸ" << endl;
	cout << "2.������ ��� ����" << endl;
	cout << "3.������ ��� ����" << endl;
	cout << "4.�ڷΰ���" << endl;
	cin >> num;
	return num;
}

/*-------------------------------------------------
 R_main(Employee&, Retiree&, Basic_info&): ������ ����
-------------------------------------------------*/
void R_main(Employee& emp_E, Retiree& rtr_R ,Basic_info& bas) {
	int num;
	system("cls");

	while ((num = R_menu()) != R::Exit) {
		switch (num) {
			case R::Ser:	//������ ��� ��ȸ
				if (rtr_R.rtr_check1() == true) {
					rtr_R.show_rtr_data();
				}
				else {
					cout << "��ȸ�� ��������� �����ϴ�." << endl;
				}
				break;
			case R::Cre:	//������ ��� ����
				if (rtr_R.rtr_check2() == true) {
					rtr_R.set_rtr_data(bas);
				}
				else {
					cout << "������ ��������� �����ϴ�." << endl;
				}
				break;
			case R::Mod:	//������ ��� ����
				if (rtr_R.rtr_check1() == true) {
					rtr_R.modify_rtr_data();
				}
				else {
					cout << "������ ��������� �����ϴ�." << endl;
				}
				break;
			default:		//�ٽ��Է�
				system("cls");
				cout << "�ٽ� �Է����ּ���" << endl;
		}
	}
	Save_Data(emp_E, rtr_R);
}

/*-------------------------------------------------
 S_menu(): ����˻� �޴�
-------------------------------------------------*/
int S_menu() {
	int num;

	cout << "��� �˻�" << endl << endl;
	cout << "1.�����ȣ �˻�" << endl;
	cout << "2.����̸� �˻�" << endl;
	cout << "3.����μ� �˻�" << endl;
	cout << "4.������� �˻�" << endl;
	cout << "5.�ڷΰ���" << endl;
	cin >> num;
	return num;
}

/*-------------------------------------------------
 S_main(): ����˻� ����
-------------------------------------------------*/
void S_main(Employee &emp_E) {
	int num;
	system("cls");

	while ((num = S_menu()) != S::Exit) {
		switch (num) {
			case S::Num: //�����ȣ �˻�
				emp_E.E_S_num();
				break;
			case S::Nam: //����̸� �˻�
				emp_E.E_S_name();
				break;
			case S::Dep: //����μ� �˻�
				emp_E.E_S_dep();
				break;
			case S::Pos: //�����å �˻�
				emp_E.E_S_pos();
				break;
			default:	 //�ٽ��Է�
				system("cls");
				cout << "�ٽ� �Է����ּ���" << endl;
			}

	}
}

/*-------------------------------------------------
 H_menu(): �λ�˻� �޴�
-------------------------------------------------*/
int H_menu() {
	int num;
	cout << "�λ� ����" << endl << endl;
	cout << "1.������(��ü)" << endl;
	cout << "2.������(����)" << endl;
	cout << "3.������(�μ�)" << endl;
	cout << "4.�����ڸ��" << endl;
	cout << "5.�ڷΰ���" << endl;
	cin >> num;
	return num;
}

/*-------------------------------------------------
 H_main(Employee&, Retiree&): �λ�˻� ����
-------------------------------------------------*/
void H_main(Employee &emp_E, Retiree &rtr_R) {
	int num;
	system("cls");

	while ((num = H_menu()) != H::Exit) {
		switch (num) {
		case H::All: //������(��ü) ���
			F_All_print(emp_E);
			break;
		case H::Pos: //������(����) ���
			F_Pos_print(emp_E);
			break;
		case H::Dep: //������(�μ�) ���
			F_Dep_print(emp_E);
			break;
		case H::Ret: //�����ڸ�� ���
			F_Ret_print(emp_E, rtr_R);
			break;
		default:	 //�ٽ��Է�
			system("cls");
			cout << "�ٽ� �Է����ּ���" << endl;
		}

	}
}

/*-------------------------------------------------
 Save_Data(Employee&, Retiree&): ������ �����ϱ�
-------------------------------------------------*/
void Save_Data(Employee& emp_E, Retiree& rtr_R) {
	emp_E.f_set_emp();
	emp_E.f_set_fmy1();
	rtr_R.f_set_rtr();
}

/*-------------------------------------------------
 Load_Data(Employee&, Retiree&, Basic_info& ): 
 ������ �ҷ�����
-------------------------------------------------*/
void Load_Data(Employee &emp_E, Retiree &rtr_R, Basic_info &bas) {
	bas.f_get_dep();
	bas.f_get_rel();
	bas.f_get_pos();
	emp_E.f_get_emp();
	rtr_R.f_get_rtr();
}