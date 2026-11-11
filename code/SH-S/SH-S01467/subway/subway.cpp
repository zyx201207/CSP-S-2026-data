#include<bits/stdc++.h>
using namespace std;
const int maxn=505,maxm=5e5+5,inf=1e15+7;
long long c,n,m,d,q,k[maxn],w[maxm],cnt[maxm],e[maxn][maxn];
struct node{
	int id;
	long long val;
}mn[maxm][27];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) e[i][j]=inf;
	}
	for(int i=1;i<=n;i++){//i是线点 
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			long long a,t;
			cin>>a>>t;//a是站点,.id是线点 
			mn[a][++cnt[a]].id=i;
			mn[a][cnt[a]].val=t;
			for(int l=1;l<cnt[a];l++){
				e[i][mn[a][l].id]=min(e[i][mn[a][l].id],t+mn[a][l].val);
				e[mn[a][l].id][i]=min(e[i][mn[a][l].id],t+mn[a][l].val);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j) e[i][j]=0;
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				e[i][j]=min(e[i][j],e[i][l]+e[l][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		long long x,y,ans=inf;
		cin>>x>>y;
//	for(int x=1;x<=m;x++){
//		for(int y=1;y<=m;y++){
//			long long ans=inf;
			for(int s=1;s<=cnt[x];s++){
				for(int t=1;t<=cnt[y];t++){
					ans=min(ans,w[x]+w[y]+mn[x][s].val+mn[y][t].val+e[mn[x][s].id][mn[y][t].id]);
				}
			}
			cout<<ans<<endl;
//		}
	}
//	for(int i=1;i<=m;i++){
//		cout<<i<<endl;
//		for(int j=1;j<=cnt[i];j++){
//			cout<<mn[i][j].id<<' '<<mn[i][j].val<<endl;
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<i<<' '<<j<<' '<<e[i][j]<<endl;
//		}
//	}
}
//0 3 7 20 2
//1 1 1 1 1 1 1
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7

