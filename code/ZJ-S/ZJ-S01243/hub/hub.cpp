#include<bits/stdc++.h>
using namespace std;
const int N=1e6+16;
const int M=2e6+1;
int c,t;
int n,k;
int u,v;
vector<int> r[N];
int ans=M;
void dfs(int num,int x,int r,int mn){
	if(x==n+1){
		if(num==0){
			return;
		}
		mn=max(r,mn);
		ans=min(mn,ans);
		return;
	}
	if(num==k){
		dfs(num,x+1,r,mn+1);
		return ;
	}
	if(num==0){
		dfs(num+1,x+1,mn,0);
		dfs(num,x+1,r,mn+1);
		return;
	}
	dfs(num+1,x+1,max(r,mn/2+mn%2),0);
	dfs(num,x+1,r,mn+1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=M;
		for(int i=1;i<=n-1;i++){
			cin>>u>>v;
			r[u].push_back(v);
			r[v].push_back(u);
		}
		dfs(0,1,0,0);
		
		dfs(1,1,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
