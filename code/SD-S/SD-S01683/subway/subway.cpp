#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k[505];
int w[500005];
int dis[500005];
int a[505][505];
int t[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){//铁线路 
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
//		dijkstra(x);
//		cout<<dis[y];
		int ans=0;
		ans+=w[x];
		int now=x;
		while(now!=y){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=k[i];j++){
					if(a[i][j]==now){
						ans+=t[i][j];
						ans+=t[i+1][j];
						now=a[i+1][j];
					}
				}
			}
		}
		cout<<ans+w[y]<<'\n';
	}
	return 0;
}
