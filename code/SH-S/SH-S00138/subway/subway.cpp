#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int M=500005,N=505;
struct node{
	int v,w;
};
int c,n,m,d,q,w[M];
ll dis[N][N];
vector<node>mp[M+N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		for(int j=1;j<=k;j++){
			int a,t; cin>>a>>t;
			for(auto v:mp[a])
				if(dis[v.v][i]>t+v.w)
					dis[v.v][i]=dis[i][v.v]=t+v.w;
			mp[a].push_back({i,t});
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y; cin>>x>>y;
		ll ans=LLONG_MAX;
		int cnt=0;
		for(auto u:mp[x])
			for(auto v:mp[y])
				ans=min(ans,(long long)w[x]+w[y]+dis[u.v][v.v]+u.w+v.w),++cnt;
		cout<<ans<<'\n';
	}
	return 0;
}
