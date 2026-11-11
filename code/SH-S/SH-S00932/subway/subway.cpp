#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
priority_queue<pair<int, int> > que;
int to[800005],head[800005],w[800005],nxt[800005];
int cnt;
int vis[800005]; 
int c,n,m,d,q;
int time1[800005];
int dist[800005];
void add(int u,int v,int val){
	cnt++;
	w[cnt] = val;
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	int dot = 500001;
	for(int i =1;i<=m;i++){
		cin >> time1[i];
	}
	for(int i =1;i<=n;i++){
		int k;
		cin >> k;
		dot ++;
		for(int j=1;j<= k;j++){
			int a,t;
			cin >> a >>t;
			add(a,dot,t);
			add(dot,a,t);
		}
	}
	for(int Q=1;Q<=q;Q++){
		memset(dist,0x3f,sizeof(dist));
		memset(vis,0,sizeof(vis));
		int s, e;
		cin >> s >> e;
		int ans = time1[s] + time1[e];
		que.push(make_pair(0,s));
		dist[s] = 0;
		while( que.size() ){
			int x = que.top().second;
			que.pop();
			vis[x] = 1;
			for(int i = head[x];i;i = nxt[i]){
				int y = to[i];
				if(vis[y] == 0){
					if(dist[y] > dist[x] + w[i]){
						dist[y] = dist[x] + w[i];
						que.push(make_pair(-dist[y],y));
					}
				}
			}
		}
		ans = ans + dist[e];
		cout << ans <<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
