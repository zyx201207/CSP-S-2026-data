#include <bits/stdc++.h>
using namespace std;

string s1, s2, c1, c2;
int main(){
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1 >> s2 >> c1 >> c2;
	int s1_setcar = (s1[0] - '0') * 10 + s1[1] - '0';
	int c1_setcar = (c1[0] - '0') * 10 + c1[1] - '0';
	if (s1_setcar == c1_setcar){
		cout << "1";
		int s_set = (s2[0] - '0') * 10 + s2[1] - '0';
		char s_op = s2[2];
		int c_set = (c2[0] - '0') * 10 + c2[1] - '0';
		char c_op = c2[2];
		if (c_set == s_set){
			cout << "1";
			if (s_op >= 'A' && s_op <= 'C' && c_op >= 'A' && c_op <= 'C'){
				cout << "1";
				if (abs(s_op - c_op) == 1){
					cout << "1";
				} else {
					cout << "0";
				}
			} else if (s_op == 'D' || s_op <= 'F' && c_op >= 'D' || c_op <= 'F'){
				cout << "11";
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
