#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,w;
};
int c,n,m,d,q;
int w[500005];
int a[500005];
int t[500005];
int k[500005];
int x[100005],y[100005];
int dist[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=m;i++){
		//cin>>w[i];
		scanf("%d",&w[i]);
	} 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			//cin>>a[j]>>t[j];
			scanf("%d%d",&a[j],&t[j]);
		}
		
		for(int j=1;j<=k[i];j++){
			for(int l=1;l<=k[i];l++){
				if(j==l) continue;
				int u=a[j],p=a[l];
				int x=t[j]+t[l];
				dist[u][p]=x;
				dist[p][u]=x;
			}
		}
	}
	for(int i=1;i<=m;i++) dist[i][i]=0;
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			if(dist[i][k]==0x3f) continue;
			for(int j=1;j<=m;j++){
				if(dist[i][k]+dist[k][j]<dist[i][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		//cin>>x[i]>>y[i];
		scanf("%d%d",&x[i],&y[i]);
		//cout<<dist[x[i]][y[i]]+w[x[i]]+w[y[i]]<<'\n';
		printf("%d\n",dist[x[i]][y[i]]+w[x[i]]+w[y[i]]);
		
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

