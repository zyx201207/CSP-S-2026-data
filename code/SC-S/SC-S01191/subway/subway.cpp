#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const ll INF=5e18;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m+1);
	for(int i=1;i<=m;i++)
		cin>>w[i];
	vector<vector<ll>> f(n+1,vector<ll>(n+1,INF));
	for(int i=1;i<=n;i++)
		f[i][i]=0;
	vector<vector<pii>> G(m+1);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			G[a].pb({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		int len=G[i].size();
		for(int j=0;j<len-1;j++)
			for(int k=j+1;k<len;k++){
				int a1=G[i][j].fi,a2=G[i][k].fi,t1=G[i][j].se,t2=G[i][k].se;
				f[a1][a2]=f[a2][a1]=min(f[a1][a2],1ll*t1+t2);
			}
	}
	for(int j=1;j<=n;j++)
		for(int i=1;i<=n;i++)
			for(int k=1;k<=n;k++)
				if(f[i][k]!=INF&&f[k][j]!=INF)  f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=INF;
		for(int i=0;i<G[x].size();i++)
			for(int j=0;j<G[y].size();j++){
				int a1=G[x][i].fi,a2=G[y][j].fi,t1=G[x][i].se,t2=G[y][j].se;
				ans=min(ans,1ll*t1+1ll*t2+1ll*f[a1][a2]);
			}
		ans+=1ll*w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
}