#include<bits/stdc++.h>

using namespace std;
#define int long long 
#define ll long long 
#define ull unsigned long long 

/*
n^2 log n 是显然的，具体而言就是你直接枚举起点
然后将相同的 dp 值归为一段，那么每一段就直接二分，
找到前一段的倒数第二个点，然后二分到它最远能到达的位置即可。
常数极小。
如果动态维护这个 dp 值可以均摊吗？
不对呀，维护都是均摊 O(n) 的。
我有一个想法
你直接给它建树，每个节点的 fa 是它可以到的最远的点
现在我们来考虑一个点的贡献
那么我们发现如果一个节点是某个段的结尾，当且仅当起点是它子树内的点
那么考虑它前一个点的贡献不就是简单的吗，直接二分
当然注意特殊情况，如果前一个点是你的儿子，贡献为 0
如果没有第三个点，也是有贡献的
这不就 $O(n\log n)$ 了吗？
重新递推构造我们发现每一层的儿子都是连续的
如果有一层的儿子数量 >2 显然他就有至少 3 种改道方案
=1 就没有改道方案
=2 考虑 只能是编号较小的点下面的所有点改道到 编号较大的点
然后可以和直到上一个 儿子数>=2的点的所有点匹配
*/

const int N=1e6+15;
const int inf=1e9;

int h[N],to[N],ne[N],idx=0;
int siz[N],cnt[N];
int fa[N];
int x[N];
int dep[N],pre[N];
int n,d,ans;

void add(int u,int v)
{
	to[++idx]=v;
	ne[idx]=h[u];
	h[u]=idx;
}

void bfs(int rt)
{
	queue<int> q;
	q.push(rt);
	int len=0;
	while(!q.empty())
	{
		vector<int> p;
		p.clear();
		while(!q.empty()) p.push_back(q.front()),q.pop();
		if(p.size()==1)
		{
			len++;
			int u=p[0];
			if(cnt[u]>=2)
			{
				int minn=inf,cmin=inf;
				for(int i=h[u];i!=-1;i=ne[i])
				{
					int v=to[i];
					if(v==fa[u]) continue;
					if(v<minn) cmin=minn,minn=v;
					else if(v<cmin) cmin=v;
				}
				if(!cnt[minn]) ans=ans+(siz[cmin]-1)*len;
				else ans=ans+cnt[cmin]*len;
				len=0;
			}
		}
		else if(p.size()>=2)
		{
			int minn=inf,maxx=0;
			for(auto &u:p)
			{
				minn=min(minn,u);
				for(int i=h[u];i!=-1;i=ne[i])
				{
					int v=to[i];
					if(v==fa[u]) continue;
					maxx=max(maxx,v);
				}
			}
			int ooo=1;
			for(auto &u:p)
				if((!cnt[u])&&u!=fa[maxx]) ooo++;
			if(fa[maxx]!=minn)
			{
				if(cnt[fa[maxx]]==1)
				{
					if(!cnt[maxx]) ans=ans+(siz[minn]-1)*ooo;
					else ans=ans+(cnt[minn])*ooo;
				}
			}
			len=0;
		}
		for(auto &u:p)
			for(int i=h[u];i!=-1;i=ne[i])
			{
				int v=to[i];
				if(v==fa[u]) continue;
				q.push(v);
			}
	}
}

void pdfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	siz[u]=1;
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int v=to[i];
		if(v==fa) continue;
		pdfs(v,u);
		siz[u]+=siz[v];
		cnt[u]++;
	}
}

void solve()
{
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) h[i]=-1,cnt[i]=0;
	idx=0;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++)
	{
		fa[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
		if(fa[i]!=i) add(fa[i],i),add(i,fa[i]);
//		cerr<<i<<" "<<fa[i]<<endl;
	}
	for(int i=1;i<=n;i++)
		if(fa[i]==i) pdfs(i,0);
	for(int i=1;i<=n;i++)
		if(fa[i]==i) bfs(i);
	cout<<ans<<endl;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T=1;
	cin>>c>>T;
	while(T--)
		solve();
	return 0;
}