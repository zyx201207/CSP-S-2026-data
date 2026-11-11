#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int INF=1e9;
int c,t,n,k;
int U[N],V[N],to[N<<1],deg[N];
namespace solve1{
	int limit;
	int in[N],dep[N];
	queue<int>q;
	int bel[N];
	bool vis[N];
	void dfs(int u,int fa,int rt){
		bel[u]=rt;
		for(int i=deg[u];i<deg[u+1];i++){
			int v=to[i];
			if(v!=fa) dfs(v,u,rt);
		}
	}
	int Del(int x){
		bool flag1=false,flag2=false;
		int tot=0,X,Y;
		for(int i=1;i<=n;i++) in[i]=dep[i]=0,vis[i]=false;
		if(x==0) X=Y=1;
		else X=U[x],Y=V[x];
		dfs(X,Y,X),dfs(Y,X,Y);
		for(int i=1;i<n;i++){
			if(i==x) continue;
			in[U[i]]++,in[V[i]]++;
		}
		for(int i=1;i<=n;i++){
			if(in[i]==1){
				dep[i]=0;
				if(dep[i]<limit) q.push(i);
			}
		}
		while(!q.empty()){
			int u=q.front(); q.pop();
			vis[u]=true;
			tot++;
			for(int i=deg[u];i<deg[u+1];i++){
				int v=to[i];
				if(u==X && v==Y) continue;
				if(u==Y && v==X) continue;
				if(in[v]==1) continue;
				dep[v]=max(dep[v],dep[u]+1);
				if(--in[v]==1){
					if(dep[v]<limit) q.push(v);
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(bel[i]==X) flag1|=(!vis[i]);
			else flag2|=(!vis[i]);
		}
		if(x==0) return n-tot+(!flag1);
		else return n-tot+(!flag1)+(!flag2);
	}
	int check(int mid){	
		limit=mid;
		int res=Del(0);
		for(int i=1;i<n;i++){
			int val=Del(i);
			res=min(res,val);
		}
		return res;
	}	
	void calc(){
		int l=0,r=n;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid)<=k) r=mid;
			else l=mid+1;
		}	
		cout<<l<<'\n';
	}
}
namespace solve2{
	int f[N],g[N],cnt;
	int limit;
	void dfs(int u,int fa){
		g[u]=0;
		for(int i=deg[u];i<deg[u+1];i++){
			int v=to[i];
			if(v!=fa){
				dfs(v,u);
				f[u]=min(f[u],f[v]+1);
				g[u]=max(g[u],g[v]+1);
			}
		}
		if(f[u]+g[u]<=limit) g[u]=-INF;
		else if(g[u]>=limit) g[u]=-INF,f[u]=0,cnt++;
	}
	int check(int mid){	
		limit=mid,cnt=0;
		for(int i=1;i<=n;i++) f[i]=INF;
		dfs(1,0);
		if(f[1]+g[1]>=limit) cnt++;
		return cnt;
	}	
	void calc(){
		int l=0,r=n;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid)<=k) r=mid;
			else l=mid+1;
		}	
		cout<<l<<'\n';
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		cin>>U[i]>>V[i];
		deg[U[i]]++,deg[V[i]]++;
	}
	for(int i=1;i<=n;i++) deg[i+1]+=deg[i];
	for(int i=1;i<n;i++){
		to[--deg[U[i]]]=V[i];
		to[--deg[V[i]]]=U[i]; 
	}
	if(n<=4000) solve1::calc();
	else solve2::calc();
	for(int i=1;i<=n+1;i++) deg[i]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
