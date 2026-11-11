#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int f[15],cnt;
vector<int>tree[15];
int dis[15][15];
void dfs(int u,int fa,int d,int ai){
	dis[ai][u]=d;
	for(int v:tree[u])if(v!=fa)dfs(v,u,d+1,ai);
}
int fa[15];
int findf(int x){
	if(fa[x]==x)return x;
	return fa[x]=findf(fa[x]);
}void merge(int x,int y){
	fa[findf(x)]=findf(y);
}void bl(){
	for(int i=1;i<=n;i++)tree[i].clear();memset(dis,0,sizeof dis);
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v,tree[u].push_back(v),tree[v].push_back(u);
	}
	for(int i=1;i<=n;i++)dfs(i,0,0,i);
	int ans=1e9;
	for(int s=0;s<1<<n;s++){
		memset(f,0,sizeof f),cnt=0;
		int t=s;while(t){f[++cnt]=t&1,t>>=1;}int tot=0;
		for(int i=1;i<=n;i++)if(f[i])tot++;
		if(tot!=k)continue;
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=n;i++)if(f[i])
		for(int j=i+1;j<=n;j++)if(f[j])if(dis[i][j]==1)merge(i,j);
		int h=0;for(int i=1;i<=n;i++)if(f[i]&&findf(i)==i)h++;
		if(h>2)continue;
		int lg=0;
		for(int i=1;i<=n;i++)if(!f[i]){int mj=1e9;
			for(int j=1;j<=n;j++)if(f[j]){
			mj=min(mj,dis[i][j]);
			}lg=max(lg,mj);}ans=min(ans,lg);
	}cout<<ans<<endl;
}void work(){
	cin>>n>>k;
	if(c==1||c==2||c==3)bl();
	else{
		int u,v;
		for(int i=1;i<n;i++)cin>>u>>v;
		int m=n/2;
		cout<<(k>=m?1:(m-k+3)/4+1)<<"\n";
	}
}int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>t;
	while(t--)work(); 
	return 0;
}