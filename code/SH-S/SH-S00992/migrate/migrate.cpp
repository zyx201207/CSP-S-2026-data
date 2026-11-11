#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define re(i, n) for(ll i = 1; i <= (n); i++)
#define rr(i, l, r) for(ll i = (l); i <= (r); i++)
#define pb push_back
#define cdub cout<<"Debug: "
const ll N = 2e6 + 9, INF = 1e17 + 9;
ll c, t;
ll n, d;
ll x[N]; 
bool flag[N];
ll typ[N];
ll pre[N], suf[N];
ll nxt[N];
vector<ll> e[N];
int main() {
	 freopen("migrate.in", "r", stdin);
	 freopen("migrate.out", "w", stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		re(i, n) cin>>x[i];
		ll r = 1;
		x[0] = -INF;
		x[n + 1] = INF;
		re(i, n) {
			while(r <= n && x[r + 1] <= x[i] + d)
				r++;
			nxt[i] = r;
		}
//		nxt[n] = n + 1;
		re(i, n) {
			if(x[i - 1] + d < nxt[i])
				flag[i] = 1;
			else
				flag[i] = 0;
			if(!flag[i] && flag[i - 1])
				typ[i] = 1;
			else if(!flag[i] && !flag[i - 1])
				typ[i] = -1;
			else
				typ[i] = 0;
		}
//		re(i, n) cout<<nxt[i]<<" ";
//		cout<<endl;
		ll ans = 0;
		re(i, n) {
			ll j = i;
			ll cnt = 0;
			while(nxt[j] != j) {
				j = nxt[j];
				if(cnt == 0) {
					ans += nxt[j - 1] - nxt[j - 2];
//					cdub<<i<<" "<<j<<" "<<nxt[j - 1] - nxt[j - 2]<<endl;
				} 
				if(cnt == 1) {
					ans += nxt[j] - nxt[j - 1];
//					cdub<<i<<" "<<j<<" "<<nxt[j] - nxt[j - 1]<<endl;
				}
				if(typ[j] == 1) cnt++;
				if(typ[j] == -1) break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define re(i, n) for(ll i = 1; i <= (n); i++)
#define rr(i, l, r) for(ll i = (l); i <= (r); i++)
#define pb push_back
#define cdub cout<<"Debug: "
const ll N = 2e6 + 9, INF = 1e17 + 9;
ll c, t;
ll n, d;
ll x[N]; 
bool flag[N];
ll typ[N];
ll pre[N], suf[N];
ll nxt[N];
vector<ll> e[N];
ll ans = 0;
ll dp[N][2];
void dfs(ll u) {
	if(typ[u] == -1) {
		dp[u][0] = dp[u][1] = 0;
		return ;
	}
	if(typ[u] == 0) {
		dp[u][0] = pre[u];
		dp[u][1] = 0;
	} else {
		dp[u][0] = 0;
		dp[u][1] = pre[u];
	}
	for(ll &v : e[u]) {
		dfs(v);
		if(typ[u] == 0) {
			dp[u][0] += dp[v][0];
			dp[u][1] += dp[v][1];
		} else {
			dp[u][1] += dp[v][0];
		}
	}
	ans += dp[u][1] * suf[u];
	if(u > 1)
		ans += dp[u][0] * (nxt[u - 1] - nxt[u - 2]);
}
int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		re(i, n) cin>>x[i];
		x[0] = -INF;
		x[n + 1] = INF;
		ll r = 1;
		re(i, n) {
			while(r <= n && x[r + 1] <= x[i] + d)
				r++;
			nxt[i] = r;
			cdub<<i<<" "<<nxt[i]<<endl;
		}
		re(i, n) {
			if(x[i - 1] + d < nxt[i])
				flag[i] = 1;
			else
				flag[i] = 0;
			if(!flag[i] && flag[i - 1])
				typ[i] = 1;
			else if(!flag[i] && !flag[i - 1])
				typ[i] = -1;
			else
				typ[i] = 0;
		}
		re(i, n) {
			suf[i] = nxt[i] - nxt[i - 1];
		}
		re(i, n) {
			pre[nxt[i]]++;
		}
		re(i, n) {
			cdub<<i<<" "<<pre[i]<<" "<<suf[i]<<" "<<flag[i]<<" "<<typ[i]<<endl;
		}
		re(i, n) e[i].clear();
		re(i, n) {
			e[nxt[i]].pb(i);
		}
		ans = 0;
		dfs(n);
//		re(i, n) {
//			if(typ[i] == 1) 
//				ans += nxt[i] - i;
//		}
		cout<<ans<<endl;
		re(i, n) cdub<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl; 
	}
	return 0;
}
*/ 
