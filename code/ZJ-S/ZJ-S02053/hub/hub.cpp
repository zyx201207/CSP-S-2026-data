#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int c,T,n,k,top,s[N][105];
vector<int> g[N];
void dfs(int x,int cnt){
	if(x>n||cnt>k){
		if(cnt>k) top++;
		return;
	}
	dfs(x+1,cnt);
	s[top][cnt]=x;
	dfs(x+1,cnt+1);
}
signed main(){
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1,u,v;i<n;++i){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,1);
		for(int i=1;i<=top;++i){
			for(int j=1;j<=k;++j){
				cout<<s[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
}
