#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,t;
int n,k;
vector<int>g[N];
int fath[N];
void dfs(int u,int f){
	fath[u]=f;
	for(auto i:g[u]){
		if(i==f)continue;
		dfs(i,u);
	}
}
int ans;
bool is[N];
bool fl[N];
void check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(is[i]){
			if(is[fath[i]])continue;
			cnt++;
			if(cnt>2)return;
		}
	}
	memset(fl,false,sizeof fl);
	queue<pair<int,int>>q;
	for(int i=1;i<=n;i++){
		if(is[i])q.push({i,0});
	}
	int res=0;
	int u,l;
	while(!q.empty()){
		u=q.front().first,l=q.front().second;
		q.pop();
		if(fl[u])continue;
		fl[u]=true;
		res=max(res,l);
		for(auto i:g[u]){
			q.push({i,l+1});
		}
	}
	ans=min(ans,res);
}
void get(int u,int cnt){
	if(cnt>k)return;
	if(u>n){
		if(cnt!=k)return;
		check();
		return;
	}
	is[u]=true;
	get(u+1,cnt+1);
	is[u]=false;
	get(u+1,cnt);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		ans=1e9;
		int u,v;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		get(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}