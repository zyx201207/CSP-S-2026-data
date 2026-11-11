#include<bits/stdc++.h>
using namespace std;
long long a[10000005],b[10000005];
string s[10000005],s2[10000005];
bool cmp(long long x,long long y)
{
	return x>y;
} 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(long long i=1;i<=m;i++)
	{
		b[i]=a[i];
		while(b[i])
		{
			if(b[i]%2==0)
			{
				s[i]+='0';
			}
			else
			{
				s[i]+='1';
			}
			b[i]/=2;
		}
	}
	long long y;
	for(long long i=0;i<s[1].size();i++)
	{
		if(s[1][i]=='1'&&s[2][i]=='1')
		{
			s2[1]+='1';	
		}
		else
		{
			s2[1]+='0';
		}
		y=1;
	}
	for(long long j=3;j<=m;j++)
	{
		for(long long i=0;i<s[j].size();i++)
		{
			if(s[j][i]=='1'&&s2[j-2][i]=='1')
			{
				s2[j-1]+='1';	
			}
			else
			{
				s2[j-1]+='0';
			}
			y=j-1;
		}
	}
	for(long long i=0;i<s2[y].size();i++)
	{
		if(int(s2[y][i]-'0')==1)
		{
			ans+=pow(2,i);
		}
	}
	cout<<ans;
	return 0;
} 
