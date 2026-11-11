#include<bits/stdc++.h>
using namespace std;
int c1,s1[5],c2,s2[5];
int q[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	for(int i=1;i<=3;i++)
	{
		cin>>s1[i];
	}
	cin>>c2;
	for(int i = 1;i <= 3;i++)
	{
		cin>>s2[i];
	}
	if(c1==c2)
	{
		q[1]=1;
	}
	else
	{
		q[1]=0;
	}
	if(s1[1]==s2[1]&&s1[2]==s2[2])
	{
		q[2]=1;
	}
	else
	{
		q[2]==0;
	}
	
	for(int i = 1;i<=4;i++)
	{
		cout << q[i];
	}
	return 0;
}