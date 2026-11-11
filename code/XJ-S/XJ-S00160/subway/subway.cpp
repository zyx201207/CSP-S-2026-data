#include <iostream>
#include <algorithm>
#include <cstring> 
#include <vector>
#include <queue>
#define ll long long
using namespace std;
const int N = 5e5+5;//////
const int M = 1e5+5;
const int T = 505;//////
const ll inf = 1e18;

struct node{
	ll w; int x;
	bool operator<(const node& a)const{
		return a.w<w;
	}
};
struct edge{
	ll ans;
	int x, y;
	edge(){ans=inf;}
	edge(int nx, int ny, ll a){
		x=nx;y=ny;ans=a;
	}
}ed[M];

int c, n, m, d, q, done[N+T];
ll w[N+T], dis[N+T];
vector<pair<int, ll> > g[N+T];
vector<int> qu[N+T];
void dij(int t){
	memset(dis, 0x3f, sizeof(dis));
	memset(done, 0, sizeof(done));
	priority_queue<node> pq;
	dis[m+t]=0;
	pq.push({0, m+t});
	while(!pq.empty()){
		int x=pq.top().x;
		pq.pop();
		//cout << t << ':' << x << ' ' << dis[t][x] << endl;
		if(done[x])continue;
		done[x]=1;
		int len = g[x].size();
		for(int i=0; i<len; i++){
			int to=g[x][i].first; ll nw=g[x][i].second;
			if(done[to])continue;
			if(nw+dis[x]<dis[to]){
				dis[to] = nw+dis[x];
				if(g[to].size()!=1)pq.push({dis[to], to});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i=1; i<=m; i++)scanf("%lld", w+i);
	for(int i=1; i<=n; i++){
		int k; scanf("%d", &k);
		while(k--){
			int x;ll len; scanf("%d%lld", &x, &len);
			g[i+m].push_back(make_pair(x, len));
			g[x].push_back(make_pair(i+m, len));
		}
	}
	for(int i=1; i<=q; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		ed[i]=edge(x,y,inf);
		qu[x].push_back(i);
	}
	for(int i=1; i<=n; i++){
		dij(i);
		int len=g[i+m].size();
		for(int j=0; j<len; j++){
			int x=g[i+m][j].first; ll nw=g[i+m][j].second;
			int tlen=qu[x].size();
			for(int q=0; q<tlen; q++){
				int id=qu[x][q];
				ed[id].ans = min(ed[id].ans, dis[ed[id].y]+nw);
			}
		}
	}
	for(int i=1; i<=q; i++){
		printf("%lld\n", ed[i].ans+w[ed[i].x]+w[ed[i].y]);
	}
	return 0;
}
