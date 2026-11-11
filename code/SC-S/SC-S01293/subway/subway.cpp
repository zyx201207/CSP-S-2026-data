#include<iostream> 
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int mx=1000;
bool vis[mx][mx];
int c,n,m,d,q;
long long dis[mx][mx],val[mx];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++) scanf("%lld",&val[i]),dis[i][i]=0;
	for(int i=1;i<=n;i++){
		int x,y,vx,vy;
		scanf("%d%d%d",&x,&x,&y);
		scanf("%d%d",&vx,&vy);
		dis[y][x]=dis[x][y]=vx+vy;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",val[y]+val[x]+dis[x][y]);
	}
	return 0;
}