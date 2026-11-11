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
int n ,c ,d ,x[N] ,dis[N] ,path[N]; 
bool vis[N];
queue <int> q;
vector <int> edge[N];

inline void bfs(int x){
	up(i ,1 ,n) dis[i] = inf ,vis[i] = path[i] = 0 ; 
	path[x] = 1 ,dis[x] = 0 ,vis[x] = 1; q.push(x);
	while(!q.empty()) {
		int u = q.front() ; q.pop();
		for(int v : edge[u]) {
			if(vis[v]) {
				if(dis[u] + 1 == dis[v]) {
					if(path[v] <= 2) path[v] += path[u] ;
				}
			} else {
				dis[v] = dis[u] + 1 ,path[v] = path[u] ,vis[v] = 1;
				q.push(v) ;
			}
		}
	}
}
namespace lolcrying {

	signed main() {
		
		n = read() ,d = read() ; 
		up(i ,1 ,n) x[i] = read() ;
		
		int ans = 0; 
		if(n <= 2) {
			writeln(0) ;
			return 0 ;
		}
		
		if(c == 11 || c == 12) {
			if(d < x[3] - x[1]) writeln(0) ;
			else {
				int T = d / (x[2] - x[1]);
				writeln(max(n + 1 - 2 * T ,0ll));
				return 0 ;
			} 
		}
		
		if(c <= 6) {
			
			up(i ,1 ,n) {
				up(j ,1 ,n) {
					if(abs(x[i] - x[j]) <= d) edge[i].push_back(j)  ;
				}
			}
			
			int ans = 0 ;
			up(i ,1 ,n) {
				bfs(i) ;
				up(j ,i + 1 ,n) ans += (path[j] == 2) ;
			} writeln(ans);
			
			up(i ,1 ,n) edge[i].clear() ;
			
		}
		
		return 0 ;
	}
} signed main() {
	
	freopen("migrate.in" ,"r" ,stdin);
	freopen("migrate.out" ,"w" ,stdout);
	
	c = read() ;
//	int T = 1 ; 
	int T = read() ;
	while(T --) lolcrying :: main();
	
	return 0 ;
}
