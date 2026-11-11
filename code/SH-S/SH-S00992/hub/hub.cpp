#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define re(i, n) for(ll i = 1; i <= (n); i++)
#define rr(i, l, r) for(ll i = (l); i <= (r); i++)
#define pb push_back
const ll N = 1e3 + 9, INF = 1e17 + 9;
ll c, t;
ll n, k;
vector<ll> e[N];
bool flag[N]; 
ll col[N], top;
ll ans[N];
void dfs1(ll u, ll fa, ll c) {
	if(col[u]) return ;
	if(!flag[u]) return ;
	col[u] = c;
	for(ll &v : e[u]) {
		if(v == fa) continue;
		dfs1(v, u, c);
	}
}
int main() {
	 freopen("hub.in", "r", stdin);
	 freopen("hub.out", "w", stdout);
	cin>>c>>t;
	if(c > 6) return 0;
	while(t--) {
		cin>>n>>k;
		re(i, n) e[i].clear(); 
		re(i, n - 1) {
			ll u, v; cin>>u>>v;
			e[u].pb(v);
			e[v].pb(u);
		}
		ll minn = INF;
		for(int b = 0; b < (1 << n); b++) {
			ll cnt = 0;
			re(i, n) {
				if(b >> (i - 1) & 1) {
					cnt++;
					flag[i] = 1;
				} else {
					flag[i] = 0;
				}
			}
			if(cnt != k) continue;
			top = 0;
			fill(col + 1, col + n + 1, 0);
			re(i, n) {
				if(!flag[i]) continue;
				if(col[i]) continue;
				dfs1(i, 0, ++top);
			}
//			re(i, n) cout<<flag[i]<<" ";
//			cout<<endl;
			if(top > 2) continue;
			fill(ans + 1, ans + n + 1, INF);
			queue<pair<ll, ll>> q;
			re(i, n) {
				if(!flag[i]) continue;
				q.emplace(i, 0);
				ans[i] = 0;
			}
			while(!q.empty()) {
				ll u = q.front().first, d = q.front().second;
				q.pop();
				for(ll &v : e[u]) {
					if(ans[v] <= d + 1) continue;
					ans[v] = d + 1;
					q.emplace(v, d + 1);
				}
			}
			minn = min(minn, *max_element(ans + 1, ans + n + 1));
//			if(*max_element(ans + 1, ans + n + 1) == 1) {
//				re(i, n) cout<<flag[i]<<" ";
//				cout<<endl;
//				re(i, n) cout<<ans[i]<<" ";
//				cout<<endl; 
//				cout<<top<<endl;
//				cout<<*max_element(ans + 1, ans + n + 1)<<endl;
//			}
		}
		cout<<minn<<endl;
	}
	return 0;
}

