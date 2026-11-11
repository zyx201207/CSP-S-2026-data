#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,t,n,d,a[N],minn,cnt,ans,k;

void dfs(int x,int sum,int y)
{
	if(x>y) return ;
	if(x==y)
	{
		if(minn!=1e18&&sum>minn) return ;
		minn=min(minn,sum);
		cnt++;
		return ;
	}
	for(int i=n;i>=x+1;i--)
		if(a[i]-a[x]<=d) dfs(i,sum+1,y);
	return ;
}
void solve_1()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cnt=0;
			minn=1e18;
			dfs(i,0,j);
			if(cnt==2) ans++;
		}
	}
	cout<<ans<<'\n';
	return ;
}
void solve_2()
{
	k=d/k;
	if(k<2||n<k+2)
	{
		cout<<0<<'\n';
		return ;
	}
	ans+=n-2*k+1;
	cout<<ans<<'\n';
	return ;
}
void solve()
{
	bool f1=0;
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==2) k=a[i]-a[i-1];
		if(i>2&&k!=a[i]-a[i-1]) f1=1;
	}
	if(!f1)
	{
		solve_2();
		return ;
	}
	solve_1();
	return ;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
		solve();
	return 0;
}
