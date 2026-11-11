#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+10;
int c,t,n,k,dis[maxn],d[maxn],awa=1e17;
vector<int> e[maxn];
bool f[maxn],book[maxn],book1[maxn];
void dfs1(int x)
{
	book[x]=1;
	for(int y:e[x])
		if(!book[y]&&f[y])dfs1(y);
}
void bfs()
{
	for(int i=1;i<=n;i++)dis[i]=1e17,book1[i]=0;
	queue<int> q;
	while(q.size())q.pop();
	for(int i=1;i<=n;i++)if(f[i])
	{
		q.push(i);
		book1[i]=1,dis[i]=0;
	}
	while(q.size())
	{
		int y=q.front();
		q.pop();
		for(int z:e[y])
		{
			if(book1[z])continue;
			book1[z]=1;
			dis[z]=dis[y]+1;
			q.push(z);
		}
	}
}
void dfs(int depth,int lst)
{
	if(depth>k)
	{
		for(int i=1;i<=n;i++)d[i]=1e17;
		for(int i=1;i<=n;i++)book[i]=0;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]||!book[i])dfs1(i),cnt++;
			if(cnt!=2)return ;
		}
		bfs();
		for(int j=1;j<=n;j++)
			if(!f[j])
				d[j]=min(d[j],dis[j]);
		int ans=0;
		for(int i=1;i<=n;i++)if(!f[i])ans=max(ans,d[i]);
		awa=min(ans,awa);
		return ;
	}
	for(int i=lst+1;i<=n-k+depth;i++)
	{
		f[i]=1;
		dfs(depth+1,i);
		f[i]=0;
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		for(int i=1;i<=n;i++)e[i].clear();
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			int x,y;
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		dfs(1,0);
		cout<<awa<<endl;
	}
	return 0;
}
