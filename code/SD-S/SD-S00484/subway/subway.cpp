#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,w[500005],dt[500005][25][2],k,x,y,num[500005];
ll way[505][505],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&x,&y);
			dt[x][++num[x]][0]=i;
			dt[x][num[x]][1]=y;
		}
	}
	memset(way,0x3f,sizeof(way));
	for(int i=1;i<=n;i++)way[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=num[i];j++){
			for(int k=j+1;k<=num[i];k++){
				ll len=dt[i][j][1]+dt[i][k][1];
				way[dt[i][j][0]][dt[i][k][0]]=min(way[dt[i][j][0]][dt[i][k][0]],len);
				way[dt[i][k][0]][dt[i][j][0]]=min(way[dt[i][k][0]][dt[i][j][0]],len);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j||way[i][j]==MAX)continue;
			for(int k=1;k<=n;k++){
				if(j==k||i==k||way[j][k]==MAX)continue;
				ll len=way[i][j]+way[j][k];
				way[i][k]=min(way[i][k],len);
				way[k][i]=min(way[k][i],len);
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		ans=MAX;
		for(int i=1;i<=num[x];i++){
			for(int j=1;j<=num[y];j++){
				ll sum=way[dt[x][i][0]][dt[y][j][0]]+(ll)(dt[x][i][1])+(ll)(dt[y][j][1]);
				ans=min(ans,sum);
			}
		}
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0; 
}

