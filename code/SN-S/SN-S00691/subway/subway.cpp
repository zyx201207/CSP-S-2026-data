#include <bits/stdc++.h>
using namespace std;
#define int long long
#define L(i,j,k) for(int i = (j);i <= (k);i++)
#define R(i,j,k) for(int i = (j);i >= (k);i--)
typedef long long ll;
int c,n,m,d,q;
const int T = 5e5+505,inf = 1e18;
int k[T],qk[T];
vector<int>a[T],t[T];
int w[T];
int dui[T];
struct eee {
	int v,nex,w;
}e[T<<2];
int head[T],cn = 0;
void add(int u,int v,int w) {
	cn++;
	e[cn].v = v,e[cn].nex = head[u],e[cn].w = w;
	head[u] = cn;
}
int dis[T];
bool fl[T];
void dij(int s) {
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	L(i,1,m+n) {
		fl[i] = false;
		dis[i] = inf;
	}
	dis[s] = 0;
	q.push({dis[s],s});
	while(q.size()) {
		int u = q.top().second;q.pop();
		if(fl[u]) continue;
		fl[u] = true;
		for(int i = head[u],v,w;i;i = e[i].nex) {
			v = e[i].v,w = e[i].w;
			if(dis[v] > dis[u]+w) {
				dis[v] = dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
vector<pair<int,int>>vec[T];
const int T2 = 505;
int ds[T2][T2];
void solve() {
	cin >> c >> n >> m >> d >> q;
	L(i,1,m) cin >> w[i];
	qk[0] = 0;
	L(i,1,n) {
		cin >> k[i],qk[i] = qk[i-1] + k[i];
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		L(j,1,k[i]) {
			cin >> a[i][j];
			cin >> t[i][j];
//			add(a[i][j],m+i,t[i][j]);
//			add(m+i,a[i][j],t[i][j]);
			vec[a[i][j]].push_back({i,t[i][j]});
		}
	}
//	if(q <= 200) {
//		L(i,1,q){
//			int s,t;
//			cin >> s >> t;
//			dij(s);
//			int minn = dis[t];
//			minn += w[t]+w[s];
//			cout << minn << '\n';
//		}
//		return ;
//	}
//	else {
		memset(ds,63,sizeof(ds));
		L(i,1,n) ds[i][i] = 0;
		L(i,1,m) {
			int sz = vec[i].size();
			L(j,0,sz-1) {
				auto x = vec[i][j];
				L(k,j+1,sz-1) {
					auto y = vec[i][k];
					ds[x.first][y.first] = min(ds[x.first][y.first],x.second+y.second);
					ds[y.first][x.first] = min(ds[y.first][x.first],x.second+y.second);
				}
			}
		}
//		L(i,1,n) L(j,1,n) {
//			cout << i << ' ' << j << " : " << ds[i][j] << '\n';
//		}
		L(k,1,n) {
			L(i,1,n) {
				L(j,1,n) {
					ds[i][j] = min(ds[i][j],ds[i][k]+ds[k][j]);
				}
			}
		}
		L(i,1,q) {
			int s,t;
			cin >> s >> t;
			int minn = inf;
			int x,y;
			for(auto a : vec[s]) {
				x = a.first;
				for(auto b : vec[t]) {
					y = b.first;
					minn = min(minn,ds[x][y]+a.second+b.second);
				}
			}
			cout << minn+w[s]+w[t] << '\n';
		}
//	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
//	int t;cin >> t;while(t--)
	solve();
	return 0;
}

