#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t;
int n,k;
vector<int>q[N];
void dfs(int st,int ar){
	
}
void solve(){
	cin>>n>>k;
	int u,v;
	for(int i=1;i<=n-1;i++){
		cin>>u>>v;
		q[u].push_back(v);
		q[v].push_back(u);
	}
	int ans=0x3f,d[N];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		solve();
	}
	return 0;
}