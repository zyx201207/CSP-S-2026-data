#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e6+7;
const int INF=1e9;
int N,k,ans=INF;
vector <int> tmp;
vector <int> adj[MAXN];
bool vis[MAXN];
bool flag[MAXN];
int son[MAXN];
int dep[MAXN];
int si[MAXN];
int fa[MAXN];
int top[MAXN];
void pull(int now){
	queue <int> que;
	que.push(now);
	while(!que.empty()){
		int u=que.front();que.pop();
		for(int v:adj[u]){
			if(!flag[v])continue;
			flag[v]=false;
			que.push(v);
		}		
	}
}
bool check(){
	int cnt=0;
	for(int val:tmp)flag[val]=1;
	for(int i=1;i<=N;i++){
		if(flag[i]){
			flag[i]=false;
			pull(i);
			cnt++;
//			if(cnt>2)return false;
		}
	}
	
//	for(int x:tmp)cout<<x<<" ";
//	cout<<'\n';
//	cout<<cnt<<'\n';
	if(cnt>2)return false;
	else return true;
}
void dfs1(int u,int Fa){
	dep[u]=dep[Fa]+1;
	fa[u]=Fa;
	si[u]=1;
	for(int v:adj[u]){
		if(v==Fa)continue;
		dfs1(v,u);
		si[u]+=si[v];
		if(si[son[u]]<si[v])son[u]=v;
	}
}
void dfs2(int u,int Top){
	top[u]=Top;
	if(son[u])dfs2(son[u],Top);
	for(int v:adj[u])if(v!=son[u]&&v!=fa[u])dfs2(v,v);
}
int Find(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
int Dis(int x,int y){
	return dep[x]+dep[y]-2*dep[Find(x,y)];
}
int deal(){
	int res1=INF,res2=0;
	for(int x:tmp)vis[x]=true;
//	for(int x:tmp)cout<<x<<" ";
//	cout<<'\n';
	for(int i=1;i<=N;i++){
		if(vis[i])continue;
		res1=INF;
		for(int j:tmp){
//			cout<<"________"<<i<<" "<<j<<' '<<Dis(i,j)<<'\n';
			res1=min(res1,Dis(i,j));
		}
//		cout<<"_"<<res1<<'\n';
		res2=max(res2,res1);
	}
	for(int x:tmp)vis[x]=false;
//	cout<<res2<<'\n';
	return res2;
}
void dfs(int lst,int cnt){
	if(cnt==k){
		
		if(check()){
//			for(int x:tmp)cout<<x<<" ";
//			cout<<'\n';			
			int tmp1=deal();
//			cout<<"__"<<tmp1<<'\n';
			ans=min(ans,tmp1);	
		}
		return ;
	}
	for(int i=lst+1;i<=N;i++){
		tmp.push_back(i);
		dfs(i,cnt+1);
		tmp.pop_back();
	}
}
void init(){
	ans=INF;
	for(int i=1;i<=N;i++)adj[i].clear(),son[i]=0,dep[i]=0,si[i]=0,fa[i]=0,top[i]=0;
}
void solve(){
	cin>>N>>k;
	init();
	for(int i=1,u,v;i<N;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
//	tmp.push_back(2);
//	tmp.push_back(4);
//	tmp.push_back(8);
//	cout<<check();
	dfs1(1,0);
	dfs2(1,1);
	dfs(0,0);
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)solve();
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