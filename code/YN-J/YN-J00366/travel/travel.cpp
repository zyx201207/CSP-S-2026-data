#include <bits/stdc++.h>
using namespace std;
int a1, b1, a3, b3;
string a2, b2;
int a4, b4;
bool a[10];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a1 >> a2 >> b1 >> b2;
	for (int i = 0; i < a2.size() - 1; i++) {
		if (a2[i] == 0)
			continue;
		else {
			if (i == 0)
				a3 += (a2[i] - 48) * 10;
			else
				a3 += a2[i] - 48;
		}
	}
	a4 = a2[2] - 64;
	for (int i = 0; i < b2.size() - 1; i++) {
		if (b2[i] == 0)
			continue;
		else {
			if (i == 0)
				b3 += (b2[i] - 48) * 10;
			else
				b3 += b2[i] - 48;
		}
	}
	b4 = b2[2] - 64;
//	cout << a1 << " " << a3 << " " << a4 << " ";
//	cout << b1 << " " << b3 << " " << b4 << " ";
	//是否在同一节车厢
	if (a1 == b1)
		cout << 1;
	else
		cout << 0;
	//是否在同一节车厢的同一排
	if (a1 == b1 && a3 == b3)
		cout << 1;
	else
		cout << 0;
	//是否在同一节车厢的同一排，且位于过道的同一侧
	if (a1 == b1 && a3 == b3) {
		if (a4 == 3 && b4 == 4)
			cout << 0;
		else if (abs(a4 - b4) == 1 || abs(a4 - b4) == 2)
			cout << 1;
		else
			cout << 0;
	} else
		cout << 0;
	//是否相邻
	if (a1 == b1 && a3 == b3) {
		if (a4 == 3 && b4 == 4)
			cout << 0;
		else if (abs(a4 - b4) == 1)
			cout << 1;
		else
			cout << 0;
	} else
		cout << 0;
	return 0;
}


