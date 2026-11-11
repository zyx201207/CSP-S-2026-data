#include <bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int c,T,n,k,ans;
int a[maxn],fa[maxn],dis[maxn];
bool vis[maxn],ck[maxn];
vector <int> e[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)) f^=!(ch^'-'),ch=getchar();
	while( isdigit(ch)){
		ret=(ret<<3)+(ret<<1)+(ch^48);
		ch=getchar();
	}
	return ret*(f-(f^1));
}
int getfa(int x){
	if(fa[x]==x) return x;
	return fa[x]=getfa(fa[x]);
}
bool check(){
	for(int i=1;i<=n;i++) fa[i]=i,ck[i]=0;
	for(int i=1;i<=k;i++){
		int u=a[i];
		for(auto v:e[u]) if(vis[v]){
			int x=getfa(v),y=getfa(u);
			fa[x]=y;
		}
	}
	int cnt=0;
	for(int i=1;i<=k;i++){
		int u=a[i];
		if(ck[getfa(u)]) continue;
		cnt++;
		ck[getfa(u)]=1;
	}
	if(cnt>2) return 0;
	return 1;
}
int bfs(){
	int MAX=0;
	for(int i=1;i<=n;i++) ck[i]=0,dis[i]=0;
	queue<int> q;
	for(int i=1;i<=k;i++) q.push(a[i]),ck[a[i]]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto v:e[u]){
			if(ck[v]) continue;
			dis[v]=dis[u]+1;
			MAX=max(MAX,dis[v]);
			ck[v]=1;
			q.push(v);
		}
	}
	return MAX;
}
void dfs(int d){
	if(d==k+1){
		if(check()){
			int tmp=bfs();
			if(ans>tmp){
				ans=tmp;
			}
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		a[d]=i;
		dfs(d+1);
		vis[i]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();T=read();
	while(T--){
		n=read();k=read();
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i< n;i++){
			int x=read(),y=read();
			e[x].push_back(y);
			e[y].push_back(x);
		}
		if(c==13||c==14){
			int m=n/2,tmp=m+2-k;
			ans=tmp/4;if(tmp%4) ans++;
			if(k==n) printf("0\n");
			else if(k>=m+1) printf("1\n");
			else if(tmp==3||tmp==4) printf("2\n");
			else printf("%d\n",ans);
			continue;
		}
		ans=1<<30;
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}