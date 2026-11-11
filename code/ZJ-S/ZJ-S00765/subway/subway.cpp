#include<bits/stdc++.h>
using namespace std;
#define int long long
int i,j,x,y,z,n,m,d,q,c,dis[5010][5010]
,k[1000010],X[1000010],a[1000010],t[1000010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(dis,63,sizeof(dis));
	for(i=1;i<=m;i++)
		cin>>X[i];
	for(i=1;i<=n;i++){
		cin>>k[i];dis[i][i]=0;
		for(j=1;j<=k[i];j++){
			cin>>a[j]>>t[j]; 
		}
		for(x=1;x<=k[i];x++)
			for(y=x+1;y<=k[i];y++){
				dis[a[x]][a[y]]=min(dis[a[x]][a[y]],t[x]+t[y]);
				dis[a[y]][a[x]]=min(dis[a[y]][a[x]],t[x]+t[y]);
			}
	}
	for(z=1;z<=m;z++)
	for(x=1;x<=m;x++)
	for(y=1;y<=m;y++)
		dis[x][y]=min(dis[x][y],dis[x][z]+dis[z][y]),
		dis[y][x]=dis[x][y];
	while(q--){
		cin>>x>>y;
		cout<<dis[x][y]+X[x]+X[y]<<"\n";
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
