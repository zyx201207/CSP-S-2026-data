#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1==c2)cout << 1;
	else{
		cout << "0000";
		return 0;
	}
	
	if(s1[0]==s2[0] && s1[1]==s2[1])cout << 1;
	else{
		cout << "000";
		return 0;
	}
	
	if(s1[2]>s2[2])swap(s1[2],s2[2]);
	
	if('A'<=s1[2] && s1[2]<='C' && 'D'<=s2[2] && s2[2]<='F'){
		cout << "00";
		return 0;
	}
	else cout << 1;
	
	if((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='C') || (s1[2]=='D' && s2[2]=='F'))cout << 1;
	else cout << 0;
	
	return 0;
}
