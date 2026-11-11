// 15
#include<bits/stdc++.h>
using namespace std;
int read(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=15,INF=1e9;
vector<int>vc[N];
int n,k,f[N];
bool flag[N],vis[N];
void dfs(int u,int fa){
	vis[u]=true;
	for(auto v:vc[u])
		if(v!=fa&&flag[v])
			dfs(v,u);
	return;
}
bool check(int s){
	memset(flag,0,sizeof(flag));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i)
		if(s&(1<<(i-1)))
			flag[i]=true;
	int cnt=0;
	for(int i=1;i<=n;++i)
		if(flag[i]&&!vis[i])
			dfs(i,0),++cnt;
	return cnt<=2;
}
int calc(int s){
	queue<int>q;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;++i)
		if(s&(1<<(i-1)))
			q.push(i),f[i]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto v:vc[u])
			if(f[v]==f[0])
				q.push(v),f[v]=f[u]+1;
	}
	int res=0;
	for(int i=1;i<=n;++i)
		res=max(res,f[i]);
	return res;
}
void solve(){
	n=read(),k=read();
	for(int i=1;i<=n;++i)
		vc[i].clear();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		vc[u].push_back(v);
		vc[v].push_back(u);
	}
	int res=INF;
	for(int s=0;s<(1<<n);++s)
		if(__builtin_popcount(s)==k&&check(s))
			res=min(res,calc(s));
	printf("%d\n",res);
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),T=read();
	if(c<=3){
		while(T--)
			solve();
		return 0;
	}
	while(T--){
		n=read(),k=read();
		for(int i=1;i<n;++i)
			read(),read();
		int m=n/2;
		if(n==k)
			printf("1\n");
		printf("%d\n",m/k);
	}
	return 0;
}
