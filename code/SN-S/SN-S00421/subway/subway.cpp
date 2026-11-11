#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define endl '\n'
using namespace std;
const int MAXN=505;
const int MAXM=5e5+5;
const long long inf=1e18+3;
int c,n,m,d,q;
int w[MAXM],k[MAXN];

vector<pair<int,int>> a[MAXN],sub[MAXM];
map<int,int> t[MAXN];
long long dis[MAXN][MAXN];

inline void Min(long long &a,const long long b)
{
	a=(b<a)?b:a;
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,x,y;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>x>>y;
			a[i].pb({x,y});
			sub[x].pb({i,y});
		}
		sort(a[i].begin(),a[i].end());
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=(i==j)?0:inf;
	
	for(int ii=1;ii<=n;ii++) for(int jj=ii+1;jj<=n;jj++)
	{
		int i=ii,j=jj;
		if(a[i].size()>a[j].size()) swap(i,j);
		for(auto d:a[i])
		{
			auto it=lower_bound(a[j].begin(),a[j].end(),make_pair(d.fi,0));
			if(it->fi!=d.fi) continue;
			long long now=d.se+it->se;
//			cout<<now<<endl;
			Min(dis[i][j],now);
			Min(dis[j][i],now);
		}
	}
	
//	for(int i=1;i<=n;i++) 
//	{
//		for(int j=i+1;j<=n;j++)
//		cout<<i<<" "<<j<<" "<<dis[i][j]<<endl;
//	}
	
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) if(dis[i][k]<inf) for(int j=1;j<=n;j++) if(dis[k][j]<inf)
	Min(dis[i][j],dis[i][k]+dis[k][j]);
	
	while(q--)
	{
		int x,y; cin>>x>>y;
		long long ans=inf;
		for(auto a:sub[x]) for(auto b:sub[y]) Min(ans,dis[a.fi][b.fi]+a.se+b.se);
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


然后 w 没有用

然后先枚举 k 那么 地铁有 20*20 种选法

等一下 sum_k 真的有 5e5 吗
每个最坏是 n 个啊 难道不是 500*20 吗，用样例验证一下 

呀看错题了 是地铁很少 

重新想
可是说这个最短路没有多源的啊，这个 20 层？的图一定要退化

感觉这个 t 就是这个路径的代价啊
可是我还是不知道这 d 怎么用啊

就是询问有 1e5 所以这个 d 一定是要预处理的 
看看部分分吧

等等 这个 A性质 就是给一个只有 500 条边的图 那怎么做啊

这个就 floyd

看看 B 就是

问你最少换成几次 这个我不会啊

不会是什么线段树优化建图吧，但是还是解决不了问两个点

呀，我好想会了，大概是 对于每个询问 u,v 枚举 u,v 做那个地铁，并加上他上地铁的代价

然后是不是就可以 500^3 之类的，解决的事从 x 地铁到 y 地铁最少需要多少代价

然后 我记 dp_{i,j} 表示从地铁 i 到 地铁 j 的最小代价

dp_{i,j} = min(dp_{i,k} + dp_{k,j} + dis(i,j))
dis(i,j) 表示他们相交的站的 t 之和的最小值

这个怎么算我想想 

主要问题是有可能交集 = m 的个数很多是不是

这个时间复杂度到底是什么（如果暴力枚举交点的话）

大概是 sum_{min(k_i,k_j)} 的 用大样例试试 

看了大样例 1e8 不知道是不是定的
哦哦 如果 m= sqrt(5e5) 试试

每个是 sqrt 的成 500*500 大概 8e8 看看是不是 *** 的尿性

先写吧，边想想有没有优化 哦对了好像是 max 的先写 bitset 吧 

等一下还有问题 怎么 flody 啊 你需要先枚举 k

先处理任意连个的距离 


哎呀时间复杂度不会证刚才写了一个 map的在大样例上表现比我的没有map但是 pair sort的更好我不知道选哪个
 
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int MAXN=505;
const int MAXM=5e5+5;
const long long inf=1e18+3;
int c,n,m,d,q;
int w[MAXM],k[MAXN];

vector<int> a[MAXN];
map<int,int> t[MAXN];
vector<int> sub[MAXM];
long long dis[MAXN][MAXN];

inline void Min(long long &a,const long long b)
{
	a=(b<a)?b:a;
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,x,y;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>x>>y;
			a[i].pb(x);
			sub[x].pb(i);
			t[i][x]=y;
		}
		sort(a[i].begin(),a[i].end());
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=(i==j)?0:inf;
	
	for(int ii=1;ii<=n;ii++) for(int jj=ii+1;jj<=n;jj++)
	{
		int i=ii,j=jj;
		if(a[i].size()>a[j].size()) swap(i,j);
		for(int d:a[i])
		{
			auto it=lower_bound(a[j].begin(),a[j].end(),d);
			if(*it!=d) continue;
			long long now=t[i][d]+t[j][d];
//			cout<<now<<endl;
			Min(dis[i][j],now);
			Min(dis[j][i],now);
		}
	}
	
//	for(int i=1;i<=n;i++) 
//	{
//		for(int j=i+1;j<=n;j++)
//		cout<<i<<" "<<j<<" "<<dis[i][j]<<endl;
//	}
	
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) if(dis[i][k]<inf) for(int j=1;j<=n;j++) if(dis[k][j]<inf)
	Min(dis[i][j],dis[i][k]+dis[k][j]);
	
	while(q--)
	{
		int x,y; cin>>x>>y;
		long long ans=inf;
		for(int a:sub[x]) for(int b:sub[y]) Min(ans,dis[a][b]+t[a][x]+t[b][y]);
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}

 
*/
