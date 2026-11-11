#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=600,M=5e5+7;
int i,j,k,c,n,m,d,q,u,w,kk,x,y;
int ww[M],dis[N][N];
struct no{
	int to,w;
};
vector<no>a[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++) cin>>ww[i];
	for(i=1;i<=n;i++){
		cin>>kk;
		for(j=1;j<=kk;j++){
			cin>>u>>w;
			a[u].push_back((no){i,w});
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i!=j) dis[i][j]=1e18;
			else dis[i][j]=0;
	for(i=1;i<=m;i++){
		int len=a[i].size();
		for(j=0;j<len;j++)
			for(k=0;k<len;k++)
				if(j!=k) dis[a[i][j].to][a[i][k].to]=min(dis[a[i][j].to][a[i][k].to],a[i][j].w+a[i][k].w);
	}
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			if(i!=k)
				for(j=1;j<=n;j++)
					if(i!=j&&k!=j)				
						dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		cin>>x>>y;
		int len1=a[x].size();
		int len2=a[y].size();
		int mi=1e18;
		for(i=0;i<len1;i++)
			for(j=0;j<len2;j++){
				mi=min(mi,dis[a[x][i].to][a[y][j].to]+a[x][i].w+a[y][j].w);
			}
		cout<<mi+ww[x]+ww[y]<<"\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
