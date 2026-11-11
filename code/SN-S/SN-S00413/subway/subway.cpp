#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5,M=505;
const ll inf=1e17;
struct nd{int x,d;};
vector<nd>g[N];
int c,n,m,D,q,w[N];
ll d[M][M];
signed main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>c>>n>>m>>D>>q;for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;while(k--){
			int x,d;cin>>x>>d;g[x].push_back({i,d});
		} 
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)d[i][j]=inf;
	for(int i=1;i<=m;i++){
		for(nd u:g[i])for(nd v:g[i])if(u.x!=v.x){
			ll ret=u.d+v.d;
			d[u.x][v.x]=min(d[u.x][v.x],ret);
		}
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			d[j][i]=min(d[j][i],d[i][k]+d[k][j]);
		}
	} 
	while(q--){
		int x,y;cin>>x>>y;ll ans=inf;
		for(nd u:g[x])for(nd v:g[y]){
			ll ret=d[u.x][v.x];
			ret+=u.d;ret+=v.d;ret+=w[x];ret+=w[y];
			ans=min(ans,ret);
		}
		cout<<ans<<'\n';
	}
	return 0;
}

