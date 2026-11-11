#include <bits/stdc++.h>
using namespace std;
string c1, c2; //两个车箱号
string s1, s2; //两个座位号

bool sameside() {
	if (s1[2] == 'A')
		return s2[2] == 'B' || s2[2] == 'C';
	if (s1[2] == 'B')
		return s2[2] == 'A' || s2[2] == 'C';
	if (s1[2] == 'C')
		return s2[2] == 'B' || s2[2] == 'A';
	if (s1[2] == 'D')
		return s2[2] == 'F';
	if (s1[2] == 'F')
		return s2[2] == 'D';
}

bool xiangling() {
	if (s1[2] == 'A')
		return s2[2] == 'B';
	if (s1[2] == 'B')
		return s2[2] == 'A' || s2[2] == 'C';
	if (s1[2] == 'C')
		return s2[2] == 'B';
	if (s1[2] == 'D')
		return s2[2] == 'F';
	if (s1[2] == 'F')
		return s2[2] == 'D';
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	std::cin >> c1 >> s1 >> c2 >> s2;
	//1
	if (c1 == c2)
		cout << 1;
	else
		cout << 0;
	//2
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1])
		cout << 1;
	else
		cout << 0;
	//3
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && sameside())
		cout << 1;
	else
		cout << 0;
	//4
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && xiangling())
		cout << 1;
	else
		cout << 0;
	return 0;
}