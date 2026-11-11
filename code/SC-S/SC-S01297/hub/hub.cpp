#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
vector<int> g[N];
int dep[N],ou[N],cnt;
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	if(ou[x]==0){
		cnt=max(cnt,dep[x]);
		return ;
	}
	for(auto v:g[x]){
		dfs(v,x);
	}
	
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		cnt=0;
		memset(dep,0,sizeof dep);
		memset(ou,0,sizeof ou);
		for(int i=1;i<=n;i++) g[i].clear();
		cnt=0;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			ou[u]++;
		}
		int flag=0;
		for(int i=1;i<=n;i++) if(!ou[i]) flag++;
		dep[0]=-1;
		dfs(1,0);
		if(flag==1) cout<<abs(cnt-k-1)<<"\n";
		else cout<<abs(cnt-k)<<"\n";
	}
	return 0;
}