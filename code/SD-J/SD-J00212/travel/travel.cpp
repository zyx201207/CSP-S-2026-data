#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		cout << "1";
		int l1 = s1.size();
		int l2 = s2.size();
		int ss1 = s1[0] + s1[1];
		int ss2 = s2[0] + s2[1];
		if (ss1 == ss2){
			cout << "1";
			if ((s1[2] >= 'D' && s2[2] >= 'D') || (s1[2] < 'D' && s2[2] < 'D')){
				cout << "1";
				if (abs(int(s1[2] - 'A') - int(s2[2] - 'A')) == 1){
					cout << "1";
				}else{
					cout << "0";
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	return 0;
}
