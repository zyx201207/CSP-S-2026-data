#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
bool vis[N];
int com[N],c,n,k,T,ans;
//~ vector<int> G;
//~ int work(){
	
//~ }
//~ void dfs(int cnt,int last){
	//~ if(cnt==k){
		//~ ans=min(ans,work());
		//~ return;
	//~ }
	//~ for(int i=last;i<=n;i++){
		//~ if(!vis[i]){
			//~ vis[i]=1;
			//~ com[cnt+1]=i;
			//~ dfs(cnt+1,i);
			//~ vis[i]=0;
		//~ }
	//~ }
//~ }
int main(){
	freopen("hub5.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	if(c==13||c==14){
		int le=n/2-1-(k/2),ri=(k+1)/2;
		for(int i=1;i<=n;i++){
			if(i>ri&&i<le){
				ans+=(2*i-2*ri+k)*k/2;
			}else if(i>le){
				ans+=(2*i-2*le+k)*k/2;
			}
		}
		cout<<ans;
		//~ while(T--){
			//~ cin>>n>>k; G.clear();
			//~ ans=INT_MAX; memset(com,0,sizeof(com));
			//~ for(int i=1;i<n;i++){
				//~ cin>>u>>v;
				//~ G[u].push_back(v);
				//~ G[v].push_back(u);
			//~ }
			//~ dfs(0,1);
			//~ cout<<ans<<'\n';
		//~ }
	}
	return 0;
}
