#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=5e5+5;
int n,m;
int a[maxn];
int sum[maxn];

bool check(int len)
{
	for(int i=len;i<=n;i++)
	{
		if(sum[i]-sum[i-len]+m>=a[i]*len)
		{
			return 1;
		}
	}
	return 0;
}
 
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int l=1;
	int r=n+1;
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	cout<<l;
	return 0;
	
}

