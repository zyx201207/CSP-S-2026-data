#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[500010];
int n,m,need=0,maxn=-1e18,d;

bool cmp(int x,int y)
{
	return x>y;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i],maxn=max(maxn,a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=n; i++) need+=(maxn-a[i]);
	
	for(int i=1; i<=n; i++)
	{
		if(need<=m)
		{
			cout<<n-i+1;
			return 0;
		}
		d=(a[i]-a[i+1])*(n-i);
		need-=d;
	}
	cout<<1;
	
	return 0;
}
