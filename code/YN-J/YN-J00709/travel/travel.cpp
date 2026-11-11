#include <iostream>
#include <string.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.in", "w", stdout);
	//输入的第一行包含四个字符串 c1, s1, c2, s2，分别表示小 R 的车票上的车厢号、座位
	//号，以及小 X 的车票上的车厢号、座位号
	string c1, c2, s1, s2;
	int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
	//? 两张车票对应的座位是否在同一节车厢；
	//? 两张车票对应的座位是否在同一节车厢的同一排；
	//? 两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
	//? 两张车票对应的座位是否相邻。
	cin >> c1 >> s1 >> c2 >> s2;
	//a1
	if (c1 == c2)
		a1 = 1;
	else
		a1 = 0;
	//a2
	if (s1[0] == s2[0] && s1[1] == s2[1] && a1 == 1)
		a2 = 1;
	else
		a2 = 0;
	//a3
	string A = "A", B = "B", C = "C", D = "D", F = "F", X, Y ;
	X = s1[2];
	Y = s2[2];
	if (X == A || X == B || X == C && Y == A || Y == B || Y == C)
		a3 = 1;
	if (X == D || X == F && Y == D || Y == F)
		a3 = 1;
	if (a2 == 0)
		a3 = 0;
	//a4
	if (X == A && Y == B)
		a4 = 1;
	else if (X == B && Y == B)
		a4 = 1;
	else if (X == B && Y == A)
		a4 = 1;
	else if (X == C && Y == B)
		a4 = 1;
	else if (X == D && Y == F)
		a4 = 1;
	else if (X == F && Y == D)
		a4 = 1;
	else
		a4 = 0;
	if (a3 == 0)
		a4 = 0;
	cout << a1 << a2 << a3 << a4;
	return 0;
}
