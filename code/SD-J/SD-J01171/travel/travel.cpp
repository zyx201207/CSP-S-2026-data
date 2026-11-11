#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	bool fl = 0, fk = 0; 
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) { // 同车厢 
		cout << 1;
		fk = 1;
	}
	else {
		cout << 0;
	}
	if(s1[0] == s2[0] && s1[1] == s2[1] && fk == 1) { // 同一排 ，同车箱 
		cout << 1;
		if((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C')) { // 同一侧 
			cout << 1;
			fl = 1;
		}
		else { // 不同侧 
			cout << 0;
		}
	}
	else { // 不统派不同侧 
		cout << 0 << 0;
	}
	int q = (s1[0] - '0') * 10 + (s1[1] - '0');
	int p = (s2[0] - '0') * 10 + (s2[1] - '0');
	if(p == q && s1[2] == s2[2] && fk == 1) { // 同一排并且同一座 ，同意车厢 
		cout << 1;
	}
	else if(p == q) { // 同一排 
		int ksa = s1[2] - 'A';
		int ksb = s2[2] - 'A';
		if(abs(ksa - ksb) == 1 && fl == 1 && fk == 1) {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	else {
		cout << 0;
	}
	return 0;
}
//Trick||Treat!
/*两张车票对应的座位是否在同一节车厢；
? 两张车票对应的座位是否在同一节车厢的同一排；
? 两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
? 两张车票对应的座位是否相邻。*/
