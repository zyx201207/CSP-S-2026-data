#include <bits/stdc++.h>
#define int long long
using namespace std;
string s[10];
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	for(int i = 1;i <= 4;i++){
		cin >> s[i];
	}
	if(s[1][0] != s[3][0] || s[1][1] != s[3][1]){
		cout << "0000";
		return 0;
	}
	else{
		cout << 1;
		if(s[2][0] != s[4][0] || s[2][1] != s[4][1]){
			cout << "000";
			return 0;
		}
		else{
			cout << 1;
		}
		if((s[2][2] <= 'C' && s[4][2] >= 'D') || (s[4][2] <= 'C' && s[2][2] >= 'D')){
				cout << "00";
				return 0;
			}
		else{
			cout << 1;
		}
		if((s[2][2] == 'A' && s[4][2] == 'C') || (s[2][2] == 'C' && s[4][2] == 'A')){
			cout << 0;
		}
		else{
			cout << 1;
		}
	}
	return 0;
}
