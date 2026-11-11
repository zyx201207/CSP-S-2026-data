#include<iostream>
using namespace std;
int op,n,m,d,q,k,a,t,cnt[500010],u,v,w[500010];
long long f[510][510],ans;
struct node{
	int num,len;
} g[500010][23];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> op >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=1e18;
		}
		f[i][i]=0;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a,&t);
			g[a][++cnt[a]]={i,t};
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=1;k<=cnt[i];k++){
				//printf("%d %d %d\n",i,j,k);
				f[g[i][j].num][g[i][k].num]=min(f[g[i][j].num][g[i][k].num],0ll+g[i][j].len+g[i][k].len);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		//f[i][i]=0;
//		for(int j=1;j<=n;j++){
//			printf("%d ",f[i][j]);
//		}
//		printf("\n");
//	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			printf("%d ",f[i][j]);
//		}
//		printf("\n");
//	}
	while(q--){
		scanf("%d%d",&u,&v);
		ans=1e18;
		for(int i=1;i<=cnt[u];i++){
			for(int j=1;j<=cnt[v];j++){
				ans=min(ans,0ll+f[g[u][i].num][g[v][j].num]+g[u][i].len+g[v][j].len);
			}
		}
		printf("%lld\n",0ll+w[u]+w[v]+ans);
	}
	return 0;
}