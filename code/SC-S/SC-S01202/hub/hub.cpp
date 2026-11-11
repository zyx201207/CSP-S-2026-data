/*
好口口口的树形 DP 啊，但是完全不想碰
打个暴力走人得了，暴力枚举的话复杂度是 O(C(n,k)\times n)

设计一下状态，f_{i,j,k} 到了第 i 个点选了 j 个点已经有 k 个连通块的最小值
这样其实是不太好做的，因为我们不好直接求未选择父亲到选择的儿子的贡献
先写暴力保分 O(2^n\times n^2)，应该能骗 15pts

欸，距离都是 1，那 DP 状态可以设计了，再加一维当前子树上的最小深度选择点即可

或者说二分？然后可以根据什么雷霆证明得到从重心开始放最优？

暴力写挂了cao
忘判连通块个数了
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair< int,int >
#define QWQ return 0;
#define QAQ return

const int N=1e5+10, inf=1e9;

int n, k;
int ans;
int d[N];
bool vis[N], vvis[N];
vector< int > rode[N];

inline void treedfs( int p,int fa )
{
	d[p]=inf;
	for( auto x:rode[p] ) if( x != fa )
		treedfs( x,p ), d[p]=min( d[x]+1,d[p] );
	if( vis[p] ) d[p]=0;
}

inline void treedfs2( int p )
{
	vvis[p]=true;
	for( auto x:rode[p] ) if( vis[x] && !vvis[x] )
		treedfs2( x );
}

inline void clac()
{
	for( int i=1;i<=n;i++ ) vvis[i]=false;
	int tmp=0, cnt=0;
	for( int i=1;i<=n;i++ )
		treedfs( i,i ), tmp=max( tmp,d[i] );
	for( int i=1;i<=n;i++ ) if( vis[i] && !vvis[i] )
		treedfs2( i ), cnt++;
	if( cnt <= 2 ) ans=min( ans,tmp );
}

inline void sovel()
{
	cin>>n>>k;
	for( int i=1;i<=n;i++ ) vis[i]=false, rode[i].clear(); 
	for( int i=1, u, v;i<n;i++ )
		cin>>u>>v,
		rode[u].push_back( v ), rode[v].push_back( u );
	ans=inf;
	for( int state=0;state<( 1<<n );state++ )
	{
		int cnt=0;
		for( int j=0;j<n;j++ ) vis[j+1]=( ( state>>j )&1 ), cnt+=vis[j+1];
		if( cnt == k ) clac();
	}
	cout<<ans<<"\n";
}

int main()
{
	freopen( "hub.in","r",stdin );
	freopen( "hub.out","w",stdout );
	ios::sync_with_stdio( false );
	cin.tie( nullptr ); cout.tie( nullptr );
	int c, t;
	for( cin>>c>>t;t;t-- ) sovel();
	QWQ
}