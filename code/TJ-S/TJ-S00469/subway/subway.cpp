#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3fLL
#define int long long
#define N 505
#define M 500005
using namespace std;
struct node{int first,second;};
int ccc,n,m,ddd,q;
vector <node> e[M];//1~n站台
int zt[N][N],xh[M];//图的链接,消耗地铁站
signed main(){
	#ifndef HONGXIAODOU
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	#endif
	memset(zt,0x3f,sizeof(zt));
	cin >> ccc >> n >> m >> ddd >> q;
	for (int i = 1;i <= m;++i) cin >> xh[i];
	for (int i = 1,k;i <= n;++i){
		cin >> k;
		for (int j = 1,aa,tt;j <= k;++j){
			cin >> aa >> tt;
			e[aa].push_back({i,tt});
		}
	}
	for (int i = 1;i <= n;++i) zt[i][i] = 0;
	//特化floyd
	for (int k = 1;k <= m;++k){
		for (int i = 0;i < e[k].size();++i){
			for (int j = i + 1;j < e[k].size();++j){
				int uu = e[k][i].first;
				int vv = e[k][j].first;
				int ww = e[k][i].second + e[k][j].second;
				zt[vv][uu] = zt[uu][vv] = min(zt[uu][vv],ww);
			}
		}
	}
	for (int k = 1;k <= n;++k){
		for (int i = 1;i <= n;++i){
			for (int j = 1;j <= n;++j){
				zt[i][j] = min(zt[i][k] + zt[k][j],zt[i][j]);
			}
		}
	}
	int aa,bb,res;
	while (q--){
		cin >> aa >> bb;
		res = inf;
		for (int i = 0;i < e[aa].size();++i){
			for (int j = 0,uu,vv,ww;j < e[bb].size();++j){
				uu = e[aa][i].first;
				vv = e[bb][j].first;
				ww = e[aa][i].second + e[bb][j].second;
				res = min(res,ww + zt[uu][vv]);
			}
		}
		cout << res + xh[aa] + xh[bb] << '\n';
	}
return 0;
}
