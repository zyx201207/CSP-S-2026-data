/*
Just Sayori
时间也差不多了，果然还是无力回天吗，问题可能在于花了大量的时间在 T4 的甲酸，不过谁看到几乎做完的做法不会心动呢
还是自己太菜了吧，活该一辈子顶着一个蓝钩，最后一次去搏得金钩的机会也没有了啊
也没有什么别的能说了，接下来就是 NOIP，也是我人生中最后一次 OI 比赛了，我觉得我应该活不到 NOIP 之后
不管这套题是难是易我也用尽了全力，不过还是有很大遗憾吧，再多给我一些时间的话……
无论如何，去年那个颤颤巍巍走进机房的少年也应该准备好迎来好结局，无论是 HE 还是 BE
OE 是不可能 OE 的，这是现实，你不会失去观看他人继续的生活的权利。
有点忘记的一句话：
我将沿着这条路继续走下去，现在是，未来也是，永远不会后悔！	——上条当麻《魔法禁书目录》旧约四
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<vector>
#include<random>
#include<set>
#define ll long long
#define ull unsigned long long
#define gr getchar
#define pr putchar
#define N 500005
#define M 1000000007
//#define M 998244353
//#define M 0x3f3f3f3f3f3f3f3f
#define for1(i,a,b) for(auto i=(a);i<=(b);i++)
#define for2(i,a,b) for(auto i=(a);i>=(b);i--)
using namespace std;
inline ll read()
{
	ll x=0,f=1;
	char ch=gr();
	while (ch<'0' || ch>'9') ch=='-'?f=-1,ch=gr():ch=gr();
	while (ch>='0' && ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=gr();
	return x*f;
}
inline int add(int a,int b,const int mod=M){return (a+=b)>=mod?a-mod:a;}
inline int del(int a,int b,const int mod=M){return (a-=b)<0?a+mod:a;}
template<typename T> inline bool chkmin(T &a,T b){return a>b?a=b,1:0;}
template<typename T> inline bool chkmax(T &a,T b){return a<b?a=b,1:0;}
int n,k,u,v,l,r,w,ans,cnt;
int df[N],fa[N],mx[N],la[N],dep[N],sz[N];
bool vs[N],vs2[N];
int mn[22][N];
vector<int> ve;
vector<int> e[N];
inline void tdd(int u,int v)
{
	e[u].emplace_back(v),e[v].emplace_back(u);
}
void dfs1(int u,int f)
{
	fa[u]=mn[0][df[u]=++cnt]=f,mx[u]=dep[u]=dep[f]+1,sz[u]=1;
	for (auto &v:e[u])
	{
		if (v==f) continue;
		dfs1(v,u),sz[u]+=sz[v],chkmax(mx[u],mx[v]);
	}
}
void dfs(int u,int f,int d)
{
	if (vs[u]) chkmin(w,d);
	for (auto &v:e[u])
	{
		if (v==f) continue;
		dfs(v,u,d+1);
	}
}
void dfs2(int u,int f)
{
	vs2[u]=1;
	for (auto &v:e[u])
	{
		if (v==f || !vs[v]) continue;
		dfs2(v,u);
	}
}
inline int get(int u,int v)
{
	return df[u]<df[v]?u:v;
}
inline int get_lca(int u,int v,int k=0)
{
	if (u==v) return u;
	if ((u=df[u])>(v=df[v])) swap(u,v);
	return k=__lg(v-u++),get(mn[k][u],mn[k][v-(1<<k)+1]);
}
#define mid ((l+r)>>1)
void work()
{
	n=read(),k=read(),cnt=0,ans=M;
	for1 (i,1,n-1) u=read(),v=read(),tdd(u,v);
	if (n==k)
	{
		for1 (i,1,n) e[i].clear();
		return cout<<0<<"\n",void();
	}
	if (n<=10)
	{
		for1 (s,0,(1<<n)-1)
			if (__builtin_popcount(s)==k)
			{
				int nm=0,sm=0;
				for1 (i,1,n) vs[i]=vs2[i]=0;
				for1 (i,1,n)
					if (s>>(i-1)&1)
						vs[i]=1;
				for1 (i,1,n)
					if (vs[i] && !vs2[i])
						dfs2(i,0),nm++;
				if (nm>=3) continue;
				for1 (i,1,n)
					if (!vs[i])
					{
						w=M;dfs(i,0,0);
						chkmax(sm,w);
					}
				chkmin(ans,sm);
			}
		cout<<ans<<"\n";
		for1 (i,1,n) e[i].clear();
		return;
	}
	if (k==2)
	{
		for1 (i,1,n)
		{
			cnt=0,dfs1(i,0);
			for1 (i,1,__lg(n))
			for1 (j,1,n-(1<<i)+1)
			mn[i][j]=get(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
			for1 (j,i+1,n)
			{
				int sm=(dep[i]+dep[j]-2*dep[get_lca(i,j)])/2;
				for1 (k,1,n)
					if (k^i && k^j)
						chkmax(sm,min(dep[i]+dep[k]-2*dep[get_lca(i,k)],dep[j]+dep[k]-2*dep[get_lca(j,k)]));
				chkmin(ans,sm);
			}
		}
		for1 (i,1,n) e[i].clear();
		return cout<<ans<<"\n",void();
	}
	for1 (i,1,n) e[i].clear();
	
	
}
int main()
{
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),t=read();
	while (t--) work();
	t=c;
	return 0;
}
/*
怎么三道图论，让 loli 控爽到了
感觉比 T3 更可做吧，我们可以二分答案，然后贪心地选择点，那么就可以知道哪些点是必选的
然后剩下的点要把它们连成两个连通块……这个怎么做？
一个是明显好做的，但是问题在于可以分成两个那么我们按 dfn 序分成两部分，这样应该是最优的，
然后我们可以扫一遍分界点，然后用 set 维护，可以直接维护虚树的边数，再加一就是点数
那么可以做到两只老哥，应该能拿不少分啊
坏了，好像不太对，可能我们不是卡着匹配反而要更优一些啊
那么怎么做？
二分答案应该有道理，问题在于贪心
那么改成 dp 呢？
设 f[i][j][k] 为第 i 个点，已经用了 j 个人，上一次选的深度是 k，是否分成了两个连通块
也不好做啊，死马当活马医，我们把贪心改改得了
我们先贪心取最少的点，然后再能删点就删点
*/