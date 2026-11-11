#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> PI;
const int N=510,M=5e5+10,inf=0x3f3f3f3f3f3f3f3f;
int C,n,m,d,q;
int dis[N][N],top[M],w[M];
vector<PI> t[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i],t[i].push_back({0,0});
	for(int i=1;i<=n;i++){
		int k,x,y;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			t[x].push_back({y,i});
			top[x]++;
		}
		dis[i][i]=0;
	}
	for(int x=1;x<=m;x++){
		for(int i=1;i<=top[x];i++){
			for(int j=i+1;j<=top[x];j++){
				int u=t[x][i].second;
				int v=t[x][j].second;
				dis[u][v]=dis[v][u]=min(dis[u][v],t[x][i].first+t[x][j].first);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(dis[i][k]!=inf&&dis[k][j]!=inf)
					dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	int x,y,res;
	while(q--){
		cin>>x>>y;
		res=inf;
		for(int i=1;i<=top[x];i++){
			for(int j=1;j<=top[y];j++){
				int u=t[x][i].second;
				int v=t[y][j].second;
				if(dis[u][v]!=inf){
					res=min(res,dis[u][v]+t[x][i].first+t[y][j].first);
				}
			}
		}
		cout<<res+w[x]+w[y]<<'\n';
	}
	return 0;
}
