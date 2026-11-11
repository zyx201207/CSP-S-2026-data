#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
struct xl{
	ll x,t;
};
vector<xl> a[510000];
vector<xl> xianlu[510000];
struct node{
	ll u,w,last;
	friend bool operator < (node a,node b){
		return a.w > b.w;
	}
};
bool vis[510000];
ll dis[510000];
void dj(int s){
	priority_queue<node> q;
	dis[s] = 0;
	q.push({s,0,-1});
	while(!q.empty()){
		node now = q.top();q.pop();
		if(vis[now.u]==0){
			vis[now.u] = 1;
			for(int i = 0 ; i < a[now.u].size() ; i++){
				if(a[now.u][i].x==now.last) continue;
				for(xl nxt : xianlu[a[now.u][i].x]){
					if(nxt.x==now.u) continue;
					if(dis[nxt.x]>dis[now.u]+nxt.t+a[now.u][i].t){
						dis[nxt.x] = dis[now.u] + nxt.t + a[now.u][i].t;
						q.push({nxt.x,dis[nxt.x],a[now.u][i].x});
					}
				}
			}
		}
	}
}
ll w[500001];
int main(){
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> m >> n >> d >> q;
	for(int i = 1 ; i <= n ; i++){
		cin >> w[i];
	}
	for(int i = 1 ; i <= m ; i++){
		int num = 0;
		cin >> num;
		for(int j = 1 ; j <= num ; j++){
			int x,y;
			cin >> x >> y;
			xianlu[i].push_back({x,y});
			a[x].push_back({i,y});
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		for(int i = 1 ; i <= n ; i++){
			vis[i] = 0;
			dis[i] = 1e18;
		}
		dj(x);
		cout << dis[y]+w[x]+w[y] << '\n'; 
	}
	return 0;
}
