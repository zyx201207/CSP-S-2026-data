#include<bits/stdc++.h>
using namespace std;
const long long INF=1e18;
int c,n,m,D,q;
long long ww[509],d[509][509];
vector<int> vv[500009],w[500009];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++){
		cin>>ww[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			vv[a].push_back(i);
			w[a].push_back(t);
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			d[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++)d[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<vv[i].size();j++){
			for(int k=j+1;k<vv[i].size();k++){
				long long u=vv[i][j],v=vv[i][k],W=w[i][j]+w[i][k];
				d[u][v]=min(d[u][v],W);
				d[v][u]=min(d[v][u],W);
			}
		}
	}
	
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(d[i][k]==INF)continue;
				if(d[j][k]==INF)continue;
				if(d[i][k]+d[k][j]<=d[i][j]){
					d[i][j]=d[i][k]+d[k][j];
					d[j][i]=d[i][j];
				}
			}
		}
	}
	
	
	for(int i=1;i<=q;i++){
		long long x,y,ans=INF;
		cin>>x>>y;
		for(int j=0;j<vv[x].size();j++){
			for(int k=0;k<vv[y].size();k++){
				long long u=vv[x][j],v=vv[y][k],W=w[x][j]+w[y][k];
				W+=d[u][v];
				ans=min(ans,W);
			}
		}
		cout<<ans+ww[x]+ww[y]<<"\n";
	}
	
	
	return 0;
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
