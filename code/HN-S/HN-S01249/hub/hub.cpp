#include<bits/stdc++.h>
#define eps 1e-7
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
#define fi first
#define se second
#define MAXN 1000005
int n,k,dep[MAXN],f[MAXN][21];
vector<int>v[MAXN];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1,f[x][0]=fa;
	for(int i:v[x])if(i!=fa)dfs(i,x);
}
int LCA(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int j=20;j>=0;j--)
		if(dep[f[x][j]]>=dep[y])
			x=f[x][j];
	if(x==y)return x;
	for(int j=20;j>=0;j--)
		if(f[x][j]!=f[y][j])
			x=f[x][j],y=f[y][j];
	return f[x][0];
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
bool bl[MAXN];int Fa[MAXN],Ans;
int Find(int x){return Fa[x]==x?x:Fa[x]=Find(Fa[x]);}
void Union(int x,int y){
	x=Find(x),y=Find(y);
	if(x!=y)Fa[x]=y;
}
bool check(){
	for(int i=1;i<=n;i++)
		if(bl[i])Fa[i]=i;
	for(int i=1;i<=n;i++)if(bl[i])
		for(int x:v[i])if(bl[x])
			Union(i,x);
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(bl[i]&&Fa[i]==i)cnt++;
	return cnt<=2;
}
void DFS(int dep,int cnt){
	if(dep==n+1){
		if(!check())return;
		int ans=0;
		for(int i=1;i<=n;i++)if(!bl[i]){
			int res=inf;
			for(int j=1;j<=n;j++)if(bl[j])
				res=min(res,dis(i,j));
			ans=max(ans,res);
		}
		Ans=min(Ans,ans);
		return;
	}
	if(cnt==k)return bl[dep]=0,DFS(dep+1,k);
	if(dep+k-cnt<=n)bl[dep]=0,DFS(dep+1,cnt);
	bl[dep]=1,DFS(dep+1,cnt+1);
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)v[i].clear();
	for(int i=1;i<n;i++){
		int a,b;cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,0);
	for(int j=1;j<=20;j++)
		for(int i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
	Ans=inf;
	DFS(1,0);
	cout<<Ans<<'\n';
}
signed main(){
	auto ST=clock();
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int C,T=1;cin>>C>>T;
	while(T--)solve();
	auto EN=clock();
	cerr<<LD(EN-ST)/CLOCKS_PER_SEC<<endl;

	return 0;
}