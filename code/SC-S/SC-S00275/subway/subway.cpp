#include<bits/stdc++.h>
using namespace std;
const int N=510,M=500100;
int c,n,m,d,q,w[M],p1[M],p2[M];
vector<pair<int,int>> v[N],e[M];
long long dis[N][N];
int main(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,c,a,k;i<=n;i++){
		cin>>c; while(c--) cin>>a>>k,v[i].push_back({a,k}),e[a].push_back({i,k});
	}
	for(int i=1;i<=n;i++){
		for(auto [a,k]:v[i]) p1[a]=i,p2[a]=k;
		for(int j=i+1;j<=n;j++) for(auto [a,k]:v[j])
			if(p1[a]==i) dis[i][j]=dis[j][i]=min(dis[i][j],0ll+p2[a]+k);
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1,s,t;i<=q;i++){
		cin>>s>>t; long long mi=LLONG_MAX;
		for(auto [x,t1]:e[s]) for(auto [y,t2]:e[t])
			mi=min(mi,dis[x][y]+t1+t2);
		cout<<mi+w[s]+w[t]<<'\n';
	}
	return 0;
}