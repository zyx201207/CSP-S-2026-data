#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
int w[M];
int p[M][505];
int d[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,D,q;cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			p[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			p[a][i]=t;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			d[i][j]=INT_MAX;
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if((p[k][i]!=INT_MAX)&&(p[k][j]!=INT_MAX))
				d[i][j]=min(d[i][j],p[k][i]+p[k][j]);
				//if(d[i][j]<0)cout<<"!!!"<<p[k][i]<<" "<<p[k][j]<<endl;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if((d[i][k]!=INT_MAX)&&(d[k][j]!=INT_MAX))
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	while(q--){
		int u,v;cin>>u>>v;
		int mn=INT_MAX;
		for(int i=1;i<=n;i++){
			if((p[u][i]!=INT_MAX)&&(p[v][i]!=INT_MAX)){
				mn=min(mn,p[u][i]+p[v][i]);
			}
		}
		for(int i=1;i<=n;i++){
			if(p[u][i]!=INT_MAX){
				for(int j=1;j<=n;j++){
					if(p[v][j]!=INT_MAX){
						mn=min(mn,d[i][j]+p[v][j]+p[u][i]);
					}
				}
			}
		}
		cout<<w[u]+mn+w[v]<<endl;
	}
	return 0;
}