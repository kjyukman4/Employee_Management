//메뉴화면

#ifndef __MENUVISION__
#define __MENUVISION__
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

namespace M {
	enum m { Emp = 1, Bas = 2, Fam = 3, Ret = 4, Hri = 5, Test = 6, Quit = 7 }; //메인메뉴
};

namespace E {
	enum e { Reg = 1, Mod = 2, Del = 3, Ser = 4, Exit = 5 };					//기초정보메뉴
};

namespace B {
	enum b { Dep = 1, Rel = 2, Pos = 3, Exit = 4 };								//기초정보메뉴
};

namespace B_sub {
	enum b { Ser = 1, Ins = 2, Mod = 3, Del = 4, Exit = 5 };					//기초정보내부메뉴
};

namespace F {
	enum f { Reg = 1, Ser = 2, Mod = 3, Del = 4, Exit = 5 };					//가족메뉴
};

namespace R {
	enum r { Ser = 1, Cre = 2, Mod = 3, Exit = 4 };								//퇴직자 메뉴
};

namespace S {
	enum s { Num = 1, Nam = 2, Dep = 3, Pos = 4, Exit = 5 };					//사원검색 메뉴
};

namespace H {
	enum h { All = 1, Pos = 2, Dep = 3, Ret = 4, Exit = 5 };					//인사정보 메뉴
};
#endif