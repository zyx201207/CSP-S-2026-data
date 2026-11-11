#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
ll w[500005]; 
ll k[505];
ll a[505][25];
ll t[505][25];
ll dis[2005][2005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j)
			cin>>a[i][j]>>t[i][j];
	}	
		for(int i=1;i<=m;++i){
			for(int j=1;j<=m;++j){
				dis[i][j]=1e15;
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=k[i];++j){
				for(int p=j+1;p<=k[i];++p){
					dis[a[i][p]][a[i][j]]=t[i][j]+t[i][p];
					dis[a[i][j]][a[i][p]]=t[i][j]+t[i][p];
				}
			}
		}
		for(int k=1;k<=m;++k){
			for(int i=1;i<=m;++i){
				for(int j=1;j<=m;++j){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		for(int i=1;i<=q;++i){
			int x,y;cin>>x>>y;
			cout<<w[x]+dis[x][y]+w[y]<<'\n';
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
---
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
