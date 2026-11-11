#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll c, n, t, d;
vector <ll> x;

ll lowbit(ll x){
	return x & (-x);
}

ll countbit(ll x){
	ll cnt = 0, a = x;
	while(a){
		a -= lowbit(a);
		cnt ++;
	}
	return cnt;
}

int log_lowbit(ll x){
	for(int i = 0; i < 64; i ++){
		if((lowbit(x) >> i) & 1) return i;
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t --){
		cin >> n >> d;
		for(int i = 0; i < n; i ++){
			ll x1;
			cin >> x1;
			x.push_back(x1);
		}
		// Subtask 1-2: N <= 9.
		//if(0 <= c && c <= 2){
			ll ans = 0;
			ll dist[10009] = {0};
			ll minn = 10000;
			for(ll u = 0; u < n - 3; u ++){
				for(ll v = u + 3; v < n; v ++){
					for(ll x1 = 0; x1 < (1 << (v - u - 1)); x1 ++){
						bool ok = true;
						ll val = x1, length = 0;
						int last = u;
						while(val){
							//cout << last + 1 << ' ';
							int is = log_lowbit(val) + u + 1;
							if(x[is] - x[last] > d){
								ok = false;
								break;
							}
							val -= lowbit(val);
							last = is;
						}
						if(x[v] - x[last] > d) ok = false;
						//cout << v + 1 << ' ' << x1 << ' ' << length << endl;
						if(ok){
							length = countbit(x1) + 1;
							if(length < minn) minn = length;
							dist[length] ++;
						}
					}
					if(dist[minn] >= 2) ans += (dist[minn] * dist[minn] - dist[minn]) / 2;
				}
			}
			cout << ans << endl;
		//}
	}
	
	return 0;
}

