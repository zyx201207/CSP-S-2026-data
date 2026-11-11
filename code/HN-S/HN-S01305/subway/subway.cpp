#include<bits/stdc++.h>
using namespace std;
const long long inf=1e10+7;
int w[500005],k[505];
long long y[505][505];
vector<int>a[505],t[505],e[500005],f[500005];
struct node{
	int u,v;
}to[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			int x,y;
			scanf("%d%d",&x,&y);
			a[i].push_back(x);
			t[i].push_back(y);
			e[x].push_back(i); 
			f[x].push_back(y);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			y[i][j]=inf;
		}
		y[i][i]=0;
	} 
	for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size();j++){
			for(int k=j+1;k<e[i].size();k++){
//				cout<<i<<" "<<e[i][j]<<" "<<e[i][k]<<" "<<f[i][j]<<" "<<f[i][k]<<"\n";
				if(y[e[i][j]][e[i][k]]>(long long)f[i][j]+f[i][k]){
					y[e[i][k]][e[i][j]]=y[e[i][j]][e[i][k]]=(long long)f[i][j]+f[i][k];
					to[e[i][j]][e[i][k]].u=to[e[i][j]][e[i][k]].v=to[e[i][k]][e[i][j]].u=to[e[i][k]][e[i][j]].v=i;
				}y[e[i][k]][e[i][j]]=y[e[i][j]][e[i][k]]=min(y[e[i][j]][e[i][k]],(long long)f[i][j]+f[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(y[i][k]+y[k][j]<y[i][j]){
					to[j][i].v=to[i][j].u=to[i][k].u;
					to[i][j].v=to[j][i].u=to[k][j].v;
					y[i][j]=y[i][k]+y[k][j];
				}
				y[i][j]=min(y[i][j],y[i][k]+y[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<y[i][j]<<" ";
//		}cout<<"\n";
//	}
	while(q--){
		int x,p;
		long long ans=inf;
		scanf("%d%d",&x,&p);
		for(int i=0;i<e[x].size();i++){
			for(int j=0;j<e[p].size();j++){
//				long long tot=y[e[x][i]][e[p][j]]+w[x]+w[p];
//				if(to[e[x][i]][e[p][i]].u!=x){
//					tot+=f[x][i];
//				}
//				if(to[e[x][i]][e[p][i]].v!=p){
//					tot+=f[p][j];
//				}
				long long tot=y[e[x][i]][e[p][j]]+w[x]+w[p]+f[x][i]+f[p][j];
//				cout<<tot<<" "<<e[x][i]<<" "<<e[p][j]<<" "<<f[x][i]<<" "<<f[p][j]<<"\n";
				ans=min(ans,tot);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
