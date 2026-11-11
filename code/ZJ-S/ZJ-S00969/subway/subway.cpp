#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

const int N = 500005, M = 505;
const ll Inf = 1e18;
ll Time[N], W[M][M];
vector<PII> G[N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int TestID, n, m, d, q;	cin>>TestID>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)	cin>>Time[i];
	for(int i=1;i<=m;i++) {
		int k, v, w;	cin>>k;
		for(int j=1;j<=k;j++)	cin>>v>>w, G[v].push_back({i, w});
	}
	
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++)	W[i][j]=(i!=j)*Inf;
	for(int i=1;i<=n;i++) for(PII E1: G[i]) for(PII E2: G[i])
		if(E1.first!=E2.first) {
			int u=E1.first, v=E2.first;ll w=E1.second+E2.second;
			W[u][v]=min(W[u][v], w), W[v][u]=W[u][v];
		}
	
	for(int k=1;k<=m;k++) for(int i=1;i<=m;i++) for(int j=1;j<=m;j++)
		W[i][j]=min(W[i][j], W[i][k]+W[k][j]);
	
	for(int i=1;i<=q;i++) {
		int u, v;ll Ans=Inf;	cin>>u>>v;
		for(PII E1: G[u]) for(PII E2: G[v])
			Ans=min(Ans, E1.second+E2.second+W[E1.first][E2.first]);
		cout<<Ans+Time[u]+Time[v]<<'\n';
	}
	return 0;
}
