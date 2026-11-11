#include <bits/stdc++.h>
using namespace std;
#define int long long
#define L(i,j,k) for(int i = (j);i <= (k);i++)
#define R(i,j,k) for(int i = (j);i >= (k);i--)
typedef long long ll;
const int T = 1e6+10,inf = 1e18;
int op;
int U[T],V[T];
struct eee {
	int v,nex;
}e[T<<1];
int head[T],cn = 0;
void add(int u,int v) {
	cn++;
	e[cn].nex = head[u],e[cn].v = v;
	head[u] = cn;
}
int n,k;
int zans = 0;
bool fl[T];
bool hfl[T];
const int T2 = 1e3+10;
int dis[T2][T2];
void bfs(int x) {
	queue<int>q;
	q.push(x);
	hfl[x] = true;
	while(q.size()) {
		int u = q.front();q.pop();
		for(int i = head[u],v;i;i = e[i].nex) {
			v = e[i].v;
			if(fl[v] == true && hfl[v] == false) {
				bfs(v);
			}
		}
	}
}
int pos[T];
void ch() {
	L(i,1,n) hfl[i] = false;
	if(k >= 3) {
		int num = 0;
		L(i,1,n) {
			if(fl[i] == true && hfl[i] == false) {
				num++;
				bfs(i);
				if(num >= 3) return ;
			}
		}
	} 
//	L(i,1,n) cout << fl[i] << ' ';
//	cout << '\n';
	if(n <= 10) {
		int lans = 0;
		L(i,1,n) {
			int minv = 114;
			L(j,1,n) {
				if(fl[j] == true) {
					minv = min(minv,dis[i][j]);
				}
			}
			lans = max(lans,minv);
		}
		zans=min(zans,lans);
	}
}
void dfs(int ceng) {
	if(ceng > k) {
		ch();
		return ;
	}
	L(i,pos[ceng-1]+1,n) {
		fl[i] = true;
		pos[ceng] = i;
		dfs(ceng+1);
		fl[i] = false;
	}
}
void solve() {
	cin >> n >> k;
	cn = 0;
	L(i,1,n) head[i] = 0;
	L(i,1,n-1) cin >> U[i] >> V[i],add(U[i],V[i]),add(V[i],U[i]);
	L(i,1,n){
		queue<int>q;
		L(j,1,n) dis[i][j] = inf;
		dis[i][i] = 0;
		q.push(i);
		while(q.size()) {
			int u = q.front();q.pop();
			for(int j = head[u],v;j;j = e[j].nex) {
				v = e[j].v;
				if(dis[i][v] > dis[i][u]+1) {
					dis[i][v] = dis[i][u]+1;
					q.push(v);
				}
			}
		}
//		L(j,1,n) cout << i << ' ' << j << ' ' << dis[i][j] << '\n';
	}
	if(n <= 10) {
		zans = 114;
		dfs(1);
		cout << zans << '\n';
	} 
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> op >> t;while(t--)
	solve();
	return 0;
}

