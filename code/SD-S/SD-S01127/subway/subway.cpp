#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int inf=2e18;
int c,n,m,d,q;
int cnt=0,dep[500005],dis[505][505],h[500005];
struct nd{
	int v,w,nxt;
}e[1000005];
void jb(int u,int v,int w){
	e[++cnt]={v,w,h[u]};
	h[u]=cnt;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>dep[i];
	for(int i=1,k,u,w;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>u>>w;
			jb(u,i,w);
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=(i==j?0:inf);
	for(int i=1;i<=m;i++){
		for(int j=h[i];j;j=e[j].nxt){
			for(int k=h[i];k!=j;k=e[k].nxt){
				int x=e[j].v,y=e[k].v;
				dis[x][y]=min(dis[x][y],e[j].w+e[k].w);
				dis[y][x]=min(dis[y][x],e[j].w+e[k].w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				dis[j][i]=min(dis[j][i],dis[j][k]+dis[k][i]);
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		int ans=inf;
		for(int i=h[x];i;i=e[i].nxt){
			for(int j=h[y];j;j=e[j].nxt){
				int u=e[i].v,v=e[j].v;
				ans=min(ans,dis[u][v]+e[i].w+e[j].w);
			}
		}cout<<ans+dep[x]+dep[y]<<"\n";
	}
}
//µØÌúÃ×Õô¶ìÐÄ 
