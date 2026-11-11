#include<bits/stdc++.h>
using namespace std;
const int N=610;
long long dist[N][N];
long long c,n,m,d,q;
long long w[N];
void floyd(){
	for(int k=1;k<=n+m;k++){
		for(int i=1;i<=n+m;i++){
			for(int j=1;j<=n+m;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			dist[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++){
			long long a,t;
			cin>>a>>t;
			dist[i][a+n]=min(t,dist[i][a+n]);
			dist[a+n][i]=min(t,dist[a+n][i]);
		}
	}
	floyd();
	while(q--){
		long long x,y;
		cin>>x>>y;
		cout<<dist[n+x][y+n]+w[x]+w[y]<<"\n";
	}
	return 0;
}
