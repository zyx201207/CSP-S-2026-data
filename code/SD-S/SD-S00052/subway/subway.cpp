#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c, n, m, d, q, x, y, aa, mm, mmm, ans;
ll w[555555], k[555], jl[555][555];
map <ll, ll> t[555555];
vector <ll> a[555555];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (ll i = 0 ; i < m ; i++){
		cin >> w[i];
	}
	for (ll i = 0 ; i < n ; i++){
		cin >> k[i];
		for (ll j = 0 ; j < k[i] ; j++){
			cin >> aa;
			aa--;
			cin >> t[aa][i];
			a[aa].push_back(i);
		}
	}
	for (ll i = 0 ; i < n ; i++){
		for (ll j = 0 ; j < n ; j++){
			jl[i][j] = 1e18;
		}
	}
	for (ll i = 0 ; i < n ; i++){
		jl[i][i] = 0;
	}
	for (ll i = 0 ; i < m ; i++){
		mm = a[i].size();
		for (ll j = 0 ; j < mm ; j++){
			for (ll k = j + 1 ; k < mm ; k++){
				jl[a[i][j]][a[i][k]] = min(jl[a[i][j]][a[i][k]], t[i][a[i][j]] + t[i][a[i][k]]);
				jl[a[i][k]][a[i][j]] = min(jl[a[i][j]][a[i][k]], jl[a[i][k]][a[i][j]]);
				jl[a[i][j]][a[i][k]] = min(jl[a[i][j]][a[i][k]], jl[a[i][k]][a[i][j]]);
			}
		}
	}
	for (ll i = 0 ; i < n ; i++){
		for (ll k = 0 ; k < n ; k++){
			for (ll j = i + 1 ; j < n ; j++){
				jl[i][j] = min(jl[i][j], jl[i][k] + jl[k][j]);
			}
		}
	}
	for (ll i = 0 ; i < q ; i++){
		cin >> x >> y;
		x--, y--;
		if (x > y){
			m = x;
			x = y;
			y = m;
		}
		mm = a[x].size(), mmm = a[y].size(), ans = 1e18;
		for (ll j = 0 ; j < mm ; j++){
			for (ll k = 0 ; k < mmm ; k++){
				ans = min(ans, jl[a[x][j]][a[y][k]] + t[x][a[x][j]] + t[y][a[y][k]]);
			}
		}
		printf("%lld\n", ans + w[x] + w[y]);
	}
	return 0;
}
