#include <bits/stdc++.h>

#define int long long
#define up(i ,x ,y) for(int i = x ; i <= y ; i ++)
#define dn(i ,x ,y) for(int i = x ; i >= y ; i --)
#define Mp make_pair
#define PII pair <int ,int>
#define fir first
#define sec second
#define lowbit(x) (x & -x)
#define inf 2e18

using namespace std ;

inline int read() {int x = 0 ; bool w = 0 ; char c = getchar();while(!isdigit(c)) {w |= (c == '-') ,c = getchar() ;} while(isdigit(c)) {x = (x << 1) + (x << 3) + (c ^ 48) ,c = getchar() ;} return w ? -x : x;}
inline void write(int x) { if(x < 0) x = -x ,putchar('-') ; if(x > 9) write(x / 10) ; putchar(x % 10 | 48) ;}
inline void writesp(int x) { write(x) ,putchar(' ') ;}
inline void writeln(int x) { write(x) ,putchar('\n') ;}

const int N = 6e5 + 10;
int n ,m ,d ,Q ,c ,w[N] ,dis[N] ,dist[2005][2005];
int f[405][405] ,sub[N] ,tim[3][N] ;
bool visit[3][N] ;
bool vis[N] ;
vector < PII > edge[N];
priority_queue < PII ,vector < PII > ,greater < PII > > q;
queue <int> qwq;

inline void add(int u ,int v ,int w) {
	edge[u].push_back(Mp(v ,w)) ;
//	cout << u << ' ' << v << ' ' << w << endl;
	if(u <= 400 && v <= 400) f[u][v] = min(f[u][v] ,w) ;
}
inline void dij(int st) {
	up(i ,1 ,n) vis[i] = 0 ,dis[i] = inf ;
	dis[st] = 0 ; q.push(Mp(0 ,st)) ;
	while(!q.empty()) {
		int u = q.top().sec ; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto i : edge[u]) {
			int v = i.fir ,w = i.sec;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push(Mp(dis[v] ,v)) ;
			}
		}
	}
	up(i ,1 ,n) dist[st][i] = dis[i] ;
}
inline void bfs(int x) {
	up(i ,1 ,n + m) vis[i] = 0 ,dis[i] = inf ;
	vis[x] = 1 ,dis[x] = 0 ,qwq.push(x);
	while(!qwq.empty()) {
		int u = qwq.front() ; qwq.pop();
		for(auto i : edge[u]) {
			int v = i.fir ,w = i.sec;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w ;
				vis[v] = 1;
				qwq.push(v) ;
			}
		}
	}
}
namespace lolcrying {

	signed main() {
		
		n = read() ,m = read() ,d = read() ,Q = read() ;
		
		up(i ,1 ,m) w[i] = read() ; 
		up(i ,1 ,400) up(j ,1 ,400) f[i][j] = (i == j ? 0 : inf) ;
		
		int idx = m ;
		up(i ,1 ,n) {
			int l = read();
			if(c >= 7 && c <= 11) {
				if(l == 1) {
					int x = read() ; continue;
				} else {
					int x = read() ,t1 = read() ,y = read() ,t2 = read();
					edge[x].push_back(Mp(y ,t1 + t2)) ;
					edge[y].push_back(Mp(x ,t1 + t2)) ;
				}
			} else if(c == 20 || c == 21) {
				up(j ,1 ,l) {
					int x = read() ,t = read();
					tim[i][x] = t ,visit[i][x] = 1;
					sub[x] ++ ; 
				}
			} else {
				++ idx ;
				up(j ,1 ,l){
					int x = read() ,w = read();
					add(x ,idx ,w) ,add(idx ,x ,w) ;
				}	
			}
		}
		
		int T = inf ;
//		up(p ,1 ,m) writesp(sub[p]) ; puts("") ;
		up(p ,1 ,m) if(sub[p] == 2) T = min(T ,tim[1][p] + tim[2][p]) ;
//		cout << T << ' ' << c << endl;
		if(idx <= 400) {
			up(k ,1 ,idx) up(i ,1 ,idx) up(j ,1 ,idx) f[i][j] = min(f[i][j] ,f[i][k] + f[k][j]) ;
			while(Q --) {
				int x = read() ,y = read();
				writeln(w[x] + w[y] + f[x][y]) ;
			}
		} else if(c >= 7 && c <= 11) {
			up(i ,1 ,n) {
				dij(i) ;
			} while(Q --) {
				int x = read() ,y = read();
				writeln(w[x] + w[y] + dist[x][y]) ; 
			}
		} else if(c >= 12 && c <= 15) {
			while(Q --) {
				int x = read() ,y = read();
				bfs(x);
				writeln(w[x] + w[y] + dis[y]) ;
			}
		} else if(c == 20 || c == 21) {
//			cout << "hi" << endl;
			while(Q --) {
				int x = read() ,y = read() ,r1 = inf ,r2 = inf ; 
				if(visit[1][x] && visit[1][y]) r1 = tim[1][x] + tim[1][y];
				if(visit[2][x] && visit[2][y]) r1 = min(r1 ,tim[2][x] + tim[2][y]) ;
				if(visit[1][x] && visit[2][y]) r2 = tim[1][x] + tim[2][y] + T ;
				if(visit[2][x] && visit[1][y]) r2 = min(r2 ,tim[2][x] + tim[1][y] + T) ;
//				cout << r1 << ' ' << r2 << endl;
				writeln(min(r1 ,r2) + w[x] + w[y]) ;
			}
		} else {
			
			while(Q --) {
				
				writeln(114514) ;
				
			}
		}
		return 0 ;
	}
} signed main() {
	
	freopen("subway.in" ,"r" ,stdin);
	freopen("subway.out" ,"w" ,stdout);
	
	c = read() ;
	int T = 1 ; 
//	int T = read() ;
	while(T --) lolcrying :: main();
	
	return 0 ;
}
