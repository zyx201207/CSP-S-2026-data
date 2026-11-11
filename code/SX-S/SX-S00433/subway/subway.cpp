#include<bits/stdc++.h>
using namespace std;
int Read(){
	char c=' ';
	bool f=0;
	while(!('0'<=c&&c<='9')){
		c=getchar();
		if(c=='-') f=1;
	}
	int res=0;
	while('0'<=c&&c<='9'){
		res=(res<<1)+(res<<3)+(c^48);
		c=getchar();
	}
	if(f) res=-res;
	return res;
}
void Write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) Write(x/10);
	putchar(x%10+'0');
}
const int M=5e5;
const int N=500;
const int D=20;
int c,n,m,d,q;
int pval[M+5];
int ed[M+5][D+5][2],len[M+5];
long long dist[N+5][N+5];
int main(){
//	printf("%d\n",sizeof(ed)/1024/1024);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&pval[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		while(k--){
			int u,w;
			scanf("%d%d",&u,&w);
			len[u]++;
			ed[u][len[u]][0]=i,ed[u][len[u]][1]=w;
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) dist[i][j]=4e18;
	for(int u=1;u<=m;u++){
		for(int j1=1;j1<=len[u];j1++){
			for(int j2=1;j2<=len[u];j2++){
				dist[ed[u][j1][0]][ed[u][j2][0]]=min(dist[ed[u][j1][0]][ed[u][j2][0]],1ll*ed[u][j1][1]+ed[u][j2][1]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	while(q--){
		int u,v;
		scanf("%d%d",&u,&v);
		long long ans=4e18;
		for(int i=1;i<=len[u];i++){
			for(int j=1;j<=len[v];j++){
				ans=min(ans,dist[ed[u][i][0]][ed[v][j][0]]+ed[u][i][1]+ed[v][j][1]);
			}
		}
		printf("%lld\n",ans+pval[u]+pval[v]);
	}
	return 0;
}
