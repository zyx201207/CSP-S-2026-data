#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
struct node{
	ll pos,x;
};
ll n,m,d,T;
ll G[505][505],w[500005];
vector<node> L[500005];

void floyd(){
	for(int x = 1;x <= n;x++){
		for(int s = 1;s <= n;s++){
			for(int e = 1;e <= n;e++){
				G[s][e] = min(G[s][e],G[s][x] + G[x][e]);
			}
		}
	}
	return ;
}

void work(){
	ll s,e;
	cin >> s >> e;
	ll ans = INF;
	for(int i = 0;i < L[s].size();i++){
		for(int j = 0;j < L[e].size();j++){
			ans = min(ans,L[s][i].x + G[L[s][i].pos][L[e][j].pos] + L[e][j].x);
		}
	}
	cout << ans + w[s] + w[e] << "\n";
	return ;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll id,T;
	cin >> id >> n >> m >> d >> T;
	for(int i = 0;i <= n + 1;i++) for(int j = 0;j <= n + 1;j++) G[i][j] = (i == j ? 0ll:INF);
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	} 
	for(int i = 1;i <= n;i++){
		ll k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			ll pos,t;
			cin >> pos >> t;
			L[pos].push_back({i,t});
		}
	} 
	for(int i = 1;i <= m;i++){
		for(int j = 0;j < L[i].size();j++){
			for(int k = 0;k < L[i].size();k++){
				G[L[i][j].pos][L[i][k].pos] = min(G[L[i][j].pos][L[i][k].pos],L[i][j].x + L[i][k].x);
			}
		}
	}
	floyd();
	while(T--) work();
	return 0;
}
