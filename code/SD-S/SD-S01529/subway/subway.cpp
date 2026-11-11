#include<bits/stdc++.h>

#define int long long
#define pii pair<int,int>

using namespace std;

int read(){
	int x = 0,y = 1;
	char ch = getchar();
	while(ch > '9'||ch < '0'){
		if(ch == '-') y = -1;
		ch = getchar();
	}
	while(ch >= '0'&&ch <= '9'){
		x = x*10+ch-'0';
		ch = getchar();
	}
	return x*y;
}

void print(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	char ch = x%10+'0';
	if(x >= 10) print(x/10);
	putchar(ch);
}

int ceshidian;
int n,m,d,q;

int w[500005];

vector<pii> rod[500005];
int edw[505][505];

priority_queue<pii,vector<pii>,greater<pii> > que;
int dis[505][505];
bool vis[505];

void dijkstra(int s,int id){
	
	for(int i = 1;i <= n;++ i)
		dis[id][i] = 2e18,vis[i] = 0;
	que.push({0,s});
	dis[id][s] = 0;
	
	while(!que.empty()){
		
		int ds = que.top().first;
		int x = que.top().second;
		que.pop();
		
		if(ds > dis[id][x]||vis[x]) continue;
		vis[x] = 1;
		
		for(int y = 1;y <= n;++ y){
			int w = edw[x][y];
			if(dis[id][y] > dis[id][x]+w){
				dis[id][y] = dis[id][x]+w;
				que.push({dis[id][y],y});
			}
		}
		
	}
	
}

signed main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ceshidian = read();
	n = read();m = read();
	d = read();q = read();
	
	for(int i = 1;i <= m;++ i)
		w[i] = read();
	
	for(int i = 1;i <= n;++ i){
		int k = read();
		for(int j = 1;j <= k;++ j){
			pii t;
			t.first = read();
			t.second = read();
			rod[t.first].push_back({i,t.second});
		}
	}
	
	for(int i = 1;i <= n;++ i)
		for(int j = i+1;j <= n;++ j)
			edw[i][j] = edw[j][i] = 2e18;
	
	for(int x = 1;x <= m;++ x){
		for(int i = 0;i < rod[x].size();++ i){
			for(int j = i+1;j < rod[x].size();++ j){
				int r1 = rod[x][i].first,r2 = rod[x][j].first;
				int w1 = rod[x][i].second,w2 = rod[x][j].second;
				edw[r1][r2] = min(edw[r1][r2],w1+w2);
				edw[r2][r1] = edw[r1][r2];
			}
		}
	}
	
	for(int i = 1;i <= n;++ i)
		dijkstra(i,i);
	
	while(q--){
		int x = read(),y = read();
		int ans = 2e18;
		for(int i = 0;i < rod[x].size();++ i){
			for(int j = 0;j < rod[y].size();++ j){
				int r1 = rod[x][i].first,r2 = rod[y][j].first;
				int w1 = rod[x][i].second,w2 = rod[y][j].second;
				ans = min(ans,w[x]+w[y]+dis[r1][r2]+w1+w2);
			}
		}
		print(ans);putchar('\n');
	}
	
	return 0;
	
}
