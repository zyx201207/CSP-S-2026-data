#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e2+3,M=5e5+3;
int c,n,m,d,q;
int w[M];
vector<pair<int,int> >p[M];
ll dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int a;
			ll t;
			cin>>a>>t;
			p[a].push_back(pair<int,ll>(i,t));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)	dis[i][j]=1e18;
	}
	for(int k=1;k<=m;k++){
		for(int i=0;i<p[k].size();i++){
			int u=p[k][i].first,t1=p[k][i].second;
			for(int j=i+1;j<p[k].size();j++){
				int v=p[k][j].first,t2=p[k][j].second;
				dis[u][v]=min(dis[u][v],(ll)t1+t2);
			}
		}
	}
	#define dis(i,j) (i<j?dis[i][j]:dis[j][i])
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)	dis[i][j]=min(dis[i][j],dis(i,k)+dis(k,j));
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=1e18;
		for(int i=0;i<p[x].size();i++){
			int u=p[x][i].first,t1=p[x][i].second;
			for(int j=0;j<p[y].size();j++){
				int v=p[y][j].first,t2=p[y][j].second;
				ans=min(ans,dis(u,v)+t1+t2);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}