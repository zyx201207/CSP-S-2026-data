#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N];
int yu(int x,int y)
{
	string s1,s2;
	int he=0,k=1;
	while(x>0)
	{
		s1=char(x%2+'0')+s1;
		x/=2;
	}
	while(y>0)
	{
		s2=char(y%2+'0')+s2;
		y/=2;
	}
	if(s1.size()>s2.size())
	{
		for(int i=s1.size()-1,j=s2.size()-1;j>=0;i--,j--)
		{
			if(s1[i]=='1'&&s2[j]=='1')he+=k;
			k*=2;
		}
	}
	else
	{
		for(int i=s2.size()-1,j=s1.size()-1;j>=0;i--,j--)
		{
			if(s2[i]=='1'&&s1[j]=='1')he+=k;
			k*=2;
		}
	}
	return he;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1)
	{
		int mx=-1;
		for(int i=1;i<=n;i++)
			mx=max(mx,a[i]);
		cout<<mx;
		return 0;
	}
	if(m==2)
	{
		int mx=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
				mx=max(mx,yu(a[i],a[j]));
		}
		cout<<mx;
		return 0;
	}
	if(m==n)
	{
		int mx=a[1];
		for(int i=2;i<=n;i++)
			mx=yu(a[i],mx);
		cout<<mx;
		return 0;
	}
	return 0;
}
