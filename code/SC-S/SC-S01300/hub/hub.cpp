#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int maxn=1e6+5;
int c,T;
int n,k;
int x,y,ans;
vector<int> e[maxn],a;
bool check[maxn],vis[maxn];
void dfs(int u){
	vis[u]=1;
	for(auto v:e[u]){
		if(!check[v]) continue;
		if(vis[v]) continue;
		vis[v]=1;
		dfs(v);
	}
	return ;
}
bool pch(){
	int cnt=0;
	for(auto x:a){
		if(!vis[x]){
			cnt++;
			dfs(x);
		}
	}
	return cnt<=2;
}
int dis[maxn],op[maxn];
void dij(int st){
	priority_queue<pii,vector<pii>,greater<pii> > q;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[st]=0;
	q.push({0,st});
	while(!q.empty()){
		pii t=q.top();q.pop();
		int u=t.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto v:e[u]){
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				q.push({dis[v],v});
			}
		}
	}
	return ;
}
void dfs(int pos,int cnt,int siz){
	if(cnt>siz){
		memset(vis,0,sizeof(vis));
		if(pch()){
			int sum=0;
			memset(op,0x3f3f3f3f,sizeof(op));
			for(auto x:a){
				dij(x);
				op[x]=0;
				for(int i=1;i<=n;i++){
					if(check[i]) continue;
					op[i]=min(op[i],dis[i]);
				}
			}
			for(int i=1;i<=n;i++){
				sum=max(sum,op[i]);
			}
			ans=min(ans,sum);
		}
		return ;
	}
	for(int i=pos;i<=n-(siz-cnt);i++){
		if(check[i]) continue;
		check[i]=1;
		a.push_back(i);
		dfs(i+1,cnt+1,siz);
		check[i]=0;
		a.pop_back();
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
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<=n-1;i++){
			x=read(),y=read();
			e[x].push_back(y);
			e[y].push_back(x);
		}
		ans=1e18;
		dfs(1,1,k);
		cout<<ans<<'\n';
	}
	return 0;
}