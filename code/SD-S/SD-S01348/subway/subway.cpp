#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=5e5+5;
const long long inf=1e18;
vector<pair<int,int> >a[M];
int c,n,m,q,d;
int b[M];
long long f[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++)f[i][i]=0ll;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,w;
			cin>>u>>w;
			for(auto y:a[u]){
				int v=y.first,ww=y.second;
				f[i][v]=min(f[i][v],(long long)ww+w);
				f[v][i]=min(f[v][i],(long long)ww+w);
			}
			a[u].push_back(make_pair(i,w));
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		long long ans=inf;
		for(auto c:a[u]){
			for(auto d:a[v]){
				ans=min(ans,f[c.first][d.first]+c.second+d.second+b[u]+b[v]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
