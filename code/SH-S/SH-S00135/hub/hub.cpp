#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

using namespace std;
const int N=100+5;
const int N1=1e5+5;
vector<int> g[N1];
int n,k;
long long s;
bitset<N> ch,vis;

void dfs1(int u){
	vis[u]=true;
	for(auto v:g[u])
		if(!vis[v]&&ch[v])
			dfs1(v);
}
bool check(){
	int ans=0;
	vis.reset();
	rep(i,1,n)
		if(ch[i]&&(!vis[i])){
			dfs1(i);
			ans++;
		}
	if(ans==1||ans==2)return true;
	else return false;
}
int dis[N];
void dfs2(int u,int fa){
	for(auto v:g[u])
		if(v!=fa&&ch[v]==false){
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				dfs2(v,u);
			}
			
		}
}
int cal(){
	memset(dis,0x3f,sizeof(dis));
	rep(i,1,n)
		if(ch[i])
			dis[i]=0;
	rep(i,1,n)
		if(ch[i])
			dfs2(i,0);
	int ans=0;
	rep(i,1,n)ans=max(ans,dis[i]);
	return ans;
}
int ANS=2e9;
void dfs(int dep,int t){
	if(t>k)return;
	if(dep==n+1){
		//cout<<s<<endl;
		if(t!=k)return;
		if(!check())return;
		//cout<<'b';
		ANS=min(ANS,cal());
		return;
	}
	ch[dep]=1;
	dfs(dep+1,t+1);
	ch[dep]=0;
	dfs(dep+1,t);
}

int f[N1][2];
void dfs3(int u,int fa){
	f[u][1]=0;
	//cout<<u<<endl;
	for(auto v:g[u])
		if(v!=fa){
			dfs3(v,u);
			if(f[v][1]+1>f[u][1]){
				f[u][2]=f[u][1];
				f[u][1]=f[v][1]+1;
			}
			else if(f[v][1]+1>f[u][2])
				f[u][2]=f[v][1]+1;
		}
}
void solve2(){
	cin>>n>>k;
	rep(i,1,n)g[i].clear();
	rep(i,1,n-1){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	//zhao zhijing
	//cout<<'a';return;
	dfs3(1,0);
	//cout<<'a';
	int max=-2e9,num=0;
	rep(i,1,n)
		if(f[i][1]+f[i][2]>max){
			max=f[i][1]+f[i][2];
			num=i;
		}
	if(k==1)cout<<(f[num][1]+f[num][2]+1)/2<<endl;
	else cout<<ceil(1.0*(f[num][1]+f[num][2])/3)<<endl;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5

*/
void solve(){
	cin>>n>>k;
	rep(i,1,n)g[i].clear();
	rep(i,1,n-1){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ANS=2e9;
	dfs(1,0);
	cout<<ANS<<endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int c=0,TEST=1;
	cin>>c>>TEST;
	if(c==7||c==11||c==12){
		while(TEST--)
			solve2();
	}else{
		while(TEST--)
		solve();
	}
	return 0;
}
