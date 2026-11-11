#include <bits/stdc++.h>
using namespace std;
string s;
long long a[100001],n,cnt=1,q,e[100011],sum,vis[100010],l;
char c[100011];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int i=1;i<=a[i];i++)
		{
			s[cnt]=c[i];
			cnt++;
		}
	}
	sum=cnt/2;
	int r=1;
	for(int i=1;i<=cnt/2;i++)
	{
		if(s[i]!=s[sum])
		{
			r=0;
			break;
		}
		sum++;
	}
	if(r==1)
	{
		cout<<0;
		return 0;
	}
	q=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
		{
			q=0;
			break;
		}
	}
	if(q==1)
	{
		cout<<0;
		return 0;	
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	if(n==2)
	{
		cout<<min(a[1],a[2]);
		return 0;
	}
		
	if(n==3)
	{
		if(c[1]==c[3])
		{
			cout<<abs(a[1]-a[3]);
			return 0;
		}
		if(c[1]==c[2])
		{
			cout<<min((a[1]+a[2]),a[3]);
			return 0;
		}
		if(c[1]!=c[2]&&c[1]!=c[3]&&c[2]!=c[3])
		{
			int d=max(max(a[1],a[2]),a[3]);
			if(d>=(s.size()-d))
			{
				cout<<s.size()-d;
				return 0;
			}
			else
			{
				cout<<d;
				return 0;
			}
		}
	}
	
	return 0;
} 
