#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int maxn=1005;
const int M=2e6+5;
const int N=505;
const int inf=0x3f3f3f3f3f3f3f;
int c,n,m,d,T,ans;
int w[maxn],x;
int a[N][maxn],t[N][maxn],k[N];
vector<pii> e[M];
vector<int> h[maxn];
unordered_map<int,int> mp;
int dis[M];
bool vis[M];
void dij(int st,int rt){
	priority_queue<pii,vector<pii>,greater<pii> > q;
	memset(vis,0,sizeof(vis));
	memset(dis,inf,sizeof(dis));
	dis[st]=0;
	q.push({0,st});
	while(!q.empty()){
		pii t=q.top();q.pop();
		int u=t.second;
		if((u%m)==(rt%m)){
			ans=min(ans,dis[u]+mp[u]+mp[st]);continue;
		}
		if(vis[u]) continue;
		vis[u]=1;
		for(auto o:e[u]){
			int v=o.first;
			int we=o.second;
			if(dis[u]+we<dis[v]){
				dis[v]=dis[u]+we;
				q.push({dis[v],v});
			}
		}
	}
	return ;
}
inline int read(){
	int num=0,f=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		num=num*10+(ch^48);
		ch=getchar();
	}
	return num*f;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),T=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			a[i][j]=read();
			t[i][j]=read();
			int zz=a[i][j];
			a[i][j]+=(i-1)*m;
			h[zz].push_back(a[i][j]);
			mp[a[i][j]]=t[i][j];
			if(j==1) continue;
			e[a[i][j]].push_back({a[i][j-1],0});
			e[a[i][j-1]].push_back({a[i][j],0});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto x:h[i]){
			for(auto y:h[i]){
				if(x==y) continue;
				e[x].push_back({y,mp[x]+mp[y]});
			}
		}
	}
	while(T--){
		int l,r;
		l=read();r=read();
		ans=1e18;
		for(auto x:h[l]){
			dij(x,r);
		}
		cout<<ans+w[l]+w[r]<<'\n';
	}
	return 0;
}