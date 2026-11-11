#include<bits/stdc++.h>
#define ll long long
using namespace std;

int c, T, n, k, kn;
//int prt[N], cnt, root;

//void dfs(int u, int fa){
//	for(int i = head[u]; i; i = nxt[i]){
//		int v = twd[i];
//		if(v == fa) continue;
//		dfs(v, u);
//		prt[u] = min(prt[v], prt[u]);
//		if(prt[u] <= 1 && ){
//			if(cnt == 0){
//				cnt++;
//				vv[u] = 1;
//			}
//		}
//	}
//	return;
//}
//上面的先不管它 
//void find_root(int u, int fa){
//	siz[u] = 1; prt[u] = 0;
//	for(int i = head[u]; i; i = nxt[i]){
//		int v = twd[i];
//		if(v == fa) continue;
//		find_root(v);
//		prt[u] = max(prt[v], prt[u]);
//	}
//	maxdep[u] = max(prt[u]+1, dep[u]);
//	return;
//}
//我写不出来这个
 
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while(T--){
//		init();//多测要清空 
		cin >> n >> k;
		int u, v;
		for(int i = 1; i <= n-1; i++){
			cin >> u >> v;
//			add(u, v);
//			add(v, u);
		}
		if(c == 13 || c == 14){
			if(n == k){
				cout << "0\n";
				continue;
			}
			ll m = n/2, ans;
			if(k >= m-1){
				cout << "1\n";
				continue;
			}
			if(m%2 == 0 && k%2 == 0){
				if((m/2)%2 == 1){
					ans = (m/2+1)/2-(k/2-1)/2;
					cout << ans << "\n";
					continue;
				}else{
					ans = (m/2+1-k/2+1)/2;
					cout << ans << "\n";
					continue;
				}
			}
			if(m%2 == 0 && k%2 == 1){
				cout << (m-k)/4+2 << "\n";
				continue;
			}
			if(m%2 == 1){
				k /= 2;
				m = m/2+1;
				m -= (k-1);
				m = (m+1)/2;
				cout << m << "\n";
				continue;
			}
			continue;
		}
	}
	return 0;
}
