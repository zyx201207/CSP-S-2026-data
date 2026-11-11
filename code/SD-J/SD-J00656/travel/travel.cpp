#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s2[2]=='F')s2[2]='E';
	if(s4[2]=='F')s4[2]='E';
	if(s1==s3)a=1;
	if(a&&s2[0]==s4[0]&&s2[1]==s4[1])b=1;
	if(b&&((s2[2]<='C'&&s4[2]<='C')||(s2[2]>='D'&&s4[2]>='D')))c=1;
	if(c&&abs(s2[2]-s4[2])==1&&(!((s2[2]=='C'&&s4[4]=='D')||(s2[2]=='D'&&s4[2]=='C'))))d=1;
	cout<<a<<b<<c<<d<<endl;
	return 0;
}
