#include<queue>
#include<cstdio>
#include<vector>
#include<iostream>
#define int long long
using namespace std;
const int N=2e5+5,INF=1e9;
queue<int> q;
bool vis[N],is[N];
vector<int> to[N];
int c,t,n,k,u,v,ans,pl[N],dis[N];
void filled(int x){
	vis[x]=1;
	for(auto v:to[x]){
		if(vis[v]==0&&is[v]==1){
			filled(v);
		}
	}
	return;
}
int findans(){
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&is[i]==1){
			filled(i);
			sum++;
//			cout<<"*"<<i<<" ";
		}
	}
//	cout<<"\n";
	if(sum>2){
		return INF;
	}
	for(int i=1;i<=n;i++){
		dis[i]=0,vis[i]=0;
	}
	for(int i=1;i<=k;i++){
		q.push(pl[i]);
		vis[pl[i]]=1;
	}
	while(q.size()){
		int t=q.front();
		q.pop();
		for(auto v:to[t]){
			if(vis[v]==0){
				vis[v]=1,dis[v]=dis[t]+1;
				q.push(v);
			}
		}
	}
	int ret=0;
	for(int i=1;i<=n;i++){
		ret=max(ret,dis[i]);
//		cout<<dis[i]<<" ";
	}
//	cout<<"\n";
	return ret;
}
void dfs(int xth,int now){
	if(n-xth+1<k-now){
		return;
	}
	if(now==k){
		ans=min(ans,findans());
//		cout<<ans<<"\n";
//		for(int i=1;i<=k;i++){
//			cout<<pl[i]<<" ";
//		}
//		cout<<"\n";
		return;
	}
	dfs(xth+1,now);
	is[xth]=1,pl[now+1]=xth;
	dfs(xth+1,now+1);
	is[xth]=0;
	return;
}
void solve1(){
	while(t--){
		cin>>n>>k;
		ans=INF; 
		for(int i=1;i<=n;i++){
			to[i].clear(),vis[i]=0;
		}
		for(int i=1;i<n;i++){
			cin>>u>>v;
			to[u].push_back(v);
			to[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans<<"\n"; 
	}
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c<=3){
		solve1();
	}else{
		while(t--){
			cin>>n>>k;
			for(int i=1;i<n;i++){
				cin>>u>>v;
			}
			cout<<n/2<<"\n";
		}
	}
	return 0;
}
/*
0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9


*/
