#include<bits/stdc++.h>
using namespace std;
string s,s1,c,c1;
int main(){
	cin>>c>>s>>c1>>s1;
	freopen("w","travel.in",stdin);
	freopen("r","travel.out",stdout);
	if(c==c1)cout<<1;
	else cout<<0;
	if(c==c1&&s[0]==s1[0]&&s[1]==s1[1])cout<<1;
	else cout<<0;
	if(c==c1&&s[0]==s1[0]&&s[1]==s1[1]&&((s[2]<='C')==(s1[2]<='C')))cout<<1;
	else cout<<0;
	if(c==c1&&s[0]==s1[0]&&s[1]==s1[1]&&1==abs(s[2]-s1[2])&&((s[2]<='C')==(s1[2]<='C')))cout<<1;
	else cout<<0;
}
