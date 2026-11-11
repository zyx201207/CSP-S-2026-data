#include <bits/stdc++.h>
using namespace std;

long long a[500005],s[500005];
long long n,m,cnt=1,maxn=-1;
bool t=true;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;											
	if(n==1)
	{
		cin>>a[1];
		cout<<1;
		return 0;
	}
	if(n==2)
	{
		cin>>a[1]>>a[2];
		if(a[1]>a[2] && (a[1]-a[2])<=m) cout<<2;
		else if(a[1]<a[2] && (a[2]-a[1]<=m)) cout<<2;
		else if(a[1]==a[2]) cout<<2;
		else cout<<1;
		return 0;
	}
	
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	for(long long i=2;i<=n;i++)
	{
		s[i]=a[i]-a[i-1];
		if(i>2 && s[i]!=s[i-1]) t=false;
	}
	long long x=s[2];
	if(t){
		while(m>=x && cnt<n)
		{
			cnt++;
			m-=x;
			x*=2;
		}
		cout<<cnt;
		return 0;
	}
	
	long long ml=m;
	for(long long i=1;i<=n;i++)
	{
		x=1;
		for(long long j=1;j<=n;j++)
		{
			if(i!=j && j<i)
			{
				s[x]=a[i]-a[j];
				x++;
			}
		}
		sort(s+1,s+x);
		long long j=1;
		cnt=1;
		m=ml;
		while(m>=s[j] && j<x)
		{
			cnt++;
			m-=s[j];
			j++;
		}
		maxn=max(cnt,maxn);
	}	
	cout<<maxn;
	return 0;
}
