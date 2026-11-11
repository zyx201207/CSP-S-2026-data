#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000005;
int n,d;
int a[N];
int dist[5005];
int last[5005];
int cnt[5005];
int ans;
void bfs(int st)
{
	queue<int> q;
	for(int i=1;i<=n;i++) dist[i]=INT_MAX,cnt[i]=last[i]=0;
	q.push(st);
	dist[st]=1;
	cnt[st]=1;
	last[0]=st;
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int v=last[dist[u]-1]+1;a[v]-a[u]<=d&&v<=n;v++)
		{
			if(dist[v]<dist[u]+1) continue;
			last[dist[u]]=max(last[dist[u]],v);
			cnt[v]+=cnt[u];
			if(dist[v]>dist[u]+1) 
			{
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}
	for(int i=st+1;i<=n;i++) ans+=cnt[i]==2;
}
signed main()
{
//	freopen("data.out","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int C,T; cin>>C>>T;
	if(C<=10)
	{
		while(T--)
		{
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			for(int i=1;i<=n;i++) bfs(i);
			cout<<ans<<'\n';
		}
	}
	if(C==11||C==12)
	{
		while(T--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			if(n==1)
			{
				cout<<0<<'\n';
				continue;
			}
			int jump=d/(a[2]-a[1]);
			if(jump<=1)
			{
				cout<<0<<'\n';
				continue;
			}
			cout<<max(n-jump*2+1,0ll)<<'\n';
		}
	}
	return 0;
}

