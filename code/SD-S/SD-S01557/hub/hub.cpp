#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,T,n,k; 
vector<int>e[N];
vector<int>vec;
int res=0;
int dis[N];
queue<int>q;
bool vis[N],vi[N];
void dfs(int u,int pa){
	vi[u]=1;
	for(auto v:e[u]){
		if(v!=pa&&vis[v])dfs(v,u);
	}
}
bool check(int S){
	memset(vi,0,sizeof(vi));
	int cnt=0;
	for(int i=1;i<=n;i++){
		if((S>>(i-1))&1){
			if(!vi[i])dfs(i,0),cnt++;
		}
	}
	return cnt<=2;
}
void bfs(int S){
	memset(dis,0x3f,sizeof(dis));
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++){
		if(vis[i]==1)q.push(i),dis[i]=0;
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:e[u]){
			if(vis[v])continue;
			dis[v]=dis[u]+1;
			vis[v]=1;
			q.push(v);
		}
	}
	return;
}
void sub1(){
	int ans=0x3f3f3f3f;
	for(int S=1;S<(1<<n);S++){
		if(__builtin_popcount(S)!=k)continue;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			if((S>>(i-1))&1)vis[i]=1;
		}
		if(!check(S))continue;
		bfs(S);
		int res=0;
		for(int i=1;i<=n;i++)res=max(res,dis[i]);
		ans=min(ans,res);
	}
	cout<<ans<<"\n";
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(k==n){
		cout<<"0\n";
		return;
	}
	if(n<=10){
		sub1();
		return;
	}
	if((n/2)<=k){
		cout<<"1\n";
		return;
	}
	cout<<(n/2-k+3)/4+1<<"\n";
	return;
	/*if(k<=2){
		sub2();
		return;
	}*/
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
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
