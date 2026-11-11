#include "bits/stdc++.h"
#define For(i, l, r) for(int i=(l); i<=(r); ++i)
#define Rof(i, r, l) for(int i=(r); i>=(l); --i)
using namespace std;
typedef long long ll;
const int N=502, M=5e5+5;
struct Node {
	int x, y;
	bool operator <(const Node& b) const{
		return y>b.y;
	}
};
int c, n, m, d, Q, k, x, y, w[M];
int a[N], t[N], vis[M+N*N], dis[M+N*N];
vector<Node> g[M+N*N];
//定义M+N*(j-1)+i表示第i个铁路

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin>>c>>n>>m>>d>>Q;
	For(i, 1, m) cin>>w[i];
	For(i, 1, n) {
		cin>>k;
		For(j, 1, k) {
			cin>>a[j]>>t[j];
			g[M+N*(i-1)+j].push_back({a[j], t[j]});
			g[a[j]].push_back({M+N*(i-1)+j, t[j]});
		}
		For(j, 1, k-1) g[M+N*(i-1)+j].push_back({M+N*(i-1)+j+1, 0});
		For(j, 2, k) g[M+N*(i-1)+j].push_back({M+N*(i-1)+j-1, 0});
	}
	
	For(i, 1, Q) {
		cin>>x>>y;
		memset(dis, 0x3f, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		priority_queue<Node> q; 
		q.push({x, w[x]}); dis[x]=w[x]; vis[x]=1;
		while(!q.empty()) {
			Node u=q.top(); q.pop();
//			if(u.x>M) cout<<"stop: "<<(u.x-M)/N+1<<" "<<(u.x-M)%N<<" "<<dis[u.x]<<endl;
//			else cout<<"station: "<<u.x<<" "<<dis[u.x]<<endl;
			if(u.x<=M) vis[u.x]=1;
			for(auto v:g[u.x]) {
//				cout<<v.x<<endl;
				if(dis[u.x]+v.y<dis[v.x]) {
					dis[v.x]=dis[u.x]+v.y;
					q.push({v.x, dis[v.x]});
				}
			}
		}
		cout<<dis[y]+w[y]<<"\n";
	}
	return 0;
}
/*
I LOVE CCF
give me morrrrrrrrrrrrrrrrrre score pleeeeeeeease
STO CCF OTZ
*/
