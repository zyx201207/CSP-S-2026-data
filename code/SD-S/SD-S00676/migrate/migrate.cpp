#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=2e6+7;
ll n,d,a[N];

namespace test1
{	
const int N1=5007;
int dp[N1][N1];
struct edge
{
	int to;
	int nxt;
}e[N1*N1];
int head[N1],tot;
void add(int u,int v)
{
	e[++tot]={v,head[u]};
	head[u]=tot;
} 

ll dis[N1],cnt[N1];
bitset<N1>vis;
using pli=pair<ll,int>;
void dijikstra(int st)
{
	priority_queue<pli,vector<pli>,greater<pli>>q;
	
	
	vis.reset();
	memset(cnt,0,sizeof cnt);
	cnt[st]=1;
	memset(dis,0x3f,sizeof dis);
	dis[st]=0;
	q.push({0,st});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u]=true;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to;
			if(dis[u]+1==dis[v])
				cnt[v]+=cnt[u];
			else if(dis[u]+1<dis[v])		
			{
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				q.push({dis[v],v});
			}

		}
	}
}
void solve()
{	
	tot=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[j]-a[i]<=d)
				add(i,j);
	
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		dijikstra(i);
		for(int j=i+1;j<=n;j++)
			ans+=(cnt[j]==2);
	}
	cout<<ans<<'\n';
	
	for(int i=1;i<=n;i++)
		head[i]=0;
}
}
//namespace test2
//{
//	void solve()
//	{
//		ll ans=0;
//		int delta=a[2]-a[1];
//		int step=d/delta;
//		if(step==0 || step>2)
//		{
//			cout<<"0\n";
//			return;
//		}
////		for(int len=2;len<=n;len++)
////			if(len>step && len/step==1)
////				ans+=n-len;
////		cout<<ans<<'\n';
//		cout<<step<<' '<<n<<'\n';	
//	}	
//};
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int C,T;
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		
//		if(C<=10)
			test1::solve();
//		else if(C<=12)
//			test2::solve();
//      I wonder.
	}
	
	return 0;
}
