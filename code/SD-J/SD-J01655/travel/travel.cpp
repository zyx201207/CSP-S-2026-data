#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c,c_n;
	string s,s_n;
	cin >> c >> s >> c_n >> s_n;
	if(c == c_n){
		cout << 1;
	}else{
		cout << "0000";
		return 0;
	}
	if(s[0] == s_n[0] && s[1] == s_n[1]){
		cout << 1;
	}else{
		cout << "000";
		return 0;
	}
	if((s[2] <= 'C' && s_n[2] <= 'C') || (s[2] >= 'D' && s[2] >= 'D')){
		cout << 1;
		if(abs(s[2] - s_n[2]) == 1 || (s[2] == 'D' || s[2] == 'F') && (s_n[2] == 'D' || s_n[2] == 'F')){
			cout << 1;
		}else{
			cout << 0;
		}
	}else{
		cout << "00";
	}
	return 0;
} 
