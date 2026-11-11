#include <bits/stdc++.h>

using namespace std;

#define int long long
//  注意多测要清空！ 
constexpr int N = 2e6 + 5;

int n,a[N],nxt[N],pre[N],c,t,d,tmp[N],cnt = 0;
bool id[N];
inline void solve(){
	std::cin >> n >> d;
	++ cnt;
	// init
//	if(cnt <= 8){
//		for(int i =1; i <= n;++ i) std::cin  >> a[i]; return;
//	}
	for(int i = 1; i <= n; ++ i){
		std::cin >> a[i];
		nxt[i] = n;
		pre[i] = 0;
		tmp[i] = 0;
		id[i] = false;
	}
	int r = 1;
	for(int i = 1; i <= n; ++ i){
		r = std::max(i,r);
		while(r < n && a[r + 1] - a[i] <= d) ++ r;
		nxt[i] = r;
	}
	nxt[n] = n;
	int l = 1;
	for(int i = 1; i <= n; ++ i){
		while(l < i && a[i] - a[l] > d) ++ l;
		pre[i] = l; ++ tmp[pre[i]];
	}
//	for(int i = 1; i <= n; ++ i){
//		std::cout << "nxt[" << i << "] = " << nxt[i] << '\n';
//	}
//	for(int i = 1; i <= n; ++ i) std::cout << pre[i] << '\n';
	int ans = 0;
	for(int u = 1; u < n; ++ u){
		if(n > 300){
			int now = u,step = 0,res = 0;
			while(now < n && nxt[now] != now){
				if(res > 1) break;
				if(step){
					for(int i = now + 1; i <= nxt[now]; ++ i){
						if(res + now - pre[i] == 1){
	//						std::cout << u << ' ' << i << ' ' << pre[i] << '\n';
							++ ans;
						}
					}
	//				if(res == 1) ans += tmp[now];
	//				else if(pre[now] != now - 1) ans += tmp[now - 1] - (pre[now] == now - 1);
				}
	//			std::cout << u << ' ' << "[" << now + 1 << ',' << nxt[now] << "] = " << ans << '\n';
				if(now != u) res += now - pre[nxt[now]],assert(now  >= pre[nxt[now]]);
				now = nxt[now]; ++ step;
			}
		}else{
			for(int v = u; v <= n; ++ v) id[v] = false;
			for(int v = u + 1; v <= n; ++ v){
				int now = u,res = 0,step = 0;
				while(nxt[now] < v && nxt[now] != now){
					if(now != u) res += now - pre[nxt[now]];
					now = nxt[now];
					++ step;
				}
				if(res > 1 || !step) continue;
				int add = now - pre[v];
				if(add + res == 1){
	//				if(u == 1 && v == 9) std::cout << id[8] << '\n';
					if(!id[pre[v]]) ++ ans;
					if((add + res == 1) && (add == 1) && v != nxt[now]) id[v] = true;
				}
			}
		}
	}
	std::cout << ans << '\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> c >> t;
	while(t -- ){
		solve();
	}
	return 0;
} 
