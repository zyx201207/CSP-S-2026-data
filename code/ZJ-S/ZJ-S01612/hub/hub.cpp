#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,k;
vector<int>G[N];
int lowbit(int x){
	return x&(-x);
}
bool check(int x){
	while(x)
		++cnt,x-=lowbit(x);
	return cnt==k;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _;cin>>_>>_;
	while(_--){
		cin>>n>>k;
		for(int i=1;i<=n;++i)G[i].clear();
		for(int i=1;i<n;++i){
			int u,v;cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int S=1;S<=(1<<n)-1;++S){
			if(!check(S))continue;
			
		}
	}
}
