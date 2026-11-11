#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
string c1,s1,c2,s2;
int main(){
	FIO
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int ch1 = max(s1[2],s2[2]),ch2 = min(s1[2],s2[2]);
	if(c1 == c2) cout << 1;
	else{
		cout << "0000";
		return 0;
	}
	if(s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
	else {
		cout << "000";
		return 0;
	}
	if(s1[2] == 'A' && (s2[2] == 'B' || s2[2] == 'C')){
		if(s2[2] == 'B') cout << 11;
		else cout << 10;
	} 
	else if(s1[2] == 'B' && (s2[2] == 'A' || s2[2] == 'C')) cout << 11;
	else if(s1[2] == 'C' && (s2[2] == 'B' || s2[2] == 'A')){
		if(s2[2] == 'B') cout << 11;
		else cout << 10;
	}
	else if(s1[2] == 'D' && s2[2] == 'F'){
		cout << 11;
		return 0;
	}
	else if(s1[2] == 'F' && s2[2] == 'D'){
		cout << 11;
		return 0;
	} 
	else{
		cout << "00";
		return 0;
	}
	return 0;
}