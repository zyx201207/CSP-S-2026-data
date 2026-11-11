#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q,x,y,len[510],dis[500010],zhan[500010][21],num[500010],can[510][510],dir[510][510];
int path[500010][21];
ll f[510][510];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%d",&dis[i]);
    for(int i=1;i<=n;i++){
		scanf("%d",&len[i]);
		for(int j=1;j<=len[i];j++){
			scanf("%d%d",&x,&y);
			path[x][++num[x]]=i;
			zhan[x][num[x]]=y;
		}
	}
	for(int i=1;i<=n;i++) 
	    for(int j=1;j<=n;j++){
			if(i==j) continue;
			f[i][j]=1e9+7;
		}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=num[i];j++){
			for(int w=1;w<=num[i];w++){
				int posx=path[i][j],posy=path[i][w];
				can[posx][posy]=can[posy][posx]=true;
				f[posx][posy]=min(f[posx][posy],(ll)zhan[x][j]+zhan[x][w]);
				f[posy][posx]=min(f[posy][posx],(ll)zhan[x][j]+zhan[x][w]);
			}
		}
	}
	for(int w=1;w<=n;w++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j||j==w||i==w) continue;
				f[i][j]=min(f[i][j],f[i][w]+f[w][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		ll ss=1e18;
		for(int j=1;j<=num[x];j++){
			for(int w=1;w<=num[y];w++){
				int wx=path[x][j],wy=path[y][w];
				ss=min(ss,f[wx][wy]+zhan[x][j]+zhan[y][w]);
			}
		}
		printf("%lld\n",ss+dis[x]+dis[y]);
	}
	return 0;
}
