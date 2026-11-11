#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<iomanip>
#include<vector>
#include<bitset>
#include<map>
#include<set>
#include<climits>
#include<cmath>
#include<random>
using namespace std;
bool beginmem;
//clock_t begintim;
#define N 505
#define M 500005
#define inf 1000000000000000000ll
#define ll long long
namespace ElEp{
	int c,n,m,d,q,w[M];
	ll dist[N][N];
	vector<pair<int,int>> met[M];
	void __init__(){
		return ;
	}
	void work(){
		cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;++i) cin>>w[i];
		for(int i=1,k;i<=n;++i){
			cin>>k;
			while(k--){
				int a,t;
				cin>>a>>t;
				met[a].emplace_back(i,t);
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dist[i][j] = inf;
			}
			dist[i][i] = 0;
		}
		for(int i=1;i<=m;++i){
			for(int j=0;j<(int)met[i].size();++j){
				for(int k=j+1;k<(int)met[i].size();++k){
					dist[met[i][j].first][met[i][k].first] = min(dist[met[i][j].first][met[i][k].first],1ll*met[i][j].second+met[i][k].second);
					dist[met[i][k].first][met[i][j].first] = min(dist[met[i][k].first][met[i][j].first],1ll*met[i][j].second+met[i][k].second);
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				for(int k=1;k<=n;++k){
					if(dist[i][j]>dist[i][k]+dist[k][j]) dist[i][j] = dist[i][k]+dist[k][j];
				}
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			ll ans = inf;
			for(int i=0;i<(int)met[x].size();++i){
				for(int j=0;j<(int)met[y].size();++j){
					ans = min(ans,met[x][i].second+met[y][j].second+dist[met[x][i].first][met[y][j].first]);
				}
			}
			cout<<ans+w[x]+w[y]<<'\n';
		}
		return ;
	}
}
bool endmem;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cout<<fixed<<setprecision(5);
	cerr<<fixed<<setprecision(5);
	int T = 1;
//	cin>>T;
//	begintim = clock();
	ElEp::__init__();
	while(T--) ElEp::work();
//	cerr<<"Time used: "<<(clock()-begintim)<<" ms.\n";
//	cerr<<"Memory used: "<<abs(&endmem-&beginmem)/1048576.<<" MB.\n";
	return 0;
}
/*
author: Ethereal_loss & Eternal_poem
created: 2026/10/31 14:52:50
exp: 100
发现铁路非常少
也就是我们可以求出两个铁路之间需要花费多少时间才能够互相到达
然后我们枚举入的铁路和出的铁路即可 
复杂度 O(d^2(m+q)+n^3)
TODO: 正确性检查
DONE: 复杂度检查 
*/

