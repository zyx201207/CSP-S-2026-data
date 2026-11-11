#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int cid,T;
int n,k;
struct edge{
	int u,v;
	int nxt;
}e[N<<1];
int head[N],tot;
void add_edge(int x,int y){
	e[++tot]=(edge){x,y,head[x]};head[x]=tot;
}
//vector<int> G1[3][2],G2[3][2]; 
//vector<int> F[N][3][2];
////id block rt0/1 count  -> mindis
//int mid;
//void dfs(int x,int fath){
//	memset(F[x],63,sizeof F);
//	for(int j=head[x];j;j=e[j].nxt){
//		if(e[j].v==fath)continue;
//		dfs(e[j].v,x);
//	}
//	memset(G,63,sizeof G);
//	G1[0][0][0]=1;G1[1][1][1]=-mid+1;
//	for(int j=head[x];j;j=e[j].nxt){
//		if(e[j].v==fath)continue;
//		for(int xt:{0,1,2})for(int yt:{0,1})for(int kt=0;kt<=k;kt++)
//		for(int x_:{0,1,2})for(int y_:{0,1})for(int k_=0;k_<=k;k_++){
//			if(k_+kt>k)continue; if([xt+x_-(yt==1&&y_==1)>2)continue;
//			G1[xt+x_-(yt==1&&y_==1)][yt][kt+k_] = min(f);
//		}
//	}
//}
//int check(){
//	dfs(1,0);
//}
int dis[N][N];
int dep[N];
void dfs(int x,int fath){
	dep[x]=dep[fath]+1;
	for(int j=head[x];j;j=e[j].nxt){
		if(e[j].v==fath)continue;
		dfs(e[j].v,x);
	}
}
int ans;
int fa[N];
int Getfa(int x){
	if(fa[x]==x)return x;
	return fa[x]=Getfa(fa[x]);
}
int vvis[N],vis[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cid=read(),T=read();
	while(T--){
		tot=0;for(int i=0;i<=n;i++)head[i]=0;
		n=read(),k=read();
		for(int i=1;i<n;i++){
			int x=read(),y=read();
			add_edge(x,y);add_edge(y,x);
		}
		if(k==n){
			write(0);putchar('\n');
			continue;
		}
		ans=n;
		for(int i=1;i<=n;i++){
			dep[0]=-1;dfs(i,0);
			for(int j=1;j<=n;j++)dis[i][j]=dep[j];
		}
		for(int S=0;S<(1<<n);S++){
			vector<int> vec;int cnt=0;
			for(int i=1;i<=n;i++)vis[i]=(S>>i-1)&1;
			int TT=0;
			for(int i=1;i<=n;i++)TT+=vis[i];
			if(TT!=k)continue;
			for(int i=1;i<=n;i++)fa[i]=i;
			for(int i=1;i<=tot;i++){
				int x=e[i].u,y=e[i].v;
				if(vis[x]!=1 || vis[y]!=1)continue;
				int fx=Getfa(x),fy=Getfa(y);
				if(fx==fy)continue;fa[fx]=fy;
			}
			for(int i=1;i<=n;i++)if(vis[i]==1)vec.push_back(i);
			for(int i=1;i<=n;i++)vvis[i]=0;
			for(int i=1;i<=n;i++)if(vis[i]==1)vvis[Getfa(i)]=1;
			for(int i=1;i<=n;i++)cnt+=vvis[i];
			if(cnt>2)continue;
			int ret=0;
			for(int i=1;i<=n;i++){
				int now=n;
				for(int x:vec)now=min(now,dis[i][x]);
				ret=max(ret,now);
			}
			ans=min(ans,ret);
		}
		write(ans);putchar('\n');
//		for(int i=1;i<=n;i++)
//		for(int x:{0,1,2})for(int y:{0,1})
//			F[i][x][y].resize(k+2);
//		for(int x:{0,1,2})for(int y:{0,1})
//			G1[x][y].resize(k+2),G2[x][y].resize(k+2);
//		int l=1,r=n;
//		while(l<=r){
//			mid=(l+r)/2;
//			if(check())l=mid+1;
//			else r=mid-1;
//		}
//		write(r);putchar('\n');
	}
	return 0;
}
