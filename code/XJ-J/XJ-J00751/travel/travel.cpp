#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string n2=s2.substr(0,2);
	string n1=s1.substr(0,2);
	int flag1=0,flag2=0;
	if(s1[2]=='D'||s1[2]=='F') flag1==1;
	if(s2[2]=='D'||s2[2]=='F') flag2==1;
	if(c1==c2) cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(n1==n2) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if(flag1==flag2) cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if(s1[2]+1==s2[2]||s2[2]+1==s1[2]) cout<<1;
	else cout<<0;
	return 0;
}