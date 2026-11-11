#include<bits/stdc++.h>
using namespace std;

int C,T;
int n,k,vis[20],dis[20],fa[20][6],dep[20],p[20],cnt,ans,awa[20];
vector<int>v[20]; 
void dfs(int x,int Fa){
//	cout<<"!!!"<<x<<"\n";
	fa[x][0]=Fa;
	dep[x]=dep[Fa]+1;
	for(auto y:v[x]){
		if(y==Fa)
			continue;
		dfs(y,x);
	}
}
int lca(int x,int y){
	if(x==y)
		return x;
	if(dep[x]<dep[y])
		swap(x,y);
	for(int i=5;i>=0;i--){
		if(dep[fa[x][i]]>dep[y])
			x=fa[x][i];
			
	}
	if(dep[x]!=dep[y])
		x=fa[x][0];
	if(x==y)
		return x;
	for(int i=5;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int query(int x,int y){
	int tmp=lca(x,y);
	return dep[x]+dep[y]-2*dep[tmp];
}
void check(){
	int qwq=0;
	for(int i=1;i<=n;i++){
		int rans=n+10;
		for(int j=1;j<=n;j++){
			if(vis[j])
				rans=min(rans,query(i,j));
		}
		qwq=max(qwq,rans);
	}
	ans=min(ans,qwq);
}
void work(int x){
	awa[x]=1;
	for(auto y:v[x]){
		if(vis[y]&&!awa[y])
			work(y);
	}
}
void Dfs(int x,int qwq){
	if(x==n+1){
		if(qwq!=k)
			return ;
		for(int i=1;i<=n;i++)	
			awa[i]=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]&&!awa[i]){
				cnt++;
				work(i);
			}
		}
		if(cnt>2)
			return ;
		check();
		return ;
	}
	vis[x]=1;
	Dfs(x+1,qwq+1);
	vis[x]=0;
	Dfs(x+1,qwq);
}
void Clear(){
	ans=100000000;
	for(int i=1;i<=n;i++)	
		v[i].clear(),dep[i]=dis[i]=vis[i]=0;
	memset(fa,0,sizeof fa);
}
void solve(){
	Clear();
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<6;i++)
		for(int j=1;j<=n;j++)
			fa[j][i]=fa[fa[j][i-1]][i-1];
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<6;j++)
//			cout<<fa[i][j]<<" ";
//		cout<<"\n";
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=i;j<=n;j++)
//			cout<<query(i,j)<<" ";
//		cout<<"\n";
//	}
	Dfs(1,0);
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--)
		solve();
	
	return 0;
} 
