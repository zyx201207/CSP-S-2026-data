#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
	} 
	else
	{
		cout<<"0000";
		return 0;
	} 
	int f=1;
	for(int i=0;i<2;i++)
	{
		if(s1[i]!=s2[i]) f=0;
	}
	if(f==1)
	{
		cout<<"1";
	} 
	else
	{
		cout<<"000";
		return 0;
	} 
	if((('A'<=s1[2]&&s1[2]<='C')&&('A'<=s2[2]&&s2[2]<='C')))
	{
		cout<<"1";
	}
	else if((('D'<=s1[2]&&s1[2]<='F')&&('D'<=s2[2]&&s2[2]<='F')))
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	} 
	int t1,t2;
	t1=int(s1[2]-'0');
	t2=int(s2[2]-'0');
	if(((t1>t2)&&t1-t2==1)||((t2>t1)&&t2-t1==1))
	{
		cout<<"1";
	}
	else cout<<"0";
	return 0;
}

