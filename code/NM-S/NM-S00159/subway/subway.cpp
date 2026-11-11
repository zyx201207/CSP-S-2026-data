#include<bits/stdc++.h>
using namespace std;
const long long INF=214748360000000;
int c,n,m,d,q;
long long ed[505][505],zd[505][505],ans,xx;
int dt[500005][22][2],w[500005],k[505],l[500005],x,y,vis[505],mn,cu,des[500005][2];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&x,&y);
			dt[x][l[x]][0]=y;
			dt[x][l[x]][1]=j;
			l[x]++;
		}
	}
	for(int i=1;i<=q;i++)scanf("%d%d",&des[i][0],&des[i][1]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)ed[i][j]=INF;
			if(i!=j)zd[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<l[i];j++){
			for(int k=j+1;k<l[i];k++){
				if(dt[i][j][0]+dt[i][k][0]<ed[dt[i][j][1]][dt[i][k][1]])ed[dt[i][j][1]][dt[i][k][1]]=dt[i][j][0]+dt[i][k][0];
				if(dt[i][j][0]+dt[i][k][0]<ed[dt[i][k][1]][dt[i][j][1]])ed[dt[i][k][1]][dt[i][j][1]]=dt[i][j][0]+dt[i][k][0];
				//vis[dt[i][k][1]][dt[i][j][1]]=1;
				//vis[dt[i][j][1]][dt[i][k][1]]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			//printf("%lld ",ed[i][j]);
		}
		//printf("\n");
	}
	//printf("\n");
	for(int i=1;i<=n;i++){
		cu=i;
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=n;j++){
			mn=0;
			for(int k=1;k<=n;k++){
				if(ed[cu][k]!=INF)zd[i][k]=min(zd[i][k],zd[i][cu]+ed[cu][k]);
			}
			for(int k=1;k<=n;k++){
				if(vis[k]==0&&(mn==0||zd[i][k]<zd[i][mn]))mn=k;
			}
			vis[mn]=1;
			cu=mn;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			//printf("%lld ",zd[i][j]);
		}
		//printf("\n");
	}
	for(int i=1;i<=q;i++){
		ans=INF;
		for(int j=0;j<l[des[i][0]];j++){
			for(int k=0;k<l[des[i][1]];k++){
				xx=dt[des[i][0]][j][0]+dt[des[i][1]][k][0]+zd[dt[des[i][0]][j][1]][dt[des[i][1]][k][1]];
				if(xx<ans)ans=xx;
				//printf("%d %lld %lld %d %d %d %d\n",i,zd[dt[des[i][0]][j][1]][dt[des[i][1]][k][1]],xx,dt[des[i][0]][j][0],dt[des[i][1]][k][0],dt[des[i][0]][j][1],dt[des[i][1]][k][1]);
			}
		}
		printf("%lld\n",ans+w[des[i][0]]+w[des[i][1]]);
	}
}

