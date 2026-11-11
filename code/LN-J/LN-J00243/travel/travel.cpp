#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	string s1,s2,c1,c2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		 cout << "0000";
		 return 0; 
	}else{
		cout << "1";
	}
	if(s1[0] == s2[0] && s1[1] == s2[1]){
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}
	if(s1[3]<='C' && s2[3] <= 'C'){
		cout << "1";
	} else if(s1[3]>'C' && s2[3] > 'C'){
		cout << "11";
		return 0;
	} else {
		cout << "00";
		return 0;
	}
	if(s1[3] != 'B' && s2[3] != 'B'){
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;
}
