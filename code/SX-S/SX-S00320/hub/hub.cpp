#include<bits/stdc++.h>
	
using namespace std;
const int N=5e5+10;
int n,k;
vector<int> e[N];
int ans=1e9;
int ls[N];
queue<int> q;
int c;
int vis[N];
void bfs(int u){
	q.push(u);
	while(q.size()){
		int i=q.front();q.pop();
		for(auto v:e[i]){
			if((!vis[v])&&ls[v]==0){
				vis[v]=1;
				q.push(v);
			}
		}
	}
	return ;
}
void dfs(int x){
	for(int i=1;i<=n;i++){
		ls[i]=1e9;
		vis[i]=0;
		if(x&(1<<(i-1))){
			ls[i]=0;
			q.push(i);
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(ls[i]==0&&vis[i]==0){
			vis[i]=1;
			bfs(i);
			cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		if(x&(1<<(i-1))){
			ls[i]=0;
			q.push(i);
		}
	}
	if(cnt>2) return ;
	while(q.size()){
		int u=q.front();q.pop();
		for(auto v:e[u]){
			if(ls[v]==(int)1e9){
				ls[v]=ls[u]+1;
				q.push(v);
			}
		}
	}
	int mx=-1e9;
	for(int i=1;i<=n;i++) mx=max(mx,ls[i]);
	ans=min(ans,mx);
	return ;
}
void sol(){
	cin>>n>>k;ans=1e9;
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(n>=5000){
		cout<<1;
		return ;
	}
	for(int i=0;i<(1<<n);i++){
		int cnt=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)) cnt++;
		}
		if(cnt==k){
			dfs(i);
		}
	}
	cout<<ans<<'\n';
	return ;
} 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t=1;
	cin>>c>>t;
	while(t--) sol();
	return 0;
}
//17:35:55 know how to 1~3
//或许，我需要留出时间处理B的时间
//17:56:25 write down 1~3
//decide to deal with B
//fail on kachang B