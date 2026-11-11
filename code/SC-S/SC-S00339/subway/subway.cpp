#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int M=500010,N=510;
int w[M],k[N];
vector<int>a[N],t[N];
vector<pii>G[M];
int dist[M];
void evoker444_was_slain_by_cyq142857(int s){
	memset(dist,-1,sizeof(dist));
	queue<int>q;
	q.push(s);
	dist[s]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(pii mbpsz:G[u]){
			int v=mbpsz.first;
			int w=mbpsz.second;
			if(dist[v]==-1) dist[v]=dist[u]+w;
			else if(dist[u]+w<dist[v]) dist[v]=dist[u]+w;
			else continue;
			q.push(v);
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;i++){
		cin >> w[i];
	}
	for(int i = 1;i<=n;i++){
		cin >> k[i];
		a[i].push_back(k[i]);
		t[i].push_back(k[i]);
		int aij=0,tij=0;
		for(int j = 1;j<=k[i];j++){
			cin >> aij >> tij;
			a[i].push_back(aij);
			t[i].push_back(tij);
		}
		for(int j = 1;j<=k[i];j++){
			for(int kk = 1;kk<=k[i];kk++){
				if(j==kk) continue;
				int u=a[i][j],v=a[i][kk];
				G[u].push_back({v,t[i][j]+t[i][kk]});
			}
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		evoker444_was_slain_by_cyq142857(x);
		cout << dist[y]+w[x]+w[y];
		cout << '\n';
	}
	return 0;
}