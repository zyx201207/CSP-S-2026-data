#include<bits/stdc++.h>
using namespace std;
long long dis[505][505],c,n,m,d,q,w[500005],kk,x,y,a,t,cnt[500005];
struct node{
	long long xl,zt;
}v[500005][22];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	memset(dis,0x3f3f3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&kk);
		for(int j=1;j<=kk;j++){
			scanf("%lld%lld",&a,&t);
			if(cnt[a]==0) v[a][cnt[a]++]={i,t}; else{
				for(int k=0;k<cnt[a];k++){
					if(v[a][k].zt+t<dis[i][v[a][k].xl]) dis[v[a][k].xl][i]=v[a][k].zt+t;
					if(v[a][k].zt+t<dis[i][v[a][k].xl]) dis[i][v[a][k].xl]=v[a][k].zt+t;
				}
				v[a][cnt[a]++]={i,t};
			}
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(dis[i][k]+dis[j][k]<dis[i][j]) dis[i][j]=dis[i][k]+dis[j][k];
	while(q--){
		long long mn=LLONG_MAX;
		scanf("%lld%lld",&x,&y);
		for(int i=0;i<cnt[x];i++) for(int j=0;j<cnt[y];j++){
			long long foosball=v[x][i].zt+v[y][j].zt+dis[v[x][i].xl][v[y][j].xl]+w[x]+w[y];
			if(foosball<mn) mn=foosball;
		}
		printf("%lld\n",mn);                                                                 
	}
	return 0;
}
