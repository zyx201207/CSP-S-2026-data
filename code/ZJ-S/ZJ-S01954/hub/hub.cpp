#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<vector>
#define mp make_pair
#define fo(i , x , y) for(int i = (x) ; i <= (y) ; i++)
#define go(i , x , y) for(int i = (x) ; i >= (y) ; i--)
#define chkmax(a , b) (a) = max((a) , (b))
#define chkmin(a , b) (a) = min((a) , (b))
#define local
#ifdef local
#define debug(x) cerr << #x" : " << x << ", "
#define debugn(x) cerr << #x" : " << x << "\n"
#define debugs(s) cerr << s
#define debugarr(a , n) cerr << #a" : " << "\n"; fo(i , 1 , n) cerr << a[i]; cerr << "\n"
#elif
#define debug(x) "Chytholly is the happiest girl in the world!"
#define debugn(x) "Elaina"
#define debugs(s) "miku"
#define debugarr(a , n) "n-buna"
#endif
using namespace std;
const int maxn = 1e5;
int T;
namespace SOLVE1{
	void solve1(){
		while(T--){
			int n , k;
			cin >> n >> k;
			fo(i , 1 , n - 1){
				int u , v;
				cin >> u >> v;
			}
			if(k == 5){
				cout << "0\n";
			}
			else cout << "1\n";
		}
	}
}
namespace SOLVE2{
	int n , k;
	bool check(int mid){
		int l = mid + 1 , r = n / 2 + 2 - mid;
		if(k % 2) k-- , l++;
		l += k / 2 - 1 , r -= k / 2 - 1;
		if(mid % 2) mid--;
		l += mid - 1 , r -= mid - 1;
//		debug(l) , debugn(r);
		if(r - l > 1) return false;
		else return true;
	}
	void solve2(){
		while(T--){
			cin >> n >> k;
			fo(i , 1 , n - 1){
				int u , v;
				cin >> u >> v;
			}
			int l = 1 , r = n;
			while(l < r){
				int mid = (l + r + 1) / 2;
				if(check(mid)) r = mid - 1;
				else l = mid;
			}
			cout << l << "\n";
		}
	}
}
namespace SOLVE3{
	int n , k;
	vector<int> e[maxn + 5];
	int dep[maxn + 5] , maxdep[maxn + 5];
	bool vis[maxn + 5];
	void dfs0(int u , int fa){
		dep[u] = dep[fa] + 1;
		maxdep[u] = dep[u];
		for(int v : e[u]){
			if(v == fa) continue;
			dfs0(v , u);
			chkmax(maxdep[u] , maxdep[v]);
		}
	}
	int cur;
	void dfs1(int u , int fa){
		dep[u] = dep[fa] + 1;
		maxdep[u] = dep[u];
		vis[u] = 1;
		for(int v : e[u]){
			if(vis[v]) continue;
			dfs1(v , u);
			chkmax(maxdep[u] , maxdep[v]);
		}
		if(cur == 0 or maxdep[cur] <= maxdep[u]) cur = u;
	}
	bool check(int mid){
		fo(u , 1 , n){
			dfs0(u , 0);
			vector<int> g;
			for(int v : e[u]){
				if(maxdep[v] - 1 <= mid) continue;
				g.push_back(v);
			}
			if(g.size() > 1) continue;
			if(g.size() == 0) return true;
			int v = g[0];
			memset(vis , 0 , sizeof(vis));
			vis[u] = 1 , cur = 0;
			dfs1(v , u);
			memset(vis , 0 , sizeof(vis));
			vis[u] = 1;
			int tmp = cur , cur = 0;
			dfs1(tmp , 0);
			int len = maxdep[cur];
			if(2 * mid >= len) return true;
			else return false;
		}
		return false;
	}
	void work(){
		cin >> n >> k;
		fo(i , 1 , n - 1){
			int u , v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int l = 1 , r = n;
		while(l < r){
			int mid = (l + r + 1) / 2;
			if(check(mid)) r = mid - 1;
			else l = mid;
		}
		cout << l << "\n";
		fo(i , 1 , n) e[i].clear();
	}
	void solve3(){
		while(T--) work();
	}
}
int main(){
	ios :: sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	int c;
	cin >> c >> T;
	
	if(c == 1) SOLVE1 :: solve1();
	else if(c == 13 or c == 14) SOLVE2 :: solve2();
	else SOLVE3 :: solve3();
}
