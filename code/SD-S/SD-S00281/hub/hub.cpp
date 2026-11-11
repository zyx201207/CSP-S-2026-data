#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*f;
}
int c,t,n,k;
vector<int>e[15];
const int N=1e6+5;
pair<int,int>edge[N];
int u,v,ans,cnt;
int siz[20],fa[20];
bool flag[20];
bool vis[20];
int dep[20],f[20][6];
int lca(int u,int v){
//	bool flag=(u==2&&v==3);
	if(dep[u]<dep[v])swap(u,v);
	for(int i=5;i>=0;i--){
		if(dep[f[u][i]]>=dep[v])
		u=f[u][i];
	}
	if(u==v)return u;
	for(int i=5;i>=0;i--){
	//	if(flag)cout<<f[u][i]<<" "<<f[v][i]<<'\n';
		if(f[u][i]!=f[v][i]){
			u=f[u][i];
			v=f[v][i];
		}
	}
	return f[u][0];
}
int dis(int u,int v){
	int w=lca(u,v);
//	if(u==2&&v==3){
//		cout<<"lca(2,3)="<<w<<'\n';
//	}
	return dep[u]+dep[v]-2*dep[w];
}
int go(int p){
	if(p==fa[p])return p;
	else return fa[p]=go(fa[p]);
}
void merge(int u,int v){
	u=go(u),v=go(v);
	if(u^v)fa[u]=v;
}
void dfs(int x){
	if(x==n+1){
		if(cnt==k){
//			cout<<"have:";
//			for(int i=1;i<=n;i++){
//				if(flag[i])cout<<i<<" ";
//			}
//			cout<<'\n';
		//	if(flag[2]&&flag[7]&&flag[9])puts("trying");
			for(int i=1;i<=n;i++){
				vis[i]=false;
				fa[i]=i;
				siz[i]=1;
			}
			for(int i=1;i<n;i++){
				if(flag[edge[i].first]&&flag[edge[i].second])
				merge(edge[i].first,edge[i].second);
			}
			int tot=0;
			for(int i=1;i<=n;i++){
				if(!vis[go(i)]&&flag[i]){
					vis[go(i)]=true;
					tot++;
				}
			}
		//	cout<<"tot="<<tot<<'\n';
			if(tot>2)return;
	//		cout<<"hahha\n";
			int mx=0;
			for(int i=1;i<=n;i++){
				if(!flag[i]){
					int mn=1e18;
					for(int j=1;j<=n;j++)
					if(flag[j])mn=min(mn,dis(i,j));
//					for(int j=1;j<=n;j++){
//											if(flag[j]&&flag[2]&&flag[7]&&flag[9]){
//						cout<<"i="<<i<<'\n';
//						cout<<"j="<<j<<'\n';
//						cout<<"dis(i,j)="<<dis(i,j)<<'\n';
//					}	
//					}
					mx=max(mx,mn);
				}
			}
			ans=min(ans,mx);
		}
		return;
	}
	dfs(x+1);
	cnt++;
	flag[x]=true;
	dfs(x+1);
	cnt--;
	flag[x]=false;
}
void dfs_init(int x,int pr){
//	if(x==3&&pr==2&&n==10){
//		cout<<"sb\n";
//	}
	dep[x]=dep[pr]+1;
	f[x][0]=pr;
	for(int i=1;i<=5;i++)f[x][i]=f[f[x][i-1]][i-1];
	for(auto y:e[x]){
		if(y!=pr)dfs_init(y,x);
	}
}
void solve(){
	for(int j=0;j<=5;j++)for(int i=1;i<=n;i++)f[i][j]=0;
	for(int i=1;i<=n;i++)e[i].clear();
	n=read(),k=read(),ans=1e18,cnt=0;
//	cout<<ans<<'\n';
	for(int i=1;i<n;i++){
		u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
		edge[i]={u,v};
	}
//	if(n==10){
//	//	cout<<f[2][0]<<'\n';
//	//	cout<<f[3][0]<<'\n';
//	//	cout<<"jjj\n";
//	}
	dfs_init(1,0);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(i==j)continue;
//			cout<<i<<" "<<j<<" "<<lca(i,j)<<'\n';
//		}
//	}
//	for(int i=1;i<=n;i++){
//		cout<<i<<":";
//		for(int j=0;j<=2;j++)cout<<f[i][j]<<" ";
//		cout<<'\n';
//	}
	dfs(1);
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--)solve();
	return 0;
}/*
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



0 1
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

