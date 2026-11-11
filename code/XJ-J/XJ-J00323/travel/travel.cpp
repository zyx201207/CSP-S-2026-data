#include<bits/stdc++.h> 
using namespace std;
//const int N=;
string s[5],s1[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s[1]>>s[2]>>s1[1]>>s1[2];
	if(s[1]==s1[1])cout<<1;
	else cout<<0;
	int a=(s[2][0]-'0')*10+s[2][1]-'0';
	int b=(s1[2][0]-'0')*10+s1[2][1]-'0';
	if(s[1]==s1[1]&&a==b)cout<<1;
	else cout<<0;
	if(s[1]==s1[1]&&a==b&&(s[2][2]<='C'&&s1[2][2]<='C'||s[2][2]>'C'&&s1[2][2]>'C'))cout<<1;
	else cout<<0;
	if(s[1]==s1[1]&&a==b&&(s[2][2]<='C'&&s1[2][2]<='C'||s[2][2]>'C'&&s1[2][2]>'C')&&abs((s[2][2]-'A')-(s1[2][2]-'A'))==1)cout<<1;
	else cout<<0;
	//cout<<'@'<<abs((s[2][2]-'A')-(s1[2][2]-'A'))<<'@'<<(s[2][2]=='C'&&s1[2][2]!='D'||s1[2][2]=='C'&&s[2][2]!='D');
	// cout<<'~'<<a<<' '<<b<<'`'<<s[2][1]<<(s[2][1]-'0')*10;
	return 0;
}
