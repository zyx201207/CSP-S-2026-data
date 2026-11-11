#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=509,M=5e5+9,inf=1e18;
ll c,n,m,d,q,cs[M],w[N][N];
vector<ll>sl[M],st[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>cs[i];
	for(ll i=1;i<=n;i++){
		ll k;cin>>k;
		for(ll j=1;j<=k;j++){
			ll u,uu;cin>>u>>uu;
			sl[u].push_back(i),st[u].push_back(uu);
		}
	}
	for(ll i=1;i<=n;i++)for(ll j=1;j<=n;j++)
		w[i][j]=inf;
	for(ll i=1;i<=n;i++)w[i][i]=0;
	for(ll i=1;i<=m;i++){
		for(ll j=0;j<sl[i].size();j++)
			for(ll k=j+1;k<sl[i].size();k++){
				ll nw=st[i][j]+st[i][k];
				if(w[sl[i][j]][sl[i][k]]>nw)
					w[sl[i][j]][sl[i][k]]=w[sl[i][k]][sl[i][j]]=nw;
			}
	}
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)for(ll k=1;k<=n;k++)
			w[j][k]=min(w[j][k],w[j][i]+w[i][k]);
	while(q--){
		ll u,v,rs=inf;cin>>u>>v;
		for(ll i=0;i<sl[u].size();i++)
			for(ll j=0;j<sl[v].size();j++)
				rs=min(rs,st[u][i]+st[v][j]+w[sl[u][i]][sl[v][j]]);
		cout<<(rs+cs[u]+cs[v])<<"\n";
	}
	return 0;
}
