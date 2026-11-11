#include<bits/stdc++.h>
using namespace std;
struct node{
	int p,t;
}a[500005];
int c,n,m,d,q,w[500005],k[500005],x,y,dis[10005][10005],vis[500005];
void floyd(){
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
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
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j].p>>a[j].t;
			vis[a[j].p]=a[j].t;
		}
		for(int j=1;j<=k[i];j++){
			for(int l=j+1;l<=k[i];l++){
				dis[a[j].p][a[l].p]=a[j].t;
				dis[a[l].p][a[j].p]=a[l].t;
				for(int e=j+1;e<=l;e++){
					dis[a[j].p][a[l].p]+=a[e].t;
				}
				for(int e=l-1;e>=j;e--){
					dis[a[l].p][a[j].p]+=a[e].t;
				}
				if(vis[a[l].p]){
					dis[a[j].p][a[l].p]+=vis[a[l].p];
				}
				else if(vis[a[j].p]){
					dis[a[j].p][a[l].p]+=vis[a[j].p];
				}
			}
		}
	}
	floyd();
	for(int i=1;i<q;i++){
		cin>>x>>y;
		cout<<w[x]+dis[x][y]+w[y]<<endl;
	}
	cin>>x>>y;
	cout<<w[x]+dis[x][y]+w[y];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
