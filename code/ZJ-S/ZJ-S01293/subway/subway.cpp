#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
const long long INF=0x3f3f3f3f3f3f3f3f;

int c,n,m,d,q;
long long w[M],dis[N][N];

struct Edge{
	int v;
	long long w;
};
vector<Edge> g[M];

void Floyd(){
	for (int k=1;k<=n;k++){
		for (int i=1;i<n;i++){
			for (int j=i+1;j<=n;j++){
				if  (i==k || k==j)  continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				dis[j][i]=dis[i][j];
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)  cin>>w[i];
	for (int i=1;i<=n;i++){
		int k;
		cin>>k;
		while (k--){
			int a;
			long long t;
			cin>>a>>t;
			g[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for (int i=1;i<=n;i++)  dis[i][i]=0;
	for (int i=1;i<=m;i++){
		for (auto j:g[i]){
			for (auto k:g[i]){
				dis[j.v][k.v]=min(dis[j.v][k.v],j.w+k.w);
				dis[k.v][j.v]=min(dis[k.v][j.v],j.w+k.w);
			}
		}
	}
	Floyd();
	while (q--){
		int x,y;
		long long res=INF;
		cin>>x>>y;
		for (auto i:g[x]){
			for (auto j:g[y]){
				res=min(res,i.w+j.w+dis[i.v][j.v]);
			}
		}
		cout<<res+w[x]+w[y]<<'\n';
	}
	return 0;
}