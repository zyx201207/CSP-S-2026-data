#include<bits/stdc++.h>
#define il inline 
#define ll long long
using namespace std;
#define rep(x,l,r) for(int x=l;x<=r;++x)
#define per(x,l,r) for(int x=l;x>=r;--x)
il ll read(){
	ll f=1,k=0; char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){k=(k<<1)+(k<<3)+(c^48);c=getchar();}return f*k;
}
const int N=1e5+10;
int n,k;
struct node{
	int nxt,v;
}E[N*2]; int head[N],tot;
il void add(int u,int v){
	E[++tot]={head[u],v};
	head[u]=tot;
}
int dis[100][100],now;
void dfs1(int x,int fa){
	for(int i=head[x];i;i=E[i].nxt){
		int v=E[i].v;
		if(v==fa) continue;
		dis[now][v]=dis[now][x]+1;
		dfs1(v,x);
	}
}
bool vis[N],mp[110][110];
int fa[N];
il int Find(int x){
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
int b[N],ans=1e9,cnt;
void dfs(int x,int sum){
	if(x==n+1){
		if(sum!=k) return;
		cnt=0;
		rep(i,1,n){
			if(vis[i]) b[++cnt]=i;
			fa[i]=i;	
		}
		
		rep(i,1,cnt){
			rep(j,1,cnt){
				int x=b[i],y=b[j];
				if(x==y) continue;
				if(!mp[x][y]) continue;
				int fx=Find(x),fy=Find(y);
				if(fx==fy) continue;
				fa[fx]=fy;
			}
		}
		int s=0;
		rep(i,1,cnt){
			if(Find(b[i])==b[i]) s++;
		}
		if(s<=2){
			rep(i,1,cnt) printf("%d ",b[i]);
			printf("\n");
			int mx=0;
			rep(i,1,n){
				int mn=1e9;
				rep(j,1,cnt){
					mn=min(mn,dis[i][b[j]]);
				}
				mx=max(mx,mn);
			}
			ans=min(ans,mx);
		}
		return;
	}
	vis[x]=1;
	dfs(x+1,sum+1);
	vis[x]=0;
	dfs(x+1,sum);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),T=read();
	while(T--){
		ans=1e9;
		n=read(),k=read();
		rep(i,1,n-1){
			int x=read(),y=read();
			add(x,y);
			add(y,x);
			mp[x][y]=mp[y][x]=1;
		}
		rep(i,1,n){
			now=i;
			dis[i][i]=0;
			dfs1(i,0);
		}
		dfs(1,0);
		printf("%d\n",ans);
		tot=0;
		rep(i,1,n){
			head[i]=0;
			rep(j,1,n){
				dis[i][j]=0;
				mp[i][j]=0;
			}
		}
	}
	
	
	
	
	
	
	
	return 0;
}

