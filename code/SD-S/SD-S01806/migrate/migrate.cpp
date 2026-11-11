#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int maxn=5009; const int INF=0x3f3f3f3f;
ll x[maxn]; int frst[maxn];
vector<int> G[maxn];
int d[maxn][maxn]; bool vis[maxn]; bool actived[maxn][maxn];
map<int, int> ap[maxn];
void floyd(int n) {
	for (int k=1;k<=n;k++) {
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				if (d[i][k]!=INF&&d[k][j]!=INF) {
					int dist = d[i][k]+d[k][j];
					if (dist<d[i][j]) {
						ap[i][j]=1; d[i][j]=dist;
					} else if (dist==d[i][j]) {
						ap[i][j]++;
					}
				}
			}
		}
	}
//	memset(vis, 0, sizeof vis);
//	priority_queue<P,vector<P>,greater<P> > pq; d[f][f]=0; pq.push((P){0,f});
//	while (!pq.empty()) {
//		P p=pq.top(); pq.pop();
//		int x= p.second, cd=p.first;
//		if (vis[x]) continue; vis[x]=1;
//		for (int i=0;i<G[x].size();i++) {
//			int v=G[x][i];
//			if (cd+1<d[f][v]) {
//				d[f][v]=cd+1; ap[f][v]=1;
//				pq.push((P){cd+1, v});
//			} else if (cd+1==d[f][v]) {
//				ap[f][v]++;
//			}
//		}
//	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	int _, T; cin >> _ >> T;
	while (T--) {
		memset(actived, 0, sizeof actived);
		int n; ll dd; cin >> n >> dd;
		ll q[maxn]; int qf=1, qe=0; ll fst=0;
		for (int i=1;i<=n;i++) {
			G[i].clear(); ap[i].clear();
			cin >> x[i]; if (i==1) fst=x[i]; x[i]-=fst;
		}
		memset(d, 0x3f, sizeof d);
		for (int i=1;i<=n;i++) {	
			while (qf<=qe&&x[q[qf]]+dd<x[i]) qf++;
			for (int j=qf; j<=qe; j++) {
				G[i].push_back(q[j]);
				G[q[j]].push_back(i);
				d[i][q[j]]=d[q[j]][i]=1;
			}
			q[++qe]=i;
		}
		int ans=0; floyd(n);
		for (int i=1;i<=n;i++) {
			map<int,int> & mp = ap[i];
			for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++) {
				if (it->second==2&&i!=it->first) {
					if (!actived[i][it->first]&&!actived[it->first][i])  {
						actived[i][it->first]=actived[it->first][i]=1;
						ans++; 
					}
				}
			} 
		}
		cout << ans << '\n';
	}
	return 0;
}

