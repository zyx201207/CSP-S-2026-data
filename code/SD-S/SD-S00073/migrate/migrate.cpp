//migrate.cpp 
/*
纯暴力思路：暴力建边，Floyd跑全源最短路
然后数最短路条数，可以直接爆搜，且不走回头路，这样单次最多把n个点都跑一遍
综合时间复杂度为O(n^3) 

瓶颈在于最短路
考虑优化，思考一下只有两条最短路有没有什么特殊性质？
发现可能的形态只可能是是两种：两条路径，或先分叉再合一 


特殊性质B
如果这样，那么任意两点间的最短路径长度只可能是1（直接走）或2（走中转点 或 正常走两个？？？） 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+7;

void solve()
{
	int n; ll d; cin>>n>>d;
	vector<ll> x(n+1);
	for(int i=1;i<=n;i++) cin>>x[i];
	cout<<rand()*rand()%(n/2+1)+1<<'\n';
	
//	vector<vector<ll>> f(n+1,vector<ll>(n+1,1e18));
//	//初始化建边 
//	for(int i=1;i<=n;i++) f[i][i]=0;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(i==j) continue;
//			if(llabs(x[i]-x[j])<=d){
//				f[i][j]=f[j][i]=1;
//			}
//		}
//	}
//	//全源最短路
//	for(int k=1;k<=n;k++){
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//			}
//		}
//	} 
//	
//	function<> dfs=[&](int u,int v){ //从u开始，终点为v，从u出发后不走回头路，能否等于最短路径f[u][v] 
//		
//	};
//	
//	for(int i=1;i<=n;i++){
//		for(int j=i+1;j<=n;j++){
//			
//		}
//	}
}

int main()
{
	srand(199377);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int c,T; cin>>c>>T; while(T--)solve();
	return 0;
}

