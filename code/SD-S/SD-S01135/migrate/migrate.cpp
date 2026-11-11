#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define lowbit(x) (x&-x)
#define PII pair<int,int>
#define P(x,y) make_pair(x,y)
#define c(x) cout<<#x<<"="<<x<<endl;
using namespace std;
const int inf=1e9;
const int N=5010;
int n,d;
int x[N];
vector<int> q[N];
int dist[N],cnt[N];
bool st[N];
void dijkstra(int s)
{
	memset(dist,0x3f,sizeof dist);
	memset(st,0,sizeof st);
	memset(cnt,0,sizeof cnt);
	dist[s]=0;
	cnt[s]=1;
	queue<int> q1;
	q1.push(s);
	while(q1.size())
	{
		auto to=q1.front();
		q1.pop();
		if(st[to]) continue;
		st[to]=1;
		for(auto t:q[to])
		{
			if(dist[t]==dist[to]+1)
			{
				cnt[t]+=cnt[to];
			}
			if(dist[t]>dist[to]+1)
			{
				cnt[t]=cnt[to];
				dist[t]=dist[to]+1;
				q1.push(t);
			}
		}
	}
}
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];	
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(abs(x[j]-x[i])<=d)
			{
				q[i].push_back(j);
				q[j].push_back(i);
			} 	
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		dijkstra(i);
		for(int j=i+1;j<=n;j++)
		{
			if(cnt[j]==2) ans++;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	{
		q[i].clear();
	}
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}


