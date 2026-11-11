#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<=b;i++)
#define eb emplace_back
typedef long long ll;
const int N=1e6+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll c,n,d,x[N],ans,dis[N],cnt[N];
vector<int>G[N];
queue<int>q;
void bfs(int s)
{
	For(i,1,n)dis[i]=INT_MAX,cnt[i]=0;
	dis[s]=0;
	cnt[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto v:G[x])
		{
			if(dis[v]>dis[x]+1)
			{
				dis[v]=dis[x]+1;
				q.push(v);
				cnt[v]=cnt[x];
			}
			else if(dis[v]==dis[x]+1)cnt[v]+=cnt[x];
		}
	}
}
void solve()
{
	cin>>n>>d;
	For(i,1,n)cin>>x[i]; 	
	For(i,1,n)G[i].clear();
	For(i,1,n)
	{
		For(j,i+1,n)
		{
			if(x[j]-x[i]<=d)
			{
				G[i].eb(j);
			}
		}
	}
	ans=0;
	For(i,1,n)
	{
		bfs(i);
		For(j,i+1,n)if(cnt[j]==2)ans++;
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cin>>c>>T;
	while(T--)solve();
	return 0;
}


