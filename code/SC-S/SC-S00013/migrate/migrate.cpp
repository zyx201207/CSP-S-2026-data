#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int n,m,a[N],stk[N],tp,mn,res;
void dfs(int nw,int r)
{
	if(nw==r)
	{
		if(tp<mn) mn=tp,res=0;
		if(tp<=mn) res++;
	}
	for(int i=nw+1;i<=r;i++)
	{
		if(a[i]-a[nw]>m) break;
		stk[++tp]=i;
		dfs(i,r);
		tp--;
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1)
	{
		cout<<0<<'\n';
		return;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			res=0,mn=1e18;
			dfs(i,j);
			if(res==2) ans++;
		}
	}
	cout<<ans<<'\n';
}
void solve2()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1)
	{
		cout<<0<<'\n';
		return;
	}
	m=m/(a[2]-a[1]);
	if(m==0||m==1||n-2*m+1<=0)
	{
		cout<<0<<'\n';
		return;
	}
	cout<<n-2*m+1<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	if(c<=2)
	{
		while(t--)
		{
			solve();
		}
	}
	else if(11<=c&&c<=12)
	{
		while(t--)
		{
			solve2();
		}
	}
	else
	{
		while(t--)
		{
			cout<<0<<'\n';
		}
	}
	return 0;
}
/*
0 
2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


*/