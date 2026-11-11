#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool f1,f2,f3;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) f1=1,cout<<1;
	else return cout<<"0000",0;
	if(s2[0]==s4[0]&&s2[1]==s4[1]&&f1==1) f2=1,cout<<1;
	else cout<<0;
	if(f2==1)
	{
		if(s2[2]=='A'&&s4[2]=='B') cout<<11;
		else if(s2[2]=='B'&&s4[2]=='C') cout<<11;
		else if(s2[2]=='A'&&s4[2]=='C') cout<<10;
		else if(s2[2]=='D'&&s4[2]=='F') cout<<11;
		else if(s2[2]=='B'&&s4[2]=='A') cout<<11;
		else if(s2[2]=='C'&&s4[2]=='A') cout<<10;
		else if(s2[2]=='C'&&s4[2]=='B') cout<<11;
		else if(s2[2]=='F'&&s4[2]=='D') cout<<11;
		else cout<<"00";
	}
	else cout<<"00";
	return 0;
}
