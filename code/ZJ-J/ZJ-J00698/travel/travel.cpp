#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool s;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)cout<<1,s=true;
	else cout<<0;
	if(s2[0]==s4[0]&&s2[1]==s4[1]&&s)cout<<1;
	else cout<<0;
	if(s2[0]==s4[0]&&s2[1]==s4[1]&&s&&((s2[2]<='C'&&s2[2]<='A'&&s4[2]<='C'&&s4[2]>='A')||(s2[2]>'C'&&s2[2]<='E'&&s4[2]>'C'&&s4[2]<='E')))cout<<1;
	else cout<<0;
	if(s2[0]==s4[0]&&s2[1]==s4[1]&&s&&((s2[2]<='C'&&s2[2]<='A'&&s4[2]<='C'&&s4[2]>='A')||(s2[2]>'C'&&s2[2]<='E'&&s4[2]>'C'&&s4[2]<='E'))&&abs(s2[2]-s4[2])==1)cout<<1;
	else cout<<0;
	return 0;
}