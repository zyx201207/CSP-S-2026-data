//第一题是个模拟 O(1) 
//第二题是一个简单的找找规律的模拟？ O(n)
//第三题是个简单的位运算？（让我押中了）O(n log n)
//第四题是...... 没做出来就是防AK(bushi) 暴力 O(n^2)
//没ad-hoc狂喜 
#include<bits/stdc++.h>
using namespace std;
//int mian()
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false); 
	string c1, c2, s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) {
		cout << "1";
		if(s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << "1";
			if(((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) || ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F'))) {
				cout << "1";
				if((s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2]) || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')) {
					cout << "1";
				} else {
					cout << "0";
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}
