#include<bits/stdc++.h>
using namespace std;
vector<int> tree[1000005];
int a[1000005];
int n,k;
bool st[1000005];
int deep[1000005];
int fa[1000005][21];
int sum[1000005];
int ans=1e9;
set<int> s;
void dfs3(int t,int f)
{
	deep[t]=deep[f]+1;
	for(auto it:tree[t])
	{
		if(it!=f)
		{
			sum[it]=sum[t]+1;
			fa[it][0]=t;
			dfs3(it,t);
		}
	}
}
void init()
{
	for(int j=1;j<=20;j++)
	  for(int i=1;i<=n;i++)
	    fa[i][j]=fa[fa[i][j-1]][j-1];
}
int lca(int x,int y)
{
	if(deep[x]>deep[y]) swap(x,y);
	for(int i=20;i>=0;i--)
	  if(deep[fa[y][i]]>=deep[x]) y=fa[y][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--)
	  if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
void dfs2(int t)
{
	for(auto it:tree[t])
	{
		if(!st[it]&&s.find(it)!=s.end())
		{
			st[it]=true;
			dfs2(it);
		}
	}
}
void dfs1(int t)
{
	if(t>k)
	{
		s.clear();
		for(int i=1;i<=k;i++) s.insert(a[i]);
		int cnt=0;
		memset(st,false,sizeof st);
		for(int i=1;i<=k;i++)
		  if(!st[a[i]])
		  {
		  	cnt++;
		  	st[a[i]]=true;
		  	dfs2(a[i]);
		  }
		if(cnt>2) return ;
		//for(int i=1;i<=k;i++) cout<<a[i]<<" ";
		//cout<<endl;
		int maxV=0;
		for(int i=1;i<=n;i++)
		{
			int minV=1e9;
			if(s.find(i)!=s.end()) minV=0;
			for(int j=1;j<=k;j++)
			  minV=min(minV,sum[i]+sum[a[j]]-2*sum[lca(a[j],i)]);
		//	cout<<minV<<" ";
			maxV=max(maxV,minV);
		}
	//	cout<<endl;
		ans=min(ans,maxV);
		return ;
	}
	for(int i=a[t-1]+1;i<=n;i++)
	{
		a[t]=i;
		dfs1(t+1);
	}
}
void f()
{
	for(int i=1;i<=n;i++) tree[i].clear();
	memset(fa,0,sizeof fa);
	memset(a,0,sizeof a);
	memset(sum,0,sizeof sum);
	memset(deep,0,sizeof deep);
	ans=1e9;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		f();
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		dfs3(1,0);
		init();
		dfs1(1);
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
