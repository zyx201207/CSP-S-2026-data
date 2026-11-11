#include<bits/stdc++.h>
//#define int long long
using namespace std;

const int N = 5e5+1005;

int c, n, m, d, q;
int ino[N];

struct Edge{
	int to, next, w;
}edge[N << 1];
int head[N], cnt;

void addedge(int u, int v, int w){
	edge[++cnt] = {v, head[u], w};
	head[u] = cnt;
}

int k, lst[514];
int a[N], t[N];

struct node{
	int u, dis;
	bool operator < (const node& oth) const{
		return dis > oth.dis;
	}
};

int vis[N], dis[N];

void dijkstra(int s){
	memset(vis, 0, sizeof vis);
	memset(dis, 0x3f, sizeof dis);
	priority_queue<node> q;
	q.push({s, 0});
	dis[s] = 0;
	
	while(!q.empty()){
		int u = q.top().u;q.pop();
		if(vis[u])continue;
		vis[u] = 1;
		for(int i = head[u]; i != 0; i = edge[i].next){
			int v = edge[i].to, w = edge[i].w;
			if(dis[v] > dis[u] + w)dis[v] = dis[u] + w, q.push({v, dis[v]});
		}
	}
}

struct que{
	int x, y, id, ans;
}qs[N];

bool cmp1(que as1, que as2){
	return as1.x < as2.x;
}

bool cmp2(que as1, que as2){
	return as1.id < as2.id;
}

int ans[N];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1; i <= m; i++)cin>>ino[i];
	for(int i = 1; i <= n; i++){
		cin>>k;
		for(int j = 1; j <= k; j++){
			int u, w;cin>>u>>w;
			addedge(i+m, u, w), addedge(u, i+m, w);
		}
//		for(int j = 1; j <= k[i]; j++)cin>>a[j]>>t[j];	
//		for(int j = 1; j <= k[i]; j++)addedge(i+m, a[j], t[j]), addedge(a[j], i+m, t[j]); //Õ¾Ì¨×ßµ½Õ¾Ìü 
	}
	for(int i = 1; i <= q; i++){
		int x, y;cin>>x>>y;
		if(x > y)swap(x, y);
		qs[i] = {x, y, i, 0};
	}
	sort(qs+1, qs+q+1, cmp1);
	for(int i = 1; i <= q; i++){
		if(qs[i].x != qs[i-1].x)dijkstra(qs[i].x);
		qs[i].ans = ino[qs[i].x] + ino[qs[i].y] + dis[qs[i].y];
	}
	sort(qs+1, qs+q+1, cmp2);
	for(int i = 1; i <= q; i++)cout<<qs[i].ans<<endl;
	return 0;
}
/*

*/ 
