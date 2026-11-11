#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;

const int N=1e6+10;
int c,t,n,k;
vector<int> e[N];
int fa[N],sz[N],d[N],son[N],top[N];

ll read(){
	ll k=0; int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}

void write(ll x){
	if(x<0) putchar('-');
	else if(x<10) putchar(x+'0');
	else write(x/10), putchar(x%10+'0');
}

void dfs1(int u,int f){
	fa[u] = f;
	sz[u] = 1;
	d[u] = d[f] +1;
	son[u] =0;
	for(int v:e[u]){
		if(v==f) continue;
		dfs1(v,u);
		sz[u] += sz[v];
		if(sz[v] > sz[son[u]]) son[u] = v;
	}
}

void dfs2(int u,int f,int t){
	top[u] = t;
	if(!son[u]) return;
	dfs2(son[u],u, t);
	for(int v:e[u]){
		if(v==f || v==son[u]) continue;
		dfs2(v,u,v);
	}
} 


int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	
	c=read(), t=read();
	while(t--){
		n=read(), k=read();
		for(int i=1,u,v;i<=n-1;i++){
			u=read(), v=read();
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs1(1,0);
		
		write(1), putchar('\n');
	}
	
	return 0;
}
