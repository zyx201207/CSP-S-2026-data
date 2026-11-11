#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
#define MUBIAO ios_base::sync_with_stdio(0);
#define CESUO cin.tie(0);
#define frein freopen("subway.in","r",stdin);
#define freout freopen("subway.out","w",stdout);
#define mod 998244353
#define inf 1e14
#define pii pair<int,int>
using namespace std;
const int maxn=1e6+10;
const int N=5e2+10;

/*
	注意到 O(nq) 是一个可接受的复杂度
	于是对于询问，我们只需要预处理出每个点到虚点的距离即可
	那么问题转化为如何快速求出每个点到虚点的距离
	显然 O(mnlog n) 没有前途
	应当考虑 d 的用途
	实际上就是在说，每个点的边是很少的
	于是我们可以想到直接从每个点的可达虚点进行转移，这样的复杂度为 O(mnd)
	其实你可以离线，这样需要转移的点就是 O(q) 的，还能做到 O(qnd)
	5e8，不知道可不可做，本地 400ms，可做
	那么问题转化为求出虚点两两之间的距离
	然后容易想到直接建边
	可以做，很能做！
	这样子时间复杂度是 O(nq+nmd+d^2m+n^2log n)
	但是这样空间开不下
	哦哦，我是傻逼啊
	其实你只需要知道虚点的最短路径，然后每次询问枚举两个虚点即可
	这样子的复杂度为 O(qd^2+n^3)
*/

int c,n,m,d,q,w[maxn],k[N],Dis[N][N];

vector<pii> E[N],e[maxn],edge[maxn];

void SolveDis(){
	memset(Dis,0x3f,sizeof(Dis));
	for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size();j++)
			for(int k=0;k<e[i].size();k++)
				Dis[e[i][j].first][e[i][k].first]
				=min(Dis[e[i][j].first][e[i][k].first],e[i][j].second+e[i][k].second);
	}
	for(int i=1;i<=n;i++)Dis[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				Dis[i][j]=min(Dis[i][k]+Dis[k][j],Dis[i][j]);
}

signed main(){
	MUBIAO CESUO
	frein freout
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,u,x;j<=k[i];j++)
			cin>>u>>x,
			E[i].push_back({u,x}),
			e[u].push_back({i,x});
	}
	SolveDis();
	while(q--){
		int x,y,ans=inf; cin>>x>>y;
		for(pii i:e[x])
			for(pii j:e[y])
				ans=min(ans,Dis[i.first][j.first]+i.second+j.second);
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}