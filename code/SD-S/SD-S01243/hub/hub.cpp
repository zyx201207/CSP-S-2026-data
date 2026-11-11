#include<bits/stdc++.h>
#define N 2000005
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int c,T,n,k,V[N<<1],fst[N],nxt[N<<1],idx=1,a[11],vis[11],dis[11],ans,b[11][11];
queue<int> q;
ll rd(){
	ll x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^'0');
		c=getchar();
	}
	return x;
}
void add(int a,int b){
	V[idx]=b;
	nxt[idx]=fst[a];
	fst[a]=idx++;
}
void dfs(int x){
	if(x==k+1){
		int flag=0;
		for(int i=1;i<=k;i++){
			for(int j=i+1;j<=k;j++){
				if(b[a[i]][a[j]]) flag++;
			}
		}
		if(k-flag>2) return;
		int p=0;
		for(int i=1;i<=n;i++) dis[i]=INF;
		for(int i=1;i<=k;i++) q.push(a[i]),dis[a[i]]=0;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=fst[u];i;i=nxt[i]){
				int v=V[i];
				if(dis[v]>dis[u]+1){
					dis[v]=dis[u]+1;
					q.push(v);
				}
			}
		}
		for(int i=1;i<=n;i++) p=max(p,dis[i]);
		ans=min(ans,p);
	}
	for(int i=a[x-1]+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
void work(){
	idx=1;
	memset(fst,0,sizeof(fst));
	memset(b,0,sizeof(b));
	n=rd(),k=rd();
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		add(u,v);
		add(v,u);
		if(c<=3) b[u][v]=b[v][u]=1;
	}
	if(c<=3){
		ans=2e9;
		dfs(1);
		cout<<ans<<"\n";
		return;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=rd(),T=rd();
	while(T--) work();
	return 0;
}
//16:16 -15
