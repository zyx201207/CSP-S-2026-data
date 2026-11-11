//SN-S00531 张之奇 西安市铁一中学
#include <bits/stdc++.h>
using namespace std;

const long long inf=1e18;
const int maxn=505;
const int maxm=5e5+5;
int c,n,m,d,q;
long long w[maxm];
long long f[maxn][maxn];
vector<pair<int,long long> > G[maxm];

void solve(){
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)	cin>>w[i];
	for (int i=1;i<=n;i++){
		int k; cin>>k;
		for (int j=1;j<=k;j++){
			int a; long long t;
			cin>>a>>t;
			G[a].push_back({i,t});
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)	f[i][j]=inf;
		f[i][i]=0;
	}
	for (int i=1;i<=m;i++){
		for (auto j:G[i]) for (auto k:G[i]){
			int u=j.first,v=k.first;
			f[u][v]=min(f[u][v],j.second+k.second);
			f[v][u]=min(f[v][u],j.second+k.second);
		}
	}
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=n;j++){
//			cout<<f[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
//	for (int i=1;i<=m;i++){
//		for (auto j:G[i])	cout<<j.first<<" "<<j.second<<"\n";
//		cout<<"\n";
//	}
	for (int k=1;k<=n;k++)
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while (q--){
		int x,y; cin>>x>>y;
		long long ans=inf;
		for (auto i:G[x]) for (auto j:G[y])
			ans=min(ans,i.second+j.second+f[i.first][j.first]);
//		cout<<ans<<"\n";
		cout<<ans+w[x]+w[y]<<"\n";
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
//	int T;for (cin>>T;T--;)
	solve();
	return 0;
} 
