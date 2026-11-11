#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const long long inf=1e18;
long long read(){
	long long t=0,f=1;
	char g=getchar();
	while((g<'0' || g>'9') && g!=EOF){
		if(g=='-') f=-f;
		g=getchar();
	}
	while(g>='0' && g<='9' && g!=EOF){
		t=t*10+g-'0';
		g=getchar();
	}
	return t*f;
}
int n,m,d,q,c;
long long w[N+5];
int k[505];
vector<int>sub[N+5];//i点有哪些线路
vector<int>g[505];//i线路有哪些点 
struct node1 {
	int id;
	long long w;
};
vector<node1>t[N+5];
long long Tim(int u,int road){
	for(int i=0;i<t[u].size();++i){
		node1 tmp=t[u][i];
		if(tmp.id==road) return tmp.w;
	}
	return 0;
}
//*******************************
long long dis[N+5];
void cleardis() { for(int i=1;i<=m;++i) dis[i]=inf; }
void dfs(int u,int T,long long sum,int last){
	if(sum>dis[u]) return ;
	dis[u]=sum;
	if(u==T){
		dis[u]+=w[T];
		return ;
	}
	for(int i=0;i<sub[u].size();++i){
		int road=sub[u][i];
		if(road==last) continue;
		long long val=Tim(u,road);
		for(int j=0;j<g[road].size();++j){
			int v=g[road][j];
			if(u==v) continue;
			dfs(v,T,sum+val+Tim(v,road),road);
		}
	}
}
long long solve(int S,int T){
	cleardis();
	dis[S]=w[S];
	dfs(S,T,w[S],-1);
	return dis[T];
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;++i){
		w[i]=read();
	}
	for(int i=1;i<=n;++i){
		k[i]=read();
		for(int j=1;j<=k[i];++j){
			int a;long long ti; a=read(),ti=read();
			t[a].push_back((node1){i,ti});
			g[i].push_back(a);
			sub[a].push_back(i);
		}
	}
	while(q--){
		int x,y;
		x=read(),y=read();
		cout<<solve(x,y)<<"\n";
	}
	

	fclose(stdin);
	fclose(stdout);
	return 0;
}
