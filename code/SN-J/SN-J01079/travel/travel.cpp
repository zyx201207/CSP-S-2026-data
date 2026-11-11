#include<bits/stdc++.h>
using namespace std;
string c[2], s[2];
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	long long t = 1;
	//cin >> t;
	while(t --){
		for(int i = 0; i < 2; i ++)
			cin >> c[i] >> s[i];
		if(c[0] == c[1])
			cout << 1;
		else{
			cout << "0000";
			return 0;
		}
		if(s[0][0] == s[1][0] && s[0][1] == s[1][1])
			cout << 1;
		else{
			cout << "000";
			return 0;
		}
		if((s[0][2] <= 'F' && s[0][2] >= 'D' && s[1][2] <= 'F' && s[1][2] >= 'D') || (s[0][2] <= 'C' && s[0][2] >= 'A' && s[1][2] <= 'C' && s[1][2] >= 'A')){
			cout << 1;
		}
		else{
			cout << "00";
			return 0;
		}
		if(abs(s[0][2] - s[1][2]) == 1) cout << 1;
		else cout << "0";
	}
	return 0;
}


