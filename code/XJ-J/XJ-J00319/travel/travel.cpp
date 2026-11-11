#include<bits/stdc++.h>
using namespace std;
char c1[3],s1[5],c2[3],s2[5];
int a[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<2;i++)
	{
		cin >> c1[i];
	}
	for(int i=0;i<3;i++)
	{
		cin >> s1[i];
	}
	for(int i=0;i<2;i++)
	{
		cin >> c2[i];
	}
	for(int i=0;i<3;i++)
	{
		cin >> s2[i];
	}
	for(int i=1;i<=4;i++)
	{
		a[i] = 0;
	}
	for(int i=0;i<2;i++)
	{
		if(c1[i]==c2[i])
		{
			a[1]=1;
		}
		else
		{
			a[1]=0;
			cout << "0000";
			return 0;
		}
	}
	if(s1[1]==s2[1]&&s1[0]==s2[0])
	{
		a[2] = 1;
	}
	if((s1[2]==s2[2]-1||s1[2]==s2[2]-2||s1[2]==s2[2]-1||s2[2]==s1[2]-2)&&s2[2]!='D'&&s2[2]!='F'&&s1[2]!='D'&&s2[2]!='F')
	{
		a[3]=1;
	}
	if(s2[2]=='D'&&s1[2]=='F'||s1[2]=='D'&&s2[2]=='F')
	{
		a[3]=1;
		a[4]=1;
	}
	if((s1[2]==s2[2]-1||s1[2]==s2[2]-1)&&s1[2]!='D'&&s1[2]!='F'&&s2[2]!='D'&&s2[2]!='F')
	{
		a[4] = 1;
	}
	for(int i=1;i<=4;i++)
	{
		cout << a[i];
	}
	return 0;
}