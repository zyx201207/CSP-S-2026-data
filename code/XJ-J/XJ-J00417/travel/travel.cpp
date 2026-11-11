#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int n=2,m=3;
	for(int i=0;i<n;i++)
	{
		if(c1[i]!=c2[i])
		{
			cout<<"0000";
			return 0;
		}
	}
	cout<<1;
	int a[10],b[10];
	for(int i=0;i<m;i++)
	{
		if(s1[i]>='0'&&s1[i]<='9')
		{
			a[i]=s1[i]-'0';
		}
		if(s1[i]>='A'&&s1[i]<='Z')
		{
			a[i]=s1[i]-'A'+1; 
		}
		if(s1[i]=='F') a[i]=5; 
		if(s2[i]>='0'&&s2[i]<='9')
		{
			b[i]=s2[i]-'0';
		}
		if(s2[i]>='A'&&s2[i]<='Z')
		{
			b[i]=s2[i]-'A'+1; 
		} 
		if(s2[i]=='F') b[i]=5; 	 
	}
	if(a[0]==b[0]&&a[1]==b[1])
	{
		cout<<"1";
		if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C'))
		{
			cout<<"00";
		}
		else
		{
			cout<<1;
			if(a[2]-b[2]==1||b[2]-a[2]==1)
			{
				cout<<"1";
			}
			else
			{
				cout<<"0";
			}
		}
	}
	else
	{
		cout<<"000";
	}
	return 0;
} 
