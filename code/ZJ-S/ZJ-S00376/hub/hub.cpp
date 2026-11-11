#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int c,t,n,k,hed[15],cnt,dis[15][15],fa[15],ans;
bool vis[15];
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
struct edge{
	int t,nt;
}e[30];
struct zdy{
	int x,y;
}a[30];
void add_e(int x,int y){
	e[++cnt]=(edge){y,hed[x]};
	hed[x]=cnt;
}
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while( isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
void solve(){
	ans=1<<30;
	n=read(),k=read();
	memset(dis,63,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		dis[x][y]=1,dis[y][x]=1;
		a[i]=(zdy){x,y};
	}
	for(int K=1;K<=n;K++)
	for(int i=1;i<=n;i++)if(dis[i][K]!=INF)
	for(int j=1;j<=n;j++)
		if(dis[K][j]!=INF&&dis[i][K]+dis[K][j]<dis[i][j])
			dis[i][j]=dis[i][K]+dis[K][j];
	
	for(int s=(1<<k)-1;s<(1<<n);s++){
		int tmp=0;
		for(int i=1;i<=n;i++) fa[i]=i,vis[i]=0;
		int num=0;
		vector<int> b;
		for(int i=1;i<=n;i++){
			if(s&(1<<i-1)){
				num++;
				vis[i]=1;
				b.push_back(i);
			}
		}
		if(num!=k) continue;
		int tot=k;
		for(int i=1;i<n;i++){
			if(!vis[a[i].x]||!vis[a[i].y]) continue;
			int fx=getfa(a[i].x),fy=getfa(a[i].y);
			if(fx==fy) continue;
			tot--;
			fa[fx]=fy;
		}
		if(tot>2) continue;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			int res=1<<30;
			for(int j=0;j<b.size();j++)
				res=min(res,dis[i][b[j]]);
			tmp=max(tmp,res);
		}
		ans=min(tmp,ans);
	}
	printf("%d\n",ans);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--) solve();
	return 0;
}
