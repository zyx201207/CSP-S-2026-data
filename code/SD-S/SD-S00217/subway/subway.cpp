#include<bits/stdc++.h>
using namespace std;
const int N=1010;
long long  dist[N][N];
long long cst[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>cst[i];
	}
	for(int i=1;i<=n+m;i++){
		for(int j=1;j<=n+m;j++){
			dist[i][j]=-1;
		}
	}
	for(int i=1;i<=n;i++){
		int k,w,v;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>v>>w;
			dist[i+m][v]=w;
			dist[v][i+m]=w;
		}
	}
	for(int i=n+m;i>=1;i--){
		for(int j=n+m;j>=1;j--){
			if(i==j)continue;
			for(int k=1;k<=n+m;k++){
				if(i==k||k==j)continue;
				if(dist[i][j]!=-1&&dist[j][k]!=-1){
					if(dist[i][k]!=-1){
						dist[i][k]=min(dist[i][j]+dist[j][k],dist[i][k]);
					}
					else{
						dist[i][k]=dist[i][j]+dist[j][k];	
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int a,b;
		cin>>a>>b;
		cout<<dist[a][b]+cst[a]+cst[b]<<endl;
	}
	return 0;
}
