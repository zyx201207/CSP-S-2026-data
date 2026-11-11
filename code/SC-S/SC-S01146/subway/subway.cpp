#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5;
int c,n,m,d,q,head[N],tot,dis[N][N],w[N];
void floyed(){
	for(int i=1;i<=m;i++)dis[i][i]=0;
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)scanf("%d",w+i);
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		int k,a,t,la,lt;
		scanf("%d%d%d",&k,&la,&lt);
		for(int j=1;j<k;j++){
			scanf("%d%d",&a,&t);
			if(j==1){
				dis[la][a]=t+lt;
				dis[a][la]=t;
			}
			else dis[la][a]=dis[a][la]=t;
			la=a;
		}
	}
	floyed();
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",dis[x][y]+w[x]+w[y]);
	}
	return 0;
}