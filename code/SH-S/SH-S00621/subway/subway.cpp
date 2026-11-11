#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e2 + 10 , K = 5e5 + 5;
int c,n,m,d,q;
int s,t;
ll w[K];
struct node{
	int a , t;
};
struct f{
	int line;
	ll t;
};
vector<node> line[N]; //地铁线路
vector<f> sub[N]; // 第 i 个地铁站可换乘 subi的线路  
ll dist[N] ;
void solve1(){
	memset(dist,0x3f3f3f3f,sizeof(dist));
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if( u == t)continue;
		for(int i=0;i<sub[u].size();i++){
			int s_l = sub[u][i].line ;
			ll nowt = sub[u][i].t;
			for(int j=0;j<line[s_l].size();j++){
				node l = line[s_l][j];
				int nxt = l.a;//下一个地铁站点 
				if( nxt == u)continue;
				if( sub[nxt].size() == 1 && nxt != t)continue;
				ll w = l.t + nowt ;
				if( dist[u] + w < dist[nxt]){
					q.push(nxt);
					dist[nxt] = dist[u] + w;
				}
			}
		}
	}
	cout << dist[t] + w[s] + w[t] << endl;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)// O m
		cin >> w[i];
	for(int i=1;i<=n;i++){//O n m
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int a , t;
			cin >> a >> t;
			line[i].push_back({a,t});
			sub[a].push_back({i,t});
		}
	}
	for(int i=1;i<=q;i++){// O q m
		cin >> s >> t;
		solve1();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
