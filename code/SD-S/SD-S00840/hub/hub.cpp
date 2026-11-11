#include<bits/stdc++.h>
#define ll long long

using namespace std;
//using namespace __gnu_pbds;

const int N=1e6+5;
int n,k,dis[N],sta,ed,dep[N],st[24][N],macs[N];
vector<int> G[N];

void dfs(int x,int fa){
	for(int i=0;i<G[x].size();i++){
		int y=G[x][i];
		if(y==fa)continue;
		dis[y]=dis[x]+1;
		dfs(y,x);
	}
}
void dfsst(int x,int fa){
	dep[x]=dep[fa]+1;
	st[0][x]=fa;
	for(int i=1;i<=23;i++){
		st[i][x]=st[i-1][st[i-1][x]];
	}for(int y:G[x]){
		if(y==fa)continue;
		dfs(y,x);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=23;i>=0;i--){
		if(dep[st[i][x]]<dep[y])continue;
		x=st[i][x];
	}
	if(x==y){
		return x;
	}
	for(int i=23;i>=0;i--){
		if(st[i][x]==st[i][y])continue;
		st[i][x]=st[i][y];
	}
	return st[0][x];
}
int jump(int x,int deep){
	int cnt=0;
	for(int i=23;i>=0;i--){
		if(dep[st[i][x]]<deep)continue;
		x=st[i][x];
	}
	return x;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x); 
	}
	dfs(1,-1);dfsst(1,0);
	for(int i=1;i<=n;i++){
		if(dis[i]>dis[sta])sta=i;
	}
	memset(dis,0,sizeof dis);
	dfs(sta,-1);
	for(int i=1;i<=n;i++){
		if(dis[i]>dis[ed])ed=i;
	}
	int l=dis[ed]/4,r=dis[ed]/4+1,len=dis[ed];
	int lica=lca(sta,ed),ri,le;
	if(lica>dep[sta]-l){
		ri=jump(ed,dep[ed]-r),le=jump(ed,dep[ed]-(len-l));
	}else if(lica>dep[ed]-r){
		le=jump(sta,dep[sta]-l),ri=jump(sta,dep[sta]-(len-r));	
	}else{
		ri=jump(ed,dep[ed]-r),le=jump(sta,dep[sta]-l);
	}
	memset(macs,0x3f,sizeof macs);
	memset(dis,0,sizeof dis);
	dfs(le,-1);
	for(int i=1;i<=n;i++){
		macs[i]=min(macs[i],dis[i]);
	}
	memset(dis,0,sizeof dis);
	dfs(ri,-1);
	for(int i=1;i<=n;i++){
		macs[i]=min(macs[i],dis[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,macs[i]);
	}
	cout<<ans<<"\n";
//	cout<<len<<" "<<dis[le]<<" "<<le<<" "<<ri<<"\n";
}
signed main(){
//	freopen("hub5.in","r",stdin);
////	freopen("hub5.out","w",stdout);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T=1,c;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}



