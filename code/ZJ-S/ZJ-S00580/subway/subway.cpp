#include<bits/stdc++.h>
using namespace std;
long long ttt,n,m,ddd,q,w[500010];
unsigned long long dist[2010][2010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>ttt>>n>>m>>ddd>>q;;
	for(int i=1;i<=2000;i++){
		for(int j=1;j<=2000;j++) dist[i][j]=LONG_LONG_MAX;
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int o,t;
			cin>>o>>t;
			dist[i+m][o]=t;
			dist[o][i+m]=t;
		}
	}
	for(int k=1;k<=n+m;k++){
		for(int i=1;i<=n+m;i++){
			for(int j=1;j<=n+m;j++){
				if(dist[i][k]==LONG_LONG_MAX||dist[k][j]==LONG_LONG_MAX) continue;
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dist[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
//Õ¾Ìü 1-m
//Õ¾Ì¨ m+1-n+m 
