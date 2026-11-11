#include<bits/stdc++.h>
using namespace std;
const int N=510,M=500010;
long long c,n,m,d,q,w[M],k[N],dis[N][N],u,v,ans;
vector<pair<int,int> > e[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,a,t;j<=k[i];j++)cin>>a>>t,e[a].push_back(make_pair(i,t));
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j)dis[i][j]=0;
			else dis[i][j]=1e15;
	for(int i=1;i<=m;i++)
		for(int j=0;j<e[i].size();j++)
			for(int k=0;k<e[i].size();k++)
				dis[e[i][j].first][e[i][k].first]=min(dis[e[i][j].first][e[i][k].first],1ll*e[i][j].second+1ll*e[i][k].second);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		cin>>u>>v;
		ans=1e15;
		for(int j=0;j<e[u].size();j++)
			for(int k=0;k<e[v].size();k++)
				ans=min(ans,1ll*e[u][j].second+1ll*e[v][k].second+dis[e[u][j].first][e[v][k].first]);
		ans+=w[u]+w[v];
		cout<<ans<<"\n";
	}
	return 0;
}
