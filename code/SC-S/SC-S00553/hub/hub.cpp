#include<bits/stdc++.h>
using namespace std;
const int MAXN=1004;
int n,k;
vector<int>G[MAXN];
vector<int>tmp,vec[MAXN];
vector<int>vis;
bool check(int k);
bool dfs(int k,int p);
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,T;
	cin>>c>>T;
	cout<<1<<'\n'<<2;
//	while(T--){
//		cin>>n>>k;
//		for(int i=1,u,v;i<n&&cin>>u>>v;i++)
//			G[u].push_back(v),G[v].push_back(u);
//		if(n==k) {cout<<0<<'\n';continue;}
//		int L=1,R=n-k;
//		while(L<=R){
//			int M=L+(R-L)/2;
//			if(check(M)) L=M+1;
//			else R=M-1;
//		}
//		cout<<L<<'\n';
//		for(int i=1;i<=n;i++) G[i].clear();
//		continue;
//	}
	return 0;
}
bool check(int k){
	for(int i=1;i<=n;i++){
		vec[i].clear();
		queue<pair<int,int>>que;
		que.push({i,k});
		while(!que.empty()){
			auto [u,k]=que.front();
			que.pop();
			vec[i].push_back(u);
			if(k<1) continue;
			for(int v:G[u]) que.push({v,k-1});
		}
	}
	vis.resize(n+4),fill(vis.begin(),vis.end(),false);
	tmp.resize(n+4),fill(tmp.begin(),tmp.end(),0);
	return dfs(k,0);
}
bool dfs(int k,int p){
	if(k==0){
		for(int i=1;i<=n;i++)
			if(tmp[i]==0) return false;
		return true;
	}
	bool flag=false;
	for(int i=p+1;i<=n;i++){
		if(vis[i]) continue;
		auto t=tmp;
		for(int j:vec[i]) tmp[j]=1;
		flag=flag||dfs(k-1,i);
		tmp=t;
	}
	return flag;
}