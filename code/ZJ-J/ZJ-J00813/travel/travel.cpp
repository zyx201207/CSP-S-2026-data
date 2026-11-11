#include<bits/stdc++.h>
using namespace std;
string c[5],s[5];
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	bool is=(c[1]==c[2]);
	cout<<is;
	is=(is&&s[1][0]==s[2][0]&&s[1][1]==s[2][1]);
	cout<<is;
	is=(is&&(s[1][2]=='F'&&s[2][2]=='D'||s[1][2]=='D'&&s[2][2]=='F'
	||s[1][2]=='A'&&s[2][2]=='B'||s[1][2]=='B'&&s[2][2]=='A'
	||s[1][2]=='A'&&s[2][2]=='C'||s[1][2]=='C'&&s[2][2]=='A'||
	s[1][2]=='C'&&s[2][2]=='B'||s[1][2]=='B'&&s[2][2]=='C'));
	cout<<is;
	is=(is&&(s[1][2]=='F'&&s[2][2]=='D'||s[1][2]=='D'&&s[2][2]=='F'
	||s[1][2]=='A'&&s[2][2]=='B'||s[1][2]=='B'&&s[2][2]=='A'
	||s[1][2]=='B'&&s[2][2]=='C'||s[1][2]=='C'&&s[2][2]=='B'));
	cout<<is;
	return 0;
}