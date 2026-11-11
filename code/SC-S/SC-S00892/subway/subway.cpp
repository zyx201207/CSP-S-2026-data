#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=501005;
int c,n,m,d,q;
int w[N],siz[N];
int dis[505][505];
struct no{
	int u,w;
	bool operator <(const no& x)const{
		return w<x.w;
	}
};
vector<no>ve[N];
void fyd(){
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		for(int p1=0;p1<siz[i];p1++){
			for(int p2=p1+1;p2<siz[i];p2++){
				int u=ve[i][p1].u-m,v=ve[i][p2].u-m;
				int w1=ve[i][p1].w,w2=ve[i][p2].w;
				dis[u][v]=dis[v][u]=dis[u][v]>w1+w2?w1+w2:dis[u][v];
			}
		}
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dis[i][j]=dis[j][i]=(dis[i][j]>dis[i][k]+dis[k][j]?dis[i][k]+dis[k][j]:dis[i][j]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,x;i<=n;i++){
		cin>>x;int u=i+m;
		for(int j=1,a,t;j<=x;j++){
			cin>>a>>t;
			ve[a].push_back({u,t});
			ve[u].push_back({a,t});
		}
	}
	for(int i=1;i<=m;i++)siz[i]=ve[i].size();
	fyd();
	while(q--){
		int u,v,ans=1e18;cin>>u>>v;
		for(int i=0;i<siz[u];i++){
			for(int j=0;j<siz[v];j++){
				int x=ve[u][i].u-m,y=ve[v][j].u-m;
				int w1=ve[u][i].w,w2=ve[v][j].w;
				ans=ans>dis[x][y]+w1+w2?dis[x][y]+w1+w2:ans;
			}
		}
		cout<<ans+w[u]+w[v]<<"\n";
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/