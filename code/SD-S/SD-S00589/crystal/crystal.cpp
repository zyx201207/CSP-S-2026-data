#include <bits/stdc++.h>
using namespace std;
#define ll long long
int const N=1e6+5;
inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if (ch == '-')
		{
			f = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
ll n,m,a[N],sum[N],ans;
bool check(int x,int s)
{
	return (s-x+1)*a[s]-(sum[s]-sum[x-1])<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	ans=1;
	for(int i=2;i<=n;i++)
	{
		int l=1,r=i,mid;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(check(mid,i))
				r=mid;
			else
				l=mid+1;
		}
		ans=max(ans,1ll*i-l+1);
	}
	cout<<ans;
	return 0;
}

