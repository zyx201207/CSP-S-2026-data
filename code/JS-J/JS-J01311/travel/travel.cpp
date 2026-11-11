#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool car_chexiang, pai_pai, sid_tongce, by_xianglin;
string pai1 = "", pai2 = "";
char zuo1, zuo2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	//cout << c1 << ' ' << s1 << ' ' << c2 << ' ' << s2 << '\n';
	//cout << s1[0] << '\n' << s1[1] << '\n';
	pai1 += s1[0];
	pai1 += s1[1];
	//cout << pai1 << '\n';
	// get the first pai
	pai2 += s2[0];
	pai2 += s2[1];
	//cout << pai1 << '\n';
	// get the second pai
	if (c1 == c2) { // in the same car
		car_chexiang = true;
	}
	if (car_chexiang) {
		if (pai1 == pai2) { // in the same pai
			pai_pai = true;
		}
	}
	zuo1 = s1[2];
	zuo2 = s2[2];
	if (pai_pai == true) {
		if (zuo1 == 'A' && (zuo2 == 'B' || zuo2 == 'C'))
			sid_tongce = true;
		if (zuo1 == 'B' && (zuo2 == 'A' || zuo2 == 'C'))
			sid_tongce = true;
		if (zuo1 == 'C' && (zuo2 == 'A' || zuo2 == 'B'))
			sid_tongce = true;
		if (zuo1 == 'D' && zuo2 == 'F')
			sid_tongce = true;
		if (zuo1 == 'F' && zuo2 == 'D')
			sid_tongce = true;
	}
	if (sid_tongce == true) {
		if (zuo1 == 'A' && zuo2 == 'B')
			by_xianglin = true;
		if (zuo1 == 'B' && (zuo2 == 'A' || zuo2 == 'C'))
			by_xianglin = true;
		if (zuo1 == 'C' && zuo2 == 'B')
			by_xianglin = true;
		if (zuo1 == 'D' && zuo2 == 'F')
			by_xianglin = true;
		if (zuo1 == 'F' && zuo2 == 'D')
			by_xianglin = true;
	}
	cout << car_chexiang << pai_pai << sid_tongce << by_xianglin << '\n';
	
	return 0;
}
