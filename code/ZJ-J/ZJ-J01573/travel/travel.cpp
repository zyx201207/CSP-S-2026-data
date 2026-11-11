#include<bits/stdc++.h>
using namespace std;
char c1[10],s1[10],c2[10],s2[10],l1,l2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=3;i++)
	{
		if(s1[i]>='A'&&s1[i]<='F')
		{
			l1=s1[i];
		}
		if(s2[i]>='A'&&s2[i]<='F')
		{
			l2=s2[i];
		}
	}
	if(c1[1]==c2[1]&&c1[2]==c2[2])
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}//同车厢 
	if(s1[1]==s2[1])
	{
		if(s1[2]>='A'&&s1[2]<='F'&&s2[2]>='A'&&s2[2]<='F')
		{
			cout<<"1";
		}
		else
		{
			if(s1[2]==s2[2])
			{
				cout<<"1";
			}
			else
			{
				cout<<"000";
				return 0;
			}
		}
	}
	else
	{
		cout<<"000";
		return 0;
	}
	//同排 
	if(l1>='A'&&l1<='C'&&l2>='A'&&l2<='C'||l1>='D'&&l1<='F'&&l2>='D'&&l2<='F')
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}//同侧 
	if(l1>='A'&&l1<='C'&&l2>='A'&&l2<='C')
	{
		if(l1+1==l2||l2+1==l1)
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	else
	{
		if(l1>='D'&&l1<='F'&&l2>='D'&&l2<='F')
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}//相邻 
	return 0;
}
