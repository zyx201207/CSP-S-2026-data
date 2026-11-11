#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX=1e18;
int SS,n,m,d,q,i,j,k,k2,l,s1,s2,x,y,a,t,mi,ans,W[500010],dis[510][510];
vector<int>g[500510],w[500510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>SS>>n>>m>>d>>q;
	for(i=1;i<=m;i++)
		cin>>W[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)dis[i][j]=MAX;
	for(i=1;i<=n;i++)dis[i][i]=0;
	for(i=1;i<=n;i++){
		cin>>x;
		for(j=1;j<=x;j++){
			cin>>a>>t;
			g[a].push_back(i+m);
			w[a].push_back(t);
			g[i+m].push_back(a);
			w[i+m].push_back(t);
		}
	}
	for(i=m+1;i<=m+n;i++)
		for(j=0;j<g[i].size();j++){
			k=g[i][j];
			for(l=0;l<g[k].size();l++){
				k2=g[k][l];
				if(i!=k2)dis[i-m][k2-m]=min(dis[i-m][k2-m],w[i][j]+w[k][l]);
			}
		}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			if(dis[j][i]==MAX)continue;
			for(k=1;k<=n;k++)
				if(dis[j][i]!=MAX&&dis[i][k]!=MAX)
					dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
		}
	while(q--){
		cin>>x>>y;mi=2e9;
		for(i=0;i<g[x].size();i++)
			for(j=0;j<g[y].size();j++){
				s1=g[x][i];
				s2=g[y][j];
				mi=min(mi,W[x]+W[y]+w[x][i]+w[y][j]+dis[s1-m][s2-m]);
			}
		cout<<mi<<"\n";
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3