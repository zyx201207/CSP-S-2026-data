#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0]||s2[1]!=s1[1])
	{
		cout<<"1000";
		return 0;
	}
	bool l1=false,l2=false;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
	{
		l1=true;
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
	{
		l2=true;
	}
	if(l1!=l2)
	{
		cout<<"1100";
		return 0;
	}
	if(!l1&&!l2)
	{
		cout<<"1111";
		return 0;
	}
	int t1=(int)s1[2],t2=(int)s2[2];
	if(t1+1!=t2&&t2+1!=t1)
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
