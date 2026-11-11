#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool t(char c) {
	if(c=='A'||c=='B'||c=='C') return 1;
	return 0;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int a1=(c1[0]-'0')*10+c1[1],a2=(c2[0]-'0')*10+c2[1];
	if(a1!=a2) cout<<"0000";
	else {
		int b1=(s1[0]-'0')*10+s1[1],b2=(s2[0]-'0')*10+s2[1];
		if(b1!=b2) cout<<"1000";
		else if(t(s1[2])!=t(s2[2])) cout<<"1100";
		else if(s1[2]=='D'||s2[2]=='D') cout<<"1111";
		else if(s1[2]=='B'||s2[2]=='B') cout<<"1111";
		else cout<<"1110"; 
	}
	return 0;
}