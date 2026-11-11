#include<bits/stdc++.h>
using namespace std;
#define N 1000008
vector<int>e[N];
int c,t,n,k,u,v,res;
bool used[N],ok[N];
void dfs(int node){
	if(used[node]||!ok[node]) return;
	used[node]=1;
	for(int i=0;i<(int)e[node].size();i++) dfs(e[node][i]);
}
int ff(int node,int fa){
	int ans=0;
	if(ok[node]) return 0;
	for(int i=0;i<(int)e[node].size();i++) if(e[node][i]!=fa) ans=max(ans,ff(e[node][i],node)+1);
	return ans;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;res=INT_MAX;
		for(int i=1;i<n;i++) cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
		for(int i=0;i<(1<<n);i++) if(__builtin_popcount(i)==k){
			int cnt=0;
			for(int j=0;j<n;j++) if(i&(1<<j)) ok[j+1]=1;
			for(int j=1;j<=n;j++) if(!used[j]&&ok[j]) dfs(j),cnt++;
			if(cnt<=2){
				int amt=0;
				for(int j=1;j<=n;j++) amt=max(ff(j,j),amt);
				res=min(res,amt);
			}
			for(int j=1;j<=n;j++) ok[j]=used[j]=0;
		}
		for(int i=1;i<=n;i++) e[i].clear();
		cout<<res<<'\n';
	}
	return 0;
} 

