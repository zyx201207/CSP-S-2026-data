#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cnt;
int a[500006];
int s[500006];
int x[500006];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	s[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=a[i]+s[i-1];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		x[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(m<x[i]*i)
		{
			break;
		}
		cnt+=1;
		m-=x[i]*i;
	}
	cout<<cnt+1;
}
