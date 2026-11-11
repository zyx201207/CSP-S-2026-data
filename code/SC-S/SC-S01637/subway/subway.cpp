#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int maxn = 3e5 + 10;
inline int read(){
	int res = 0,f = 1; char ch = getchar();
	while (!isdigit(ch)){if (ch == '-') f = -1; ch = getchar();}
	while (isdigit(ch)){res = res * 10 + (ch - '0'); ch = getchar();}
	return res * f;
}
struct node{
	int to,w,bl;
};
struct qnode{
	int id,d,lst;
	friend bool operator <(qnode a,qnode b){
		return a.d > b.d;
	}
};
int c,n,m,d,Q;
int w[maxn],k[maxn],t[510][maxn];
vector<int> h[maxn];
vector<node> v[maxn];
int dis[maxn][510];
priority_queue<qnode> q;
bool vis[maxn];

int dij(int s,int T){
	memset(dis,0x7f,sizeof(dis));
	int ans = dis[0][0];
	memset(vis,false,sizeof(vis));
	dis[s][0] = 0; q.push({s,0,0});
	while (!q.empty()){
		qnode nd = q.top(); q.pop();
		int x = nd.id;
		if (vis[x]) continue;
		vis[x] = true;
		for (int i = 0;i < v[x].size();i++){
			int y = v[x][i].to,bl = v[x][i].bl;
			if (nd.lst == 0){
				if (y == T) dis[y][bl] = dis[x][0] + t[bl][x] + t[bl][y];
				else{
					dis[y][bl] = dis[x][0] + t[bl][x];
					q.push({y,dis[y][bl],bl});
				}
			}else if (nd.lst == bl){
				if (y == T){
					if (dis[y][bl] > dis[x][nd.lst] + t[bl][y]) dis[y][bl] = dis[x][nd.lst] + t[bl][y];
				}else{
					if (dis[y][bl] > dis[x][nd.lst]){
						dis[y][bl] = dis[x][nd.lst];
						q.push({y,dis[y][bl],bl});
					}
				}
			}else{
				if (y == T){
					if (dis[y][bl] > dis[x][nd.lst] + t[nd.lst][x] + t[bl][x] + t[bl][y]) dis[y][bl] = dis[x][nd.lst] + t[nd.lst][x] + t[bl][x] + t[bl][y];
				}else{
					if (dis[y][bl] > dis[x][nd.lst] + t[nd.lst][x] + t[bl][x]){
						dis[y][bl] = dis[x][nd.lst] + t[nd.lst][x] + t[bl][x];
						q.push({y,dis[y][bl],bl});
					}
				}
			}
		}
	}
	for (int i = 1;i <= n;i++) ans = min(ans,dis[T][i]);
	return ans;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read(); n = read(); m = read(); d = read(); Q = read();
	for (int i = 1;i <= m;i++) w[i] = read();
	for (int i = 1;i <= n;i++){
		k[i] = read();
		int lst = 0;
		for (int j = 1;j <= k[i];j++){
			int z = read(),d = read();
			h[z].push_back(i); t[i][z] = d;
			if (!lst) lst = z;
			else{
				v[lst].push_back({z,0,i});
				v[z].push_back({lst,0,i});
				lst = z;
			}
			
		}
	}
//	for (int i = 1;i <= m;i++){
//		for (int j = 0;j < v[i].size();j++){
//			cout << i << " " << v[i][j].to << " " << v[i][j].w << " " << v[i][j].bl << endl;
//		}
//	}
//	dij(1,3);
	for (int i = 1;i <= Q;i++){
		int qd = read(),zd = read();
		cout << dij(qd,zd) + w[qd] + w[zd] << endl;
	}
	return 0;
}