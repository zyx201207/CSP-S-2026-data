/*
依旧注意到 n 和 d 都很小
猜 CCF 又考一次状压+神笔算法
能不能跑个多源最短路直接走了？

既然喜欢“站口”“站厅”“站台”的叫，不如我直接把每个点拆成 3 个点
因为存在一个“每条路径最大经过数量”的限制，进一步说即使连边也不会爆 siz
那么这真的不是多源最短路吗？

看了样例解释，发现这不就是拆点板子吗，西西弗竟然这么良心，T2 放这个
其实给这个 d 是个废话吧
对于每个点我们至多拆成 23 个点，后面的表示在那条路线上，但是这个是 1e8 的量级

那么考虑对路线去建立“超级源点”
将每条路线也看作“上车”和“下车”两个点，这样我们就可以 台(边权t)->上车点(边权0)->下车点(边权0)->其他台
点的数量是：n*3+m*2，因为每个路线至多连 d 个站台，所以理论上 m 最大是 n*d = 1e4，点数还是爆炸了
好吧 CCF 没有良心发现
其实根本不需要，我们们容易想到：在一条线路上不会跳多次，至多一次
这样我们就可以不需要多连边，直接连到站厅上就行

这样我们其实连“站台”都不需要拆点出来了
并且我们发现第一个点也是浪费的，点的数量降到 O(n)
好的 CCF 就是良心发现了

不敢写 SPFA 好烦
为什么挂了好烦
怎么变量名写混了

大阳历到了 5 就挂了，为什么呢(是不是边数太多了)

我是唐比吧，这个直接 Floyed 不是更好吗

依旧读错题 play

路线数很少可以启发什么，按路线分类
这样我们先考虑一下把每个路线缩成一个点操作(在图形上看成一条线)，这样同时处于多路线的点就是线的交点
还是不太行的样子，cao怎么又把题读错了

不妨先回去看一下我原本那份代码的瓶颈，或者用这个类暴力找下规律
oh，那么对于我们期望走到另一个已连通路线上，要么直接走，要么至多转换一次到达
那么我们是不是可以处理这个，而且我们考虑的处理是“走到某个线上”，那我们开始的时候枚举一下第一步上那个线，后面就可以暴力了
具体就是找到最小的 t[i1][j]+t[i2][j]，直到到了最后一个点特别处理即可，这样我们就做到了在小范围上的最短路查询
那么我们对这个跑个 floyed 就行了吗 ？ 

先把后面暴力拼了在凹这个题

1h 能做到吗
首先我们现在已经做到了求转换路线的最小代价，但是这个是不一定正确的
因为我们会发现“找到最小的 t[i1][j]+t[i2][j]”，若其本身就是这个最小值，我们会多加一个 t[i1][j]，判断减去即可
那么如何计算最终答案，我们依旧发现如果对于终点，他也是最优选择，我们也会多一次计算 t[i2][j]，也可以减去
但是减去的话就会破坏我们维护的最短路，这个如何解决？
发现边权只减不增，那我们分两次维护新的三角不等式即可，这样的复杂度应该是一个 O(2n)
那么总的复杂度预期是 O(qdn) 的查询了，应该能过把
但是这样预处理的复杂度是一个 O(d^2m)，要是少爷机开心就可以过
球球你了 CCF 的机子

cao，好像炸空间了
完了，好像正确性也死了，呜呜呜
留个备份比赛结束后再想想把

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair< int,int >
#define QWQ return 0;
#define QAQ return
#define pli pair< ll,int >

const int N=5e4+10, M=5e2+10;
const ll inf=1e18;

int w[N], siz[N];
int t[N][M], a[N][M];
ll pre[2][M][M];
ll f[M][M];

inline void upd( int n,int i )
{
	for( int k=1;k<=n;k++ ) for( int j=1;j<=n;j++ )
		f[i][j]=min( f[i][j],f[i][k]+f[k][j] ), f[j][i]=f[i][j];
}

int main()
{
	freopen( "subway1.in","r",stdin );
	freopen( "txt.out","w",stdout );
	ios::sync_with_stdio( false );
	cin.tie( nullptr ); cout.tie( nullptr );
	int c, n, m, d, q;
	cin>>c>>m>>n>>d>>q;
	for( int i=1;i<=n;i++ ) cin>>w[i];
	for( int i=1;i<=n;i++ )
	{
		for( int j=1;j<=n;j++ ) f[i][j]=inf;
		f[i][i]=0;
	}
	for( int i=1, k;i<=m;i++ )
	{
		cin>>k;
		for( int j=1, x, tim;j<=k;j++ )
			cin>>x>>tim,
			siz[x]++, t[x][siz[x]]=tim, a[x][siz[x]]=i;
	}
	for( int i=1;i<=n;i++ )
	{
		for( int j=1;j<=siz[i];j++ ) for( int k=1;k<=siz[i];k++ )
			f[a[i][j]][a[i][k]]=min( f[a[i][j]][a[i][k]],0ll+t[i][j]+t[i][k] );
	}
	for( int k=1;k<=m;k++ ) for( int i=1;i<=m;i++ ) for( int j=1;j<=m;j++ )
		f[i][j]=min( f[i][j],f[i][k]+f[k][j] );
	for( int i=1, x, y;i<=q;i++ )
	{
		cin>>x>>y;
		
		for( int j=1;j<=siz[x];j++ ) for( int k=1;k<=siz[x];k++ )
			pre[0][j][k]=f[a[x][j]][a[x][k]],
			f[a[x][j]][a[x][k]]=min( f[a[x][j]][a[x][k]],0ll+t[i][k] );
		upd( m,x );
		for( int j=1;j<=siz[y];j++ ) for( int k=1;k<=siz[y];k++ )
			pre[1][j][k]=f[a[y][j]][a[y][k]],
			f[a[y][j]][a[y][k]]=min( f[a[y][j]][a[y][k]],0ll+t[y][j] );
		upd( m,y );
		
		ll ans=inf;
		for( int j=1;j<=siz[x];j++ ) for( int k=1;k<=siz[y];k++ )
			ans=min( ans,f[a[x][j]][a[y][k]]+t[x][j]+t[y][k] );
		cout<<ans+w[x]+w[y]<<"\n";
		
		for( int j=1;j<=siz[x];j++ ) for( int k=1;k<=siz[x];k++ )
			f[a[x][j]][a[x][k]]=pre[0][j][k];
		upd( m,x );
		for( int j=1;j<=siz[y];j++ ) for( int k=1;k<=siz[y];k++ )
			f[a[y][j]][a[y][k]]=pre[1][j][k];
		upd( m,y );
	}
	QWQ
}

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair< int,int >
#define QWQ return 0;
#define QAQ return
#define pli pair< ll,int >

const int N=5e2+10;

int w[N], a[N], t[N];
ll dis[N][N];
vector< pii > rode[N];

inline void Dijistra( int idx )
{
	memset( dis[idx],0x3f,sizeof dis[idx] );
	priority_queue< pli,vector< pli >,greater< pli > > pq;
	dis[idx][idx]=0; pq.push( { 0,idx } );
	while( !pq.empty() )
	{
		auto tmp1=pq.top();
		pq.pop();
		ll  d=tmp1.first;
		int p=tmp1.second; 
		if( dis[idx][p] > d ) continue;
		for( auto tmp2:rode[p] )
		{
			int x=tmp2.first, w=tmp2.second;
			if( dis[idx][x] > dis[idx][p]+w )
			dis[idx][x]=dis[idx][p]+w, pq.push( { dis[idx][x],x } );
		}
	}
}

int main()
{
	freopen( "subway.in","r",stdin );
	freopen( "subway.out","w",stdout );
	ios::sync_with_stdio( false );
	cin.tie( nullptr ); cout.tie( nullptr );
	int c, n, m, d, q;
	cin>>c>>m>>n>>d>>q;
	for( int i=1;i<=n;i++ ) cin>>w[i];
	for( int i=1, k;i<=m;i++ )
	{
		cin>>k;
		for( int j=1;j<=k;j++ ) cin>>a[j]>>t[j];
		for( int j=1;j<=k;j++ ) for( int l=1;l<=k;l++ ) if( j != l )
			rode[a[j]].push_back( { a[l],t[j]+t[l] } );
	}
	for( int i=1;i<=n;i++ ) Dijistra( i );
	for( int i=1, x, y;i<=q;i++ )
		cin>>x>>y, cout<<dis[x][y]+w[x]+w[y]<<"\n";
	QWQ
}