#include<cstdio>
int min(int a,int b){
	if(a==0)return b;
	return a<b?a:b;
}
const int MAXN=505,MAXM=500005;
int e[MAXN][MAXN],e1[MAXN][MAXM];
int ans,st,ed,a,b,k,c,n,m,d,q,w[MAXM];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;++i){
		scanf("%d",&k);
		for(int j=1;j<=k;++j){
			scanf("%d%d",&a,&b);
			e1[i][a]=b;
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			for(int k=j+1;k<=n;++k){
				if(e1[j][i]&&e1[k][i])e[j][k]=e[k][j]=min(e[j][k],e1[j][i]+e1[k][i]);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			for(int k=1;k<=n;++k){
				if(k==i||k==j)continue;
				if(e[i][k]&&e[j][k]){
					if(e[i][k]+e[j][k]<e[i][j]||e[i][j]==0){
						e[i][j]=e[j][i]=e[i][k]+e[j][k];
					}
				}
			}
		}
	}
	for(int i=0;i<q;++i){
		scanf("%d%d",&st,&ed);
		for(int i=1;i<=n;++i){
			if(e1[i][st])
				for(int j=1;j<=n;++j){
					if(e1[j][ed])ans=min(ans,w[st]+w[ed]+e1[i][st]+e1[j][ed]+e[i][j]);
				}
		}
		printf("%d\n",ans);
		ans=0;
	}
	return 0;
}
