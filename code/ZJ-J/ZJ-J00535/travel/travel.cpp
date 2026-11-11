#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
void run()
{
	int f=1;
	int ff=1;
	int fff=1;
	int ffff=1;
	cin>>s1;
	cin>>c1;
	cin>>s2;
	cin>>c2;
	for(int i=0;i<=1;i++)
	{
		if(s1[i]!=s2[i])
		{
			f=0;
			break;
		}
	}
	if(f==0)
	{
		cout<<"0000";
		return;
	}
	for(int i=0;i<=1;i++)
	{
		if(c1[i]!=c2[i])
		{
			ff=0;
			break;
		}
	}
	if(f==1&&ff==0)
	{
		cout<<"1000";
		return ;
	}
	if(c1[2]-'A'<=2)
	{
		if(c2[2]-'A'>2)
		{
			fff=0;
		}
	}
	if(c1[2]-'A'>2)
	{
		if(c2[2]-'A'<=2)
		{
			fff=0;
		}
	}
	if(f==1&&ff==1&&fff==0)
	{
		cout<<"1100";
		return ;
	}
	int a=c1[2]-'A';
	int b=c2[2]-'A';
	if(abs(a-b)==1)
	{
		cout<<"1111";
		return ;
	}
	cout<<"1110";
	return ;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	run();
	return 0;
}