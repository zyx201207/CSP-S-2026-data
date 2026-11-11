#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int> 
const int maxn=1e6+20;
int n,d,a[maxn],dist[maxn],cnt[maxn];
bool st[maxn];
vector<int>vec[maxn];
void bfs(int s)
{
	memset(dist,-1,sizeof dist);
	queue<pii>q;
	q.push({s,0});
	cnt[s]++;
	dist[s]=0;
	while(!q.empty())
	{
		auto t=q.front();
		q.pop();
		int u=t.first;
		for(auto v:vec[u])
		{
			if(dist[v]==-1)
			{
				dist[v]=t.second+1;
				cnt[v]++;
				
			}else if(dist[v]==t.second+1)
			{
				cnt[v]++;
			}
			q.push({v,t.second+1});
		}
	}
}
void solve()
{
	int ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=i-1;j>=1;j--)
		{
			if(a[i]-a[j]<=d)
			{
				vec[j].push_back(i);
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<i<<":";
//		for(auto j:vec[i])cout<<j<<" ";
//		cout<<"\n";
//	}
	
	
	for(int i=1;i<=n;i++)
	{
		bfs(i);
		for(int i=1;i<=n;i++)
		{
			if(cnt[i]==2)ans++; 
		}
		for(int i=0;i<=n;i++)
		{
			a[i]=0;
			st[i]=0;
			cnt[i]=0;
			//
		}
	}
	for(int i=0;i<=n;i++)vec[i].clear();
	cout<<ans<<"\n";
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		solve();
		
	}
	return 0;
}
