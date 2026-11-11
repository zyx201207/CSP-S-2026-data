#include <bits/stdc++.h>
#define pb emplace_back
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using i128 = __int128;
using u128 = unsigned __int128;
using namespace std;
bool ST;

const int N = 1e6 + 5;

int n,k;
vector<int> G[N];

void solve(){
	cin >> n >> k;
	for (int i = 1;i <= n;++i) G[i].clear();
	for (int i = 1;i < n;++i){
		int u,v;cin >> u >> v;
		G[u].pb(v),G[v].pb(u); 
	}
}

bool ED;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	mt19937 rnd(time(0));
	
	int cid,T;cin >> cid >> T;
	while (T--) solve();
	
	cerr << "\ntime used: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000.0 << " ms";
	cerr << "\nmemory used: " << abs(&ST - &ED) / 1024.0 / 1024.0 << " MB";
	return 0; 
}/*
and now I know that sacrifice is the easy path. 
*/
