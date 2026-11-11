#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
ll f[510][510],w[500010];
vector<pair<int,ll> >g[500010],e[510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;cin>>x>>t;
			g[x].push_back(make_pair(i,t));
			e[i].push_back(make_pair(x,t));
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=n;i++)
		for(auto &it : e[i])
			for(auto &ii : g[it.first])
				f[i][ii.first]=min(f[i][ii.first],it.second+ii.second);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y;cin>>x>>y;
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(auto &it : g[x])
			for(auto &ii : g[y])ans=min(ans,it.second+ii.second+f[it.first][ii.first]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
