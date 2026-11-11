#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int c;
int n,m,d,q;
int w[500050];
vector<pii> line[505];
vector<pii> plat[500050];
long long a[505][505];
long long dis[505][505];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    scanf("%d",&c);
    scanf("%d%d%d%d",&n,&m,&d,&q);
    for(int i=0;i<=n;i++){
    	fill(a[i],a[i]+n+1,1e18);
   		fill(dis[i],dis[i]+n+1,1e18);
	}
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
   	for(int i=1,k;i<=n;i++){
    	scanf("%d",&k);
    	for(int j=0;j<k;j++){
    		int x,y;
			scanf("%d%d",&x,&y);
			line[i].push_back({x,y});plat[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(int u=0;u<plat[i].size();u++){
			for(int v=u+1;v<plat[i].size();v++){
				pii x=plat[i][u],y=plat[i][v];
				if(a[x.first][y.first]>x.second+y.second) a[x.first][y.first]=x.second+y.second;
			}
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=a[i][j];
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(dis[i][j]>dis[i][k]+dis[k][j]) dis[i][j]=dis[i][k]+dis[k][j];
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=1e18;
		for(int i=0;i<plat[x].size();i++){
			for(int j=0;j<plat[y].size();j++){
				pii u=plat[x][i],v=plat[y][j];
				if(u.first>v.first) swap(u,v);
				if(ans>dis[u.first][v.first]+u.second+v.second) ans=dis[u.first][v.first]+u.second+v.second;
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
