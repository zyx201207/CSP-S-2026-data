#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x<10) putchar(x+'0');
	else{
		write(x/10);
		putchar(x%10+'0');
	}
}
int cnt,dist[N],c[N],maxx;
bool vis[N];
vector<int> edges[N];
inline void dfs(int x,int father){
	dist[x]=min(dist[x],dist[father]+1);
	if(vis[x] && !c[x]){
		dist[x]=0;
		if(vis[father]) c[x]=c[father];
		else c[x]=++cnt;
	}
	for(auto y:edges[x]){
		if(y==father) continue;
		dfs(y,x);
		dist[x]=min(dist[x],dist[y]+1);
	}
	for(auto y:edges[x]){
		if(y==father) continue;
		dfs(y,x);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C=read(),T=read();
	while(T--){
		int n=read(),k=read();
		for(int i=1;i<=n;i++) edges[i].clear();
		for(int i=1;i<n;i++){
			int x=read(),y=read();
			edges[x].push_back(y);
			edges[y].push_back(x);
		}
		if(n==k){
			puts("0");
			continue;
		}
		int ans=1e18;
		for(int S=0;S<(1<<n);S++){
			if(__builtin_popcountll(S)!=k) continue;
			for(int i=0;i<=n;i++) dist[i]=1e9,vis[i]=c[i]=0;
			for(int i=0;i<n;i++)
				if(S&(1<<i)) vis[i+1]=true;
			cnt=0;
			dfs(1,0);
			if(cnt>2) continue;
			dfs(1,0);
			maxx=0;
			for(int i=1;i<=n;i++) maxx=max(maxx,dist[i]);
			ans=min(ans,maxx);
		}
		write(ans);
		puts("");
	}
	return 0;
}
/*
0 1
9 3
1 2
2 8
8 5
5 6
5 3
3 9
9 7
7 4
*/
