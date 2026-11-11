#include <bits/stdc++.h>
using namespace std;
int main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1;//R的车厢号与座位号 
	string c2, s2;//x的车厢号与座位号
	cin >> c1 >> s1 >> c2 >> s2;
	bool l_1 = 0, l_2 = 0, l_3 = 0;//控制步骤4 
	
	if (c1 == c2) {
		cout << 1;
		l_1 = 1;
	} else {
		cout << 0;
	}
	
	if ( l_1 == 1 && s1[0] == s2[0] && s1[1] == s2[1]) {
		cout << 1;
		l_2 = 1;
	} else {
		cout << 0;
	}
	
	if ( l_2 == 1 && s1[0] == s2[0] && s1[1] == s2[1]) {			
		if ( !(  s1[2] == 'C' && s2[2] == 'D' || s1[2] == 'D' && s2[2] == 'C' || s1[2] == 'C' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'C' || s1[2] == 'A' && s2[2] == 'D' || s1[2] == 'D' && s2[2] == 'A' || s1[2] == 'A' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'A'    
			||   s1[2] == 'B' && s2[2] == 'D' || s1[2] == 'D' && s2[2] == 'B' || s1[2] == 'B' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'B' ) ) {
			cout << 1;
			l_3 = 1;
		} else {
			cout << 0;
		}
	} else {
		cout << 0;
	}
	
	int p1 = (s1[0] - '0') * 10 + s1[1] - '0', o1 = s1[2] - 'A';
	int p2 = (s2[0] - '0') * 10 + s2[1] - '0', o2 = s2[2] - 'A'; 
	if ( l_3 == 1 && p1 == p2 && ( o1 == o2 + 1 || o1 == o2 - 1 ) ) {
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
	}
	return 0;
} 
