#include<bits/stdc++.h>
using namespace std;
const int N=1005;
vector<int> g[N];
int n,k,dep[N],dfn[N],tot=0;
int st[N][22],col[N],vis[N];
int ge(int x,int y){
	return dfn[x]<dfn[y]?x:y;
}
void dfs(int x,int f){
	dfn[x]=++tot;
	dep[x]=dep[f]+1;
	st[dfn[x]][0]=f;
	for(int y:g[x]) if(y^f){
		dfs(y,x);
	}
}
void init(){
	for(int i=1;i<=__lg(n);++i){
		for(int j=1;j+(1<<i)-1<=n;++j){
			st[j][i]=ge(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		}
	}
}
int dist(int x,int y){
	if(x==y) return 0;
	if(dfn[x]>dfn[y]) swap(x,y);
	int d=__lg(dfn[y]-dfn[x]);
	int lca=ge(st[dfn[x]+1][d],st[dfn[y]-(1<<d)+1][d]);
	return dep[x]+dep[y]-2*dep[lca];
}
vector<int> vec;
int sol(){
	int ans=0;
	for(int x=1;x<=n;++x){
		int tmp=1e9;
		for(int y:vec){
			tmp=min(tmp,dist(x,y));
		}
		ans=max(ans,tmp);
	}
	return ans;
}
int check(){
	for(int i=1;i<=n;++i) col[i]=vis[i]=0;
	for(int i:vec) col[i]=1;
	int cnt=vec.size();
	int tmp=0;
	while(cnt){
		++tmp;
		queue<int> q;
		for(int i=1;i<=n;++i) if(col[i]){
			q.push(i),vis[i]=1;
			break;
		}
		--cnt;
		while(!q.empty()){
			int x=q.front(); q.pop();
			for(int y:g[x]) if(col[y] && !vis[y]){
				vis[y]=1;
				q.push(y);
				--cnt;
			}
		}
	}
	return tmp;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T; scanf("%d%d",&c,&T);
	while(T--){
		tot=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i) g[i].clear();
		for(int i=1;i<n;++i){
			int x,y; scanf("%d%d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(1,0);
		init();
//		while(1){
//			int x,y; scanf("%d%d",&x,&y);
//			printf("%d\n",dist(x,y));
//		}
		int ans=1e9;
		if(c<=3){
			for(int S=1;S<(1<<n);++S) if((int)__builtin_popcount(S)==k){
				vec.clear();
				for(int i=1;i<=n;++i) if((S>>(i-1))&1){
					vec.push_back(i);
				}
//				printf(" < %d\n",check());
				if(check()>2) continue;
//				for(int i:vec) printf("%d ",i);
//				printf("\n");
				int tmp=sol();
				ans=min(ans,tmp);
			} 
		}
		else{
			for(int x=1;x<=n;++x){
				for(int y=x+1;y<=n;++y){
					vec.resize(2);
					vec[0]=x;
					vec[1]=y;
					int tmp=sol();
					ans=min(ans,tmp);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5
*/
