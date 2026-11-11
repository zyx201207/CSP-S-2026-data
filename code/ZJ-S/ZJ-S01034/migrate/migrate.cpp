//- Message -
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,t;
int n,d;
int x[N];
//int cnt[N];
int ans;
int ed;
int st;
int qwq;
int minn;
void dfs(int y,int s)
{
	if(s>minn)
	{
		return;
	}
	if(y==ed&&s==minn)
	{
		qwq++;
		return;
	}
	for(int i=y+1;i<=ed;i++)
	{
		if(x[y]+d>=x[i])
		{
			dfs(i,s+1);
		}
	}
}
void qnq(int y,int s)
{
	if(s>minn)
	{
		return;
	}
	if(y==ed)
	{
		minn=min(minn,s);
		return;
	}
	for(int i=y+1;i<=ed;i++)
	{
		if(x[y]+d>=x[i])
		{
			qnq(i,s+1);
		}
	}
}
void solve()
{
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			minn=1e18;
			qwq=0;
			st=i;
			ed=j;
			qnq(i,0);
			dfs(i,0);
			if(qwq==2)
			{
				ans++;
			}
//			cout<<minn<<"\n";
//			cout<<i<<' '<<j<<' '<<ans<<"\n";
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
//freopen("migrate.out","r",stdin);
//freopen("migrate.in","w",stdout);
//648647291436