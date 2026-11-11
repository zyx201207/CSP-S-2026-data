#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
const int MX=5e5+5;
int head[MX], cnt;
int c, n, m, d, q;
int w[MX], a[MX], t[MX];
int inq[MX], dis[MX];
struct node{
	int to, nex, w2;
}edges[MX*2];
void add(int u, int v, int w2) {
	edges[++cnt].to=v;
	edges[cnt].nex=head[u];
	edges[cnt].w2=w2;
	head[u]=cnt;
}
void spfa(int s){
	memset(inq, 0, sizeof(inq));
	for(int i=1; i<=m; i++)  dis[i]=1e9;
	queue<int> q;
	q.push(s); inq[s]=true;
	dis[s]=0;
	while(!q.empty()) {
		int u=q.front();
		q.pop(); inq[u]=false;
		for(int e=head[u]; e; e=edges[e].nex) {
			int v=edges[e].to;
			if(dis[u]+edges[e].w2<dis[v]) {
				dis[v]=dis[u]+edges[e].w2;
				if(!inq[v]) {
					q.push(v);
					inq[v]=true;
				}
			}
		}
	}
}
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; i++)  cin >> w[i];
	for(int i=1; i<=n; i++) {
		int k;
		cin >> k;
		for(int j=1; j<=k; j++) {
			cin >> a[j] >> t[j];
		} 
		for(int j=1; j<=k; j++) {
			for(int l=j+1; l<=k; l++) {
				add(a[j], a[l], t[j]+t[l]);
				add(a[l], a[j], t[j]+t[l]);
			}
		}
		
	}
	for(int i=1; i<=q; i++) {
		int u, v;
		cin >> u >> v;
		spfa(u);
		cout << w[u]+dis[v]+w[v] << '\n';
		
	}
    return 0;
}
