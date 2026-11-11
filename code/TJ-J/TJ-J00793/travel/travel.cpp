#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3)
	{
		cout<<"0000";
		return 0;
	}
	else cout<<"1";
	int p=1;
	for(int i=0;i<=1;i++)
		if(s2[i]!=s4[i]) p=0;
	if(p==0)
	{
		cout<<"000";
		return 0;
	}
	cout<<p;
	if(s2[2]>'C'&&s4[2]<'D'||s4[2]>'C'&&s2[2]<'D')
	{
		cout<<"00";
		return 0;
	}
	else cout<<"1";
	if(s2[2]=='A'&&s4[2]=='B'||s2[2]=='B'&&s4[2]=='A') cout<<"1";
	else if(s2[2]=='B'&&s4[2]=='C'||s2[2]=='C'&&s4[2]=='B') cout<<"1";
	else if(s2[2]=='D'&&s4[2]=='F'||s2[2]=='F'&&s4[2]=='D') cout<<"1";
	else cout<<"0";
	return 0;
}
