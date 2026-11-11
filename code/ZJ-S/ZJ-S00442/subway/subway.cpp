#include<bits/stdc++.h>
using namespace std;
const int M=20001,N=501,Q=100001;//m for dot, and n for edge
int c,n,m,d,q;
int w[M],k[N];
int a[N][M],t[N][M];//for a and t, [edge][the number of dot]
int x[Q],y[Q];
int vae[M][N];
int evi[N];
int ti,ret;
void readd(){
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	if(m>M) return;
	for(int i=1;i<=m;++i) scanf("%d",&w[i]);
	for(int i=1;i<=n;++i){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];++j){
			scanf("%d%d",&a[i][j],&t[i][j]);
			vae[a[i][j]][i]=j;
		}
	}
	for(int i=1;i<=q;++i){
		scanf("%d%d",&x[i],&y[i]);
	}
}
void dfs(int,int);
int sol(int r){
	memset(evi,0,sizeof(evi));
	ti=0;ret=0x3f3f3f3f;
	for(int i=1;i<=n;++i){
		if(vae[x[r]][i]){
			ti+=t[i][vae[x[r]][i]];
			//printf("at the beginning, edge %d for the plan %d, ti=%d\n",i,r,ti);
			dfs(i,r);
			ti-=t[i][vae[x[r]][i]];
		}
	}
	ret+=w[x[r]]+w[y[r]];
	return ret;
}
void dfs(int e,int r){
	evi[e]=1;
	if(vae[y[r]][e]){
		//printf("from edge %d, now we are at the end of plan%d, ti=%d\n",e,r,ti);
		ti+=t[e][vae[y[r]][e]];
		//printf("ti=%d\n",ti);
		if(ti<ret){
			ret=ti;
			//printf("ret=ti=%d",ret);
		}
		ti-=t[e][vae[y[r]][e]];
		//printf("ti=%d\n",ti);
		evi[e]=0;
		return;
	}
	for(int i=1;i<=m;++i){
		if(vae[i][e]){
			//printf("now we choose dot %d, ti=%d\n",i,ti);
			ti+=t[e][vae[i][e]];
			//printf("ti=%d\n",ti);
			//printf("%d\n",t[i][vae[i][e]]);
			for(int j=1;j<=n;++j){
				if(vae[i][j] && !evi[j]){
					//printf("now we choose edge %d, ti=%d\n",j,ti);
					ti+=t[j][vae[i][j]];
					//printf("ti=%d\n",ti);
					dfs(j,r);
					ti-=t[j][vae[i][j]];
					//printf("ti=%d\n",ti);
				}
			}
			ti-=t[e][vae[i][e]];
			//printf("ti=%d\n",ti);
		}
	}
	evi[e]=0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	readd();
	if(m>M){
		return 0;
	}
	for(int i=1;i<=q;++i){
		printf("%d",sol(i));
		if(i<q) printf("\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}