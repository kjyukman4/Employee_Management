//�޴�ȭ��

#ifndef __MENUVISION__
#define __MENUVISION__
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

namespace M {
	enum m { Emp = 1, Bas = 2, Fam = 3, Ret = 4, Hri = 5, Test = 6, Quit = 7 }; //���θ޴�
};

namespace E {
	enum e { Reg = 1, Mod = 2, Del = 3, Ser = 4, Exit = 5 };					//���������޴�
};

namespace B {
	enum b { Dep = 1, Rel = 2, Pos = 3, Exit = 4 };								//���������޴�
};

namespace B_sub {
	enum b { Ser = 1, Ins = 2, Mod = 3, Del = 4, Exit = 5 };					//�����������θ޴�
};

namespace F {
	enum f { Reg = 1, Ser = 2, Mod = 3, Del = 4, Exit = 5 };					//�����޴�
};

namespace R {
	enum r { Ser = 1, Cre = 2, Mod = 3, Exit = 4 };								//������ �޴�
};

namespace S {
	enum s { Num = 1, Nam = 2, Dep = 3, Pos = 4, Exit = 5 };					//����˻� �޴�
};

namespace H {
	enum h { All = 1, Pos = 2, Dep = 3, Ret = 4, Exit = 5 };					//�λ����� �޴�
};
#endif