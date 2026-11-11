#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x3f3f3f3f3f3f3f3f;
const int MAXN=510,MAXM=500010,MAXD=23;
int n,m,G[MAXN][MAXN];
int a[MAXM],len[MAXM];struct point{int id,val;}li[MAXM][MAXD];
#define gc getchar
int readint(){
	int ret=0;bool f=1;char c=gc();
	while(!isdigit(c)){if(c=='-')f=0;c=gc();}
	while(isdigit(c))ret=ret*10+(c&15),c=gc();
	return f?ret:-ret;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=readint();n=readint(),m=readint();int d=readint(),q=readint();
	for(int i=1;i<=m;i++)a[i]=readint();
	memset(G,0x3f,sizeof G);
	for(int i=1;i<=n;i++)G[i][i]=0;
	for(int i=1;i<=n;i++){
		int ll=readint();
		for(int j=1;j<=ll;j++){
			int id=readint(),val=readint();
			for(int k=1;k<=len[id];k++){
				int l=li[id][k].id,vv=li[id][k].val+val;
				if(G[i][l]>vv)G[i][l]=G[l][i]=vv;
			}
			li[id][++len[id]]=(point){i,val};
		}
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
	while(q--){
		int u=readint(),v=readint(),ans=INF,pos;
		for(int i=1;i<=len[u];i++)
		for(int j=1;j<=len[v];j++){
			int cur=a[u]+a[v]+li[u][i].val+li[v][j].val+G[li[u][i].id][li[v][j].id];
			if(ans>cur)ans=cur;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
