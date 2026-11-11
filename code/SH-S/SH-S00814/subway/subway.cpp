#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],aij,x,y;
long long tij,dis[505][505],ans;
vector<pair<int,long long> >z[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("sybway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(long long i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&aij,&tij);
			z[aij].push_back(make_pair(i,tij));
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		for(int j=i+1;j<=n;j++){
			dis[i][j]=1e17;
			dis[j][i]=1e17;
		}
	}
	for(int i=1;i<=m;i++){
		for(int p=0;p<z[i].size();p++){
			for(int q=p+1;q<z[i].size();q++){
				dis[z[i][p].first][z[i][q].first]=min(dis[z[i][p].first][z[i][q].first],z[i][p].second+z[i][q].second);
				dis[z[i][q].first][z[i][p].first]=min(dis[z[i][q].first][z[i][p].first],z[i][q].second+z[i][p].second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
					dis[j][i]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	while(q--){
		scanf("%d%d",&x,&y);
		ans=1e17;
		for(int i=0;i<z[x].size();i++){
			for(int j=0;j<z[y].size();j++){
				ans=min(ans,dis[z[x][i].first][z[y][j].first]+z[x][i].second+z[y][j].second);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
