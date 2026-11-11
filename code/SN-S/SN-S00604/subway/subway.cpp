#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=505;
int c,n,m,d,q,l[M],e[M][N];
ll line[M][M],w[N],INF,k;
vector<ll>g[N],p[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(line,0x3f,sizeof(line));
	memset(e,0x3f,sizeof(e));
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>l[i];
		for(int j=1;j<=l[i];j++){
			ll u,v;
			cin>>u>>v;
			e[i][u]=v;
			g[i].push_back(u);
			p[u].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(auto it:g[i]){
			for(int j=1;j<=n;j++){
				if(i==j)line[i][j]=0;
				line[i][j]=line[j][i]=min(line[i][j],ll(e[i][it]+e[j][it]));
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			for(int x=1;x<=n;x++){
				if(j==x)continue;
				line[j][x]=line[x][j]=min(line[j][x],line[j][i]+line[i][x]);
			}
		}
	}
	while(q--){
		int u,v;
		ll ans=LLONG_MAX;
		cin>>u>>v;
		for(auto i:p[u]){
			for(auto j:p[v]){
				ans=min(e[i][u]+line[i][j]+e[j][v],ans);
			}
		}
		ans+=w[u]+w[v];
		cout<<ans<<'\n';
	}
	return 0;
}
