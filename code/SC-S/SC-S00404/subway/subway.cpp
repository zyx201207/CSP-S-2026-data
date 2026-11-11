#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int maxm = 5e5+5;
const int maxn = 505;
const int maxt = maxn+maxm;
const int inf = 1e9;
const int maxq = 1e5;
using ll = long long;
int c;
int n,m,d,q;
int w[maxm];

const int ISZ = 1<<20;
char buff[ISZ];
int ipos,ilen;
char gc(){
	if (ipos==ilen){
		ilen = fread(buff,1,ISZ,stdin);
		ipos = 0;
		if (ilen==0) return EOF;
	}
	return buff[ipos++];
}
int rd(){
	int x = 0;
	char ch = gc();
	while (ch<'0' || ch>'9'){
		ch = gc();
	}
	while ('0'<=ch && ch<='9'){
		x = x*10+ch-'0';
		ch = gc();
	}
	return x;
}

struct qry{
	int id,y;
	ll t0;
};
vector<qry> qu[maxm];
ll ans[maxq];

vector<pii> G[maxt];
ll dis[maxt];
bool vis[maxt];
#define pii pair<ll,int>
priority_queue<pii,vector<pii>,greater<pii>> pq;
void dijkstra(int s){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[s] = 0;
	pq.push({0,s});
	while(!pq.empty()){
		int u = pq.top().second;pq.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto e:G[u]){
			int v = e.first,w = e.second;
			if (vis[v]) continue;
			if (dis[u]+w<dis[v]){
				dis[v] = dis[u]+w;
				pq.push({dis[v],v});
			}
		}
	}
}
void solve1(){
	for (int i = 1;i<=n;i++){
		int k = rd();
		vector<int> tmp;
		int T = 0;
		for (int j = 1;j<=k;j++){
			int a = rd(),t = rd();
			if (k==1) continue;
			T = t;
			tmp.push_back(a);
		}
		int len = tmp.size();
		for (int i = 0;i<len;i++){
			for (int j = i+1;j<len;j++){
				G[i].push_back({j,2*T});
				G[j].push_back({i,2*T});
			}
		}
	}
	while(q--){
		int x = rd(),y = rd();
		int ans = w[x]+w[y];
		dijkstra(x);
		cout<<ans+dis[y]<<"\n";
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	c = rd();n = rd();m = rd();d = rd();q = rd();
	for (int i = 1;i<=m;i++) w[i] = rd();
//	if (12<=c && c<=19) solve1();
	for (int i = 1;i<=n;i++){
		int k = rd();
		for (int j = 1;j<=k;j++){
			int a = rd(),t = rd();
			if (k==1) continue;
			G[m+i].push_back({a,t});
			G[a].push_back({m+i,t});
		}
	}
	for (int i = 1;i<=q;i++){
		int x = rd(),y = rd();
		if (x>y) swap(x,y);
		qu[x].push_back({i,y,w[x]+w[y]});
	}
	for (int i = 1;i<=m;i++){
		if (qu[i].size()==0) continue;
		dijkstra(i);
		for (qry sth:qu[i]){
			ans[sth.id] = sth.t0+dis[sth.y];
		}
	}
	for (int i = 1;i<=q;i++) cout<<ans[i]<<"\n";
	return 0;
}