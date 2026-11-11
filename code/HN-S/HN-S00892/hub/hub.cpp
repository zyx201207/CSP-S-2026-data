#include<bits/stdc++.h>
typedef int int32;
#define int long long
using namespace std;
/*
作者: HN-S00892 wbw_121124(luogu uid 792595)
17:51 开始写hub暴力
17:57 hyw的t2题面修正
I hate little w *2
```bash
$ type printf
printf is a shell builtin # builtin不会写
$ type l ls ll la
l 是“ls -CF”的别名
ls 是“ls --color=auto”的别名
ll 是“ls -alF”的别名
la 是“ls -A”的别名
```
*/
const int N = 1e6 + 5;
int c,t,n,m,ans=LLONG_MAX,dis[N],maxi;
vector<int>nbr[N];
bitset<N>vis;
queue<int>q;
void dfs(int x,int fa)
{
	q.push(x);
	dis[x]=vis[x]=false;
	for(auto&nxt:nbr[x])
		if(nxt!=fa&&vis[nxt])
			dfs(nxt,x);
	return;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		ans=LLONG_MAX>>2;
		for(int i=1;i<=n;i++)
			nbr[i].clear();
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			nbr[x].push_back(y);
			nbr[y].push_back(x);
		}
		for(int i=1;i<(1ll<<n);i++)
			if(__builtin_popcount(i)==m)
			{
				maxi=0;
				q=queue<int>();
				for(int j=0;j<n;j++)
					vis[j+1]=(i>>j)&1,dis[j+1]=n+1;
				int cnt=0;
				for(int j=1;j<=n;j++)
					if(vis[j])
					{
						dfs(j,0);
						cnt++;
					}
				while(!q.empty())
				{
					int x=q.front();
					q.pop();
					maxi=dis[x];
					for(auto&nxt:nbr[x])
						if(dis[nxt]>dis[x]+1)
						{
							dis[nxt]=dis[x]+1;
							q.push(nxt);
						}
				}
				if(cnt<=2)
					ans=min(ans,maxi);
			}
		cout<<ans<<'\n';
	}
	return 0;
}