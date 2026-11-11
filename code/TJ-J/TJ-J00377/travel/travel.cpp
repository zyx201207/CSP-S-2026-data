#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 == c2) {
		cout << '1';
		if(s1.substr(0, 2) == s2.substr(0, 2)){
			cout << '1';
			if((('A' <= s1[2] && s1[2] <= 'C') && ('A' <= s2[2] && s2[2] <= 'C')) || (('D' <= s1[2] && s1[2] <= 'E') && ('D' <= s2[2] && s2[2] <= 'E'))){
				cout << '1';
				if(('A' <= s1[2] && s1[2] <= 'C' && abs(s1[2] - s2[2]) == 1) || 'D' <= s1[2] && s1[2] <= 'E'){
					cout << '1';
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
