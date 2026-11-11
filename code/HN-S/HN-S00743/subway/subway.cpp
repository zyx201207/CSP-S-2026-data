#include<bits/stdc++.h>
using namespace std;

struct sNode{
	long long a,t;
};

vector<sNode> ve[505];
long long c,n,m,d,q,x,y;
long long w[500005];
long long dis[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			if(i!=j){
				dis[i][j]=1e18;
			}
		}
	}
	for(long long i=1;i<=n;i++){
		cin>>c;
		for(long long j=1;j<=c;j++){
			cin>>x>>y;
			if(ve[x].size()){
				for(long long k=0;k<ve[x].size();k++){
					sNode v=ve[x][k];
					dis[i][v.a]=dis[v.a][i]=min(min(dis[i][v.a],dis[v.a][i]),v.t+y);
				}
			}
			ve[x].push_back({i,y});
		}
	}
	for(long long k=1;k<=n;k++){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>x>>y;
		long long ans=1e18;
		for(long long j=0;j<ve[x].size();j++){
			for(long long k=0;k<ve[y].size();k++){
				ans=min(dis[ve[x][j].a][ve[y][k].a]+ve[x][j].t+ve[y][k].t,ans);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
} 
