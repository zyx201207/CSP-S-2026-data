#include <bits/stdc++.h>

#define int long long
#define up(i ,x ,y) for(int i = x ; i <= y ; i ++)
#define dn(i ,x ,y) for(int i = x ; i >= y ; i --)
#define Mp make_pair
#define fir first
#define sec second
#define lowbit(x) (x & -x)
#define inf 2e18

using namespace std ;

inline int read() {int x = 0 ; bool w = 0 ; char c = getchar();while(!isdigit(c)) {w |= (c == '-') ,c = getchar() ;} while(isdigit(c)) {x = (x << 1) + (x << 3) + (c ^ 48) ,c = getchar() ;} return w ? -x : x;}
inline void write(int x) { if(x < 0) x = -x ,putchar('-') ; if(x > 9) write(x / 10) ; putchar(x % 10 | 48) ;}
inline void writesp(int x) { write(x) ,putchar(' ') ;}
inline void writeln(int x) { write(x) ,putchar('\n') ;}

const int N = 2e6 + 10;
int n ,k ,c ,ans ,a[N] ,block ,dis[N] ,fa[N];
bool vis[N] ; 
queue <int> q;
vector <int> edge[N];

inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]) ;}
inline void merge(int x ,int y) {
	int fax = find(x) ,fay = find(y);
	if(fax == fay) return ; 
	fa[fay] = fax ,-- block ;
}
inline void bfs(){
	up(j ,1 ,n) dis[j] = inf ,vis[j] = 0 ;
	up(j ,1 ,k) dis[a[j]] = 0 ,q.push(a[j]) ,vis[a[j]] = 1;
	while(!q.empty()) {
		int u = q.front() ; q.pop();
		for(int v : edge[u]) {
			if(!vis[v]) {
				dis[v] = dis[u] + 1 ; q.push(v) ; vis[v] = 1;
			}
		}
	} int mx = 0 ;
	up(j ,1 ,n) mx = max(mx ,dis[j]) ;
//	cout << "* " << mx << endl;
	ans = min(ans ,mx);
}
inline bool check(int m ,int mid) {
	int rbound = mid + 1 ,lbound = m - mid ;
	rbound += k - 2;
	if(rbound >= lbound) return 1;
	int rem = lbound - rbound - 1;
	int re = max((rem + 1) / 2 + 1 ,1ll);
	return re <= mid ; 
}
int p ,qq ,mx ;
inline void dfs(int u ,int fath ,int d) {
	if(d > mx) {
		mx = d ,p = u ;
	}
	for(int v : edge[u]) {
		if(v == fath) continue;
		dfs(v ,u ,d + 1);
	}
}

namespace lolcrying {

	signed main() {
		
		n = read() ,k = read();
		up(i ,1 ,n) edge[i].clear() ;
		up(i ,1 ,n - 1) {
			int u = read() ,v = read();
			edge[u].push_back(v) ; edge[v].push_back(u) ;
		} ans = inf ;
		if(n <= 10) {
			int lim = (1 << n) - 1;
			up(i ,0 ,lim) {
				int pop = __builtin_popcount(i);
				if(pop != k) continue;
				int cnt = 0 ;
				up(j ,1 ,n) fa[j] = j ,vis[j] = 0 ; 
				up(j ,1 ,n) if((i >> (j - 1)) & 1) a[++ cnt] = j ,vis[j] = 1 ;

				block = k ; 
				up(j ,1 ,k) {
					int u = a[j];
					for(int v : edge[u]) if(vis[v]) merge(u ,v) ;
				}
//					cout << block << endl;
				if(block <= 2) {
//				cout << block << endl;
//					up(j ,1 ,k) writesp(a[j]) ; puts("") ;
					bfs();
				}
			} writeln(ans);
			return 0 ;
		} else if(k == 1) {
			mx = 0 ; 
			dfs(1 ,0 ,0) ,qq = p ,mx = 0;
			dfs(p ,0 ,0) ;
			writeln((mx + 1) >> 1) ; 
			return 0 ;
		} else if(c == 13 || c == 14) {
			int m = (n >> 1);
			if(k == n) puts("0") ;
			else if(k >= m) puts("1") ;
			else {
				int l = 1 ,r = m ,res = 0 ;
				while(l <= r) {
					int mid = ((l + r) >> 1) ;
					if(check(m ,mid)) r = mid - 1 ,res = mid ;
					else l = mid + 1;
				} writeln(res);
				return 0 ;
			}
		} else {
			mx = 0 ; 
			dfs(1 ,0 ,0) ,qq = p ,mx = 0;
			dfs(p ,0 ,0) ;
			writeln((mx + k - 1) / k);
		}
		
		return 0 ;
	}
} signed main() {
	
	freopen("hub.in" ,"r" ,stdin);
	freopen("hub.out" ,"w" ,stdout);
	
	c = read() ;
//	int T = 1 ; 
	int T = read() ;
	while(T --) lolcrying :: main();
	
	return 0 ;
}
