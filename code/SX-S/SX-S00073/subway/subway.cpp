#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5,M = 5e2 + 5;
ll c,n,m,d,q,ans;
ll w[N];
vector <ll> a[M],b[M],dist[M];
void dfs(ll k,ll x,ll tt,ll sum){
	if(a[k][x] == tt){
		ans = max(ans,sum);
		return ;
	}
	for(int i = 0;i < a[k].size();i++){
		if(dist[a[k][i]].size() <= 1) continue;
		for(int j = 0;j < dist[a[k][i]].size();j++){
			if(dist[a[k][i]][j] == k) continue;
			dfs(dist[a[k][i]][j],
			binary_search(a[dist[a[k][i]][j]].begin(),a[dist[a[k][i]][j]].end()),
			tt,
			sum + b[dist[a[k]]] + b[dist[a[k][i]]]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> a[j] >> t[j];
			add(i,a[j],t[j]);
			add(a[j],i,t[j]);
		}
	}
	while(q--){
		cin >> x >> y;
		ans = 0;
  		ans += w[x],ans += w[y];
  		sf(x);
  		cout << ans + dist[y] << "\n";
	}
	return 0;
}