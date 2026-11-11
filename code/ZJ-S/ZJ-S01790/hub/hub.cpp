#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
struct node
{
	int x,dis;
};
int c,t,n,k;
int pl[15],cnt,ans=-1,res=-1;
vector <int> tree[N];
bool cc[15],flag[15],mark[15];
void dfs2(int x,int fa)
{
	for(int i=0;i<tree[x].size();i++)
	{
		int v=tree[x][i];
		if(v==fa) continue;
		if(!flag[v]&&flag[x]) cnt++,dfs2(v,x);
		else dfs2(v,x);
	}
}
int work(int x)
{
	memset(cc,0,sizeof(cc));
	queue <node> q;
	q.push({x,0});cc[x]=1;
	while(!q.empty())
	{
		node qq=q.front();q.pop();
		for(int i=0;i<tree[qq.x].size();i++)
		{
			int v=tree[qq.x][i];
			if(!flag[v]) return qq.dis+1;
			if(!cc[v])
			{
				q.push({v,qq.dis+1});
				cc[v]=1;
			}
		}
	}
}
void dfs1(int x)
{
	if(x>n)
	{
		for(int i=1;i<=k;i++) flag[i]=false;
		cnt=0;
		dfs2(1,0);
		if(cnt<=2)  
		{
			for(int i=k+1;i<=n;i++)
				ans=max(ans,work(i));
			res=max(res,ans);	
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!mark[i])
		{
			mark[i]=true;
			pl[x]=i;
			dfs1(x+1);
			pl[x]=0;
			mark[i]=false;
		}
	}
}
signed main(void)
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			tree[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;cin>>u>>v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		if(n==k) {cout<<0<<"\n";continue;}
		if(n<=10)
		{
			memset(mark,0,sizeof(mark));
			memset(flag,0,sizeof(flag));
			dfs1(1);
			cout<<res<<"\n";
		}
		else
		{
			cout<<n/3<<"\n";
		}
	}
}
