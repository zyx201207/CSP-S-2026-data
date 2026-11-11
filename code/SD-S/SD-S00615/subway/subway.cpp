#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=550;
const int M=5e5+100;
vector<int> lst[N],g[M];
vector<int> pos[M];
vector<int> t[N];
int k[N];
int mn[N][N];
int n,m,d,q;
int w[M];
void solve(){
	cin>>n>>m>>d>>q;
	for (int i=1;i<=m;++i) cin>>w[i];
	for (int i=1;i<=n;++i){
		cin>>k[i];
		for (int j=1;j<=k[i];++j){
			int a,b;cin>>a>>b;
			lst[i].push_back(a);
			t[i].push_back(b);
			g[a].push_back(i);
			pos[a].push_back(j);
		}
	}
	memset(mn,0x3f,sizeof mn);
	for (int i=1;i<=n;++i){
		 mn[i][i]=0;
	}
	for (int i=1;i<=m;++i){
		for (int j=0;j<g[i].size();++j){
			for (int k=0;k<g[i].size();++k){
				if (j==k) continue;
				int lid=g[i][j];
				int rid=g[i][k];
				if (lid==rid) continue;
				int zbl=pos[i][j]-1;
				int zbr=pos[i][k]-1;
				mn[lid][rid]=min(mn[lid][rid],t[lid][zbl]+t[rid][zbr]);
			}
		}
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			for (int k=1;k<=n;++k){
				mn[i][j]=min(mn[i][j],mn[i][k]+mn[k][j]);
			}
		}
	}
//	for (int i=1;i<=n;++i){
//		for (int j=1;j<=n;++j) cout<<mn[i][j]<<" ";
//		cout<<"\n";
//	}
	while (q--){
		int x,y;cin>>x>>y;
		int ans=1e16,ll,rr;
		int res=w[x]+w[y];
		for (int i=0;i<g[x].size();++i){
			for (int j=0;j<g[y].size();++j){
				int lid=g[x][i];
				int rid=g[y][j];
				int posl=pos[x][i]-1;
				int posr=pos[y][j]-1;
				if (ans>mn[lid][rid]) ans=min(ans,mn[lid][rid]+t[lid][posl]+t[rid][posr]);
			}
		}
		cout<<ans+res<<"\n";
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c;cin>>c;
	solve();
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
简单来说就是m个地铁站 n个线路
可以换乘换线路
代价是换乘的点的t
总代价是当前地点的t+目标地点的t+换乘的代价
每个地铁站最多会被20个路线进过
突破点就在这
盲猜是20(q+n)左右的做法
注意到一个性质
就是每一个路线最多会经过1次
因为他肯定一步到达最优
预处理不太现实
但是每个地铁站最多经过20次有什么用啊？？？
我们先思考d=2的情况
我们先抽象出如何建图
一点是先在每一个点中对其他路线两两连边，w=两者的t相加
但是做法是O(nq)的
如何减去无用状态？？？
哎？我们可以记录出每一个路线与其他路线最短换乘
对的，n只有500，可以n^2记录
每一个点都暴力匹配d 
*/
