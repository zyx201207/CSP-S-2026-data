#include<bits/stdc++.h>
#define int long long
#define il inline
#define put putchar
#define pb emplace_back
#define fir first
#define sec second
#define mk make_pair
using namespace std;
typedef pair<int,int> pii;
il int rd(){
	int sum=0,p=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')p=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		sum=sum*10+(ch-'0');
		ch=getchar(); 
	}
	return sum*p;
}
il void wr(int x){
	if(x<0)put('-'),x=-x;
	if(x>9)wr(x/10);
	put(x%10+'0');
}
const int JYAAKIOI=1e18,N=5e5+5;
int cid,n,k,e[12][12],cnt[N],dis[N];
bool vis[N];
vector<int>g[N];
struct dsu{
	int fa[N];
	il void clear(){
		for(int i=1;i<=n;++i)fa[i]=i;
	}
	il int find(int x){
		return (fa[x]==x)?x:fa[x]=find(fa[x]);
	}
	il void merge(int x,int y){
		x=find(x);y=find(y);
		if(x==y)return;
		fa[x]=y;
	}
}t;
il void dfs(int x,int de,int fa){
	dis[x]=min(dis[x],de);
	for(int j=1;j<=n;++j){
		if(e[x][j]&&j!=fa)dfs(j,de+1,x);
	}
}
il void jyacanfly(){
	n=rd();k=rd();
//	for(int i=1;i<=n;++i)g[i].clear();
//	for(int i=1;i<n;++i){
//		int u=rd(),v=rd();
//		g[u].pb(v);
//		g[v].pb(u);
//	}
	if(cid<=3){
		memset(e,0,sizeof e);
		int ans=JYAAKIOI;
		for(int i=1;i<n;++i){
			int u=rd(),v=rd();
			e[u][v]=e[v][u]=1;
		}
		for(int i=1;i<(1ll<<n);++i){
			if(__builtin_popcount(i)!=k)continue;
			for(int j=1;j<=n;++j){
				if(i&(1ll<<(j-1)))vis[j]=1;
				else vis[j]=0;
			}
			t.clear();
			for(int j=1;j<=n;++j){
				cnt[j]=0;
				if(vis[j]){
					for(int k=1;k<=n;++k)if(vis[k]&&e[j][k])t.merge(j,k);
				}
			}
			int Cnt=0;
			for(int j=1;j<=n;++j){
				if(vis[j]){
					++cnt[t.find(j)];
					if(cnt[t.find(j)]==1)++Cnt;
				}
			}
			if(Cnt>2)continue;
			for(int j=1;j<=n;++j)dis[j]=JYAAKIOI;
			for(int j=1;j<=n;++j){
				if(vis[j]){
					dfs(j,0,0);
				}
			}
			int res=0;
			for(int j=1;j<=n;++j)res=max(res,dis[j]);
		//	if(res==1)cout<<i<<endl;
			ans=min(ans,res);
		}
		wr(ans),put('\n');
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cid=rd();int T=rd();
	while(T--)jyacanfly();
	return 0;
}