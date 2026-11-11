#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+10,N=510;
int w[M],k[N],dis[N][N];
vector<pair<int,int>> e[M];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=1e18;
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;cin>>a>>t;
			for(auto c:e[a]){
				int v=c.first,w=c.second;
				dis[v][i]=dis[i][v]=min(dis[v][i],w+t);
			}e[a].push_back({i,t});
		}
	}for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
//	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++) cout<<dis[i][j]<<" ";cout<<endl;}
	for(int _=1;_<=q;_++){
		int x,y;cin>>x>>y;
		int ans=w[x]+w[y],tmp=1e18;
		for(auto c1:e[x]){
			for(auto c2:e[y]){
				int v1=c1.first,v2=c2.first;
				tmp=min(tmp,dis[v1][v2]+c1.second+c2.second);
			}
		}cout<<ans+tmp<<'\n';
	}
	return 0;
}