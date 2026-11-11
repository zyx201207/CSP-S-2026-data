#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505 , M = 5e5 + 5;
int c , n , m , d , q;
ll dis[N][N] , w[M];
struct node{
	int v;
	ll w;
};
vector<node>l[M];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)cin >> w[i];
	int k , x;
	ll a;
	for(int i = 1;i <= n;i++){
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> x >> a;
			l[x].push_back({i , a});
		}
	}
	memset(dis , 0x3f , sizeof dis);
	for(int i = 1;i <= m;i++){
		for(auto j : l[i]){
			for(auto k : l[i])dis[k.v][j.v] = dis[j.v][k.v] = j.w + k.w;
		}
	}
	for(int i = 1;i <= n;i++)dis[i][i] = 0;
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++)dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
		}
	}
	while(q--){
		int x , y;
		cin >> x >> y;
		ll minn = 2e18;
		for(auto i : l[x]){
			for(auto j : l[y])minn = min(minn , w[x] + i.w + dis[i.v][j.v] + j.w + w[y]);
		}
		cout << minn << '\n';
	}
	return 0;
}
