#include<bits/stdc++.h>
#define endl '\n'
#define mp make_pair
#define pii pair<int,int>

using namespace std;
int c,t,ans;
int n,k,dis[5005];
vector<int>G[5005],ch;
void csh(){
	for(int i=1;i<=n;i++)G[i].clear();
}
queue<int>q;
void dfs(int idx,int tc){
	if(tc>n-idx+1||tc<0)return;
	if(idx==n+1){
		memset(dis,0x3f,sizeof dis);
		int cnt=0;
		for(auto it:ch)dis[it]=0,q.push(it);
		for(auto it:ch){
			for(auto itt:G[it])cnt+=(dis[itt]==0);
		}
		if(k-cnt/2>2)return;
		while(!q.empty()){
			int tmp=q.front();q.pop();
			for(auto it:G[tmp]){
				if(dis[it]>dis[tmp]+1){
					dis[it]=dis[tmp]+1;
					q.push(it);
				}
			}
		}
		int res=0;
		ans=min(ans,*max_element(dis+1,dis+n+1));
		return;
	}
	ch.push_back(idx);
	dfs(idx+1,tc-1);
	ch.pop_back();
	dfs(idx+1,tc);
}
void solve(){
	ans=INT_MAX;
	cin>>n>>k;
	csh();
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,k);
	cout<<ans<<endl;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
	return 0;
} 
