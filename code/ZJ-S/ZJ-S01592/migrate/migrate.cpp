#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=2e6+10;
int a[N], dis[N], cnt[N], n, d, ans;
bool vis[N];
void bfs(int s)
{
	for(int i=s+1;i<=n;i++) dis[i]=1e18, cnt[i]=0, vis[i]=0;
	dis[s]=0;
	cnt[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=x+1;i<=n;i++)
		{
			if(a[i]-a[x]>d) break;
			if(!vis[i]) vis[i]=1, dis[i]=dis[x]+1, cnt[i]=cnt[x], q.push(i);
			else if(dis[x]+1==dis[i]) cnt[i]++;           
		}
	}
	for(int i=s+1;i<=n;i++) if(cnt[i]==2) ans++;
}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, t;
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c==11||c==12)
		{
			int tmp=a[2]-a[1];
			if(d<2*tmp||n<=3)
			{
				cout<<"0\n";
				continue;
			}
			ans=n-3-2*(d/tmp-2);
			if(ans<0) ans=0;
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++) bfs(i);
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 1
5 6
3 6 9 12 15
*/