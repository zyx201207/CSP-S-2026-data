#include<bits/stdc++.h>
#define int long long
#define pii pair < int , int >
#define mp(a,b) make_pair(a,b)
#define endl '\n'
using namespace std;
const int MAXM = (5e2+5);
const int MAXN = (5e5+5);
const int MAXQ = (1e5+5);
const int MAXE = ((2*MAXN)+MAXM);
const int INF = (4e18);
int c,n,m,d,q,g[MAXN],x[MAXQ],y[MAXQ],k,cnt,u,t,lst,v,w,dis[MAXE],fir[MAXM],mn,ans[MAXQ],l[MAXQ],ll[MAXQ],nt,len[MAXQ][MAXM];
bool vis[MAXE];
vector < int > P[MAXM];
vector < pii > V[MAXE],H[MAXN];
void dijk(int st){
	int u,v,w;
	priority_queue < pii , vector < pii > , greater < pii > > PQ;
	memset(vis,0,sizeof(vis));
	memset(dis,0x7f,sizeof(dis));
	dis[st] = 0;
	PQ.push(mp(0,st));
	while((!PQ.empty())){
		u = PQ.top().second;
		PQ.pop();
		if((!vis[u])){
			vis[u] = 1;
			for(int i = 0;i < V[u].size();i++){
				v = V[u][i].first;
				w = V[u][i].second;
				if(dis[v] > (dis[u]+w)){
					dis[v] = (dis[u]+w);
					if((!vis[v])){
						PQ.push(mp(dis[v],v));
					}
				}
			}
		}
	}
}
int read(){
	int s = 0,f = 1;
	char ch = getchar();
	while((!isdigit(ch))){
		if(ch == '-'){
			f = (-1);
		} 
		ch = getchar();
	}
	while(isdigit(ch)){
		s = ((s<<3)+(s<<1)+(ch^48));
		ch = getchar();
	}
	return (f*s);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(ans,0x7f,sizeof(ans));
	c = read();
	m = read();
	n = read();
	d = read();
	q = read();
	cnt = (2*n);
	for(int i = 1;i <= n;i++){
		g[i] = read();
	}
	for(int i = 1;i <= m;i++){
		k = read();
		cnt++;
		fir[i] = cnt;
		for(int j = 1;j <= k;j++){
			u = read();
			t = read();
			H[u].push_back(mp(i,t));
			V[u].push_back(mp(cnt,t));
			V[cnt].push_back(mp(u,t));
			V[cnt].push_back(mp((n+u),t));
		}
	}
	for(int i = 1;i <= q;i++){
		x[i] = read();
		y[i] = read();
		l[i] = x[i];
	}
	sort((l+1),(l+q+1));
	for(int i = 1;i <= q;i++){
		if(l[i] != l[(i-1)]){
			nt++;
			ll[nt] = l[i];
		}
	}
	for(int i = 1;i <= nt;i++){
		for(int j = 0;j < H[ll[i]].size();j++){
			len[ll[i]][H[ll[i]][j].first] = H[ll[i]][j].second; 
		}
	}
	for(int i = 1;i <= q;i++){
		for(int j = 0;j < H[x[i]].size();j++){
			P[H[x[i]][j].first].push_back(i);
		}
	}
	for(int i = 1;i <= m;i++){
		dijk(fir[i]);
		for(int j = 0;j < P[i].size();j++){
			v = P[i][j];
			if(len[x[v]][i]){
				ans[v] = min(ans[v],(dis[(n+y[v])]+len[x[v]][i]+g[x[v]]+g[y[v]]));
			} 
		}
	}
	for(int i = 1;i <= q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
