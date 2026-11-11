#include<bits/stdc++.h>
using namespace std;
long long mxfw=1e18;
long long dist[5005][5005],w[500005];
long long a[5000005]={},t[500005]={};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j) dist[i][j]=0;
			else dist[i][j]=mxfw;
		}
	}
	for(int i=0;i<n;i++){
		long long k;
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>a[j]>>t[j];
		}
		for(int u=0;u<k;u++){
			for(int v=u+1;v<k;v++){
				long long su=a[u],sv=a[v];
				
				if(su>=1 and su<=m and sv>=1 and sv<=m){
					long long cost=t[u]+t[v];	
					if(cost<dist[su][sv]){
						dist[su][sv]=cost;
						dist[sv][su]=cost;
					}
				}
				
			} 
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			if(dist[i][k]==mxfw) continue;
			for(int j=1;j<=m;j++){
				if(dist[k][j] != mxfw and dist[i][k]+dist[k][j]<dist[i][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	for(int i=0;i<q;i++){
			long long x,y;
			cin>>x>>y;
			if(x<1 or x>m or y<1 or y>m) cout<<"-1"<<endl;
			if(x==y) cout<<"0"<<endl;
			else cout<<w[x]+dist[x][y]+w[y]<<endl;
	}
	return 0;
}
