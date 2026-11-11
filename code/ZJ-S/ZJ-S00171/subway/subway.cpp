#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int w[500005];
int len[505];
struct Edge{
	int to,val;
}V[500005][30];
int cnt[500005];
ll dis[505][505];
int getint(){
	char ch=getchar();
	int res=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		res=res*10+ch-'0'; ch=getchar();
	}
	return res;
}
void putint(ll x){
	if(x<10){
		putchar(x+'0'); return ;
	}
	putint(x/10); putchar(x%10+'0');
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q; c=getint(),n=getint(),m=getint(),d=getint(),q=getint();
	for(int i=1;i<=m;i++) w[i]=getint();
	for(int i=1;i<=n;i++){
		len[i]=getint(); int u,w;
		for(int j=1;j<=len[i];j++){
			u=getint(),w=getint(); V[u][++cnt[u]]=Edge{i,w};
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=j+1;k<=cnt[i];k++){
				int u=V[i][j].to,v=V[i][k].to;
				ll w=V[i][j].val+V[i][k].val;
				dis[u][v]=min(dis[u][v],w); dis[v][u]=min(dis[v][u],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	while(q--){
		int x,y; x=getint(); y=getint();
		ll ans=1e18;
		for(int j=1;j<=cnt[x];j++){
			for(int k=1;k<=cnt[y];k++){
				int p=V[x][j].to,q=V[y][k].to; ans=min(ans,dis[p][q]+V[x][j].val+V[y][k].val);
			}
		}
		putint(ans+w[x]+w[y]); putchar('\n');
	}
	return 0;
}
