#include<bits/stdc++.h>
using namespace std;
const int MAXN=501,MAXK=5e5+5;
const long long INF=1e18;
int c,n,m,d,q;
struct node{
	int u;
	long long d;
};
vector<node> v[MAXK];//记录站台与地铁站之间的联系 
long long w[MAXK],a[MAXK],b[MAXK];
long long f[MAXN][MAXN];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	int K;
	long long a,b;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) f[i][j]=f[j][i]=INF;
	int sumk=0;
	for(int i=1;i<=n;i++){
		cin>>K;
		sumk+=K;
		for(int j=1;j<=K;j++){
			cin>>a>>b;
			for(node k:v[a]){
				f[k.u][i]=f[i][k.u]=min(f[k.u][i],k.d+b);
			}
			v[a].push_back({i,b});
		}//建图，把“路线”连起来 
	}
//	for(int i=1;i<=sumk;i++){
//		cout<<i<<':';
//		for(node j:v[i])
//			cout<<j.u<<' ';
//		cout<<"\n"; 
//	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
//				printf("(%lld,%d,%d)",f[i][j],i,j);
			}
//		cout<<"\n";
	}//暴力跑 Floyd
	long long ans;
	while(q--){
		cin>>a>>b;
		ans=INF; 
		for(node i:v[a])
			for(node j:v[b]){
				ans=min(ans,f[i.u][j.u]+i.d+j.d);
//				printf("[%d,%d,%lld]",i.u,j.u,f[i.u][j.u]+i.d+j.d);
			}
		ans+=w[a]+w[b]; 
		cout<<ans<<"\n";
	}
	return 0;
}
//求最小总步行时间 
/*
题意复述：地铁站可以换乘，
由线路 i 换乘到另一条线路 j 会花费 t[i]+t[j]（在同一个地铁口）
而无向图保证连通
那么只需要考虑换乘花费最小后，
再记得加上 w[x]+w[y]，由地铁口到站厅的时间

Subtask1:
暴力建图，把站厅与站厅连起来，直接跑 Dijkstra 就是暴力分 44pts 

Subtask2:想冲正解怎么办 
但是观察一下，其实这个 n<=500 是巨小的 ， 
考虑说以“路线”建一个超大的点，然后直接把路线这个点给连起来
省去中间的地铁站
跑一遍 Floyd，去看两个路线之间的最短路 
如果两者本就在同一路线下，没什么好说的，直接t[i]+t[j]
如果不在，那么去暴力枚举他们的父亲节点（路线）, 然后 f[route1][route2]+t[i]+t[j] 取 min 即可 
*/ 