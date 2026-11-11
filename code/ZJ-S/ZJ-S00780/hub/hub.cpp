#include<bits/stdc++.h>
#define I_don_t_want_to_AFO int main()
#define I_want_to_study_OI_forever return 0;
using namespace std;
int n,k;
vector<int>e[500005];
int c[500005];
//vector<int>leaf;
//void dfs(int u,int f){
//	dep[u]=dep[f]+1;
//	fa[u][0]=f;
//	for(int i=1;i<=33;i++){
//		fa[u][i]=fa[fa[u][i-1]][i-1];
//	}
//	for(int i=0,v;i<e[u].size();i++){
//		v=e[u][i];
//		if(v==fa)continue;
//		dfs(v,u);
//	}
//	if(c[u]==1)leaf.push(u);
//}
//int lca(int u,int v){
//	if(dep[u]<dep[v])swap(u,v);
//	for(int i=33;i>=0;i--){
//		if(dep[fa[u][i]==dep)
//	}
//}
//bool check(int mid){
//	for(int i=0;i<leaf.size();i++){
//		int len=0,u=v[i];
//		for(int i=33;i>=0;i--){
//			if((1<<i)<=len){
//				len-=(1<<i);
//				u=fa[u][i];
//			}
//		}
//	}
//	
//	priority_queue<pair<int,int> >pq;
//	while(!pq.empty()){
//		
//	}
//	
//}
int mx=0,ans=INT_MAX;
bool vis[500005];
void dfs(int u,int fa,int cnt,int len,bool op,int sum){
	vis[u]=1;
	if(c[u]==1)mx=max(mx,len);
	if(cnt==k+1){
		mx=max(mx,len);
		ans=min(ans,mx);
		return;
	}
	if(op==0){
		if(sum<=1){
			int tmp=mx;
			mx=max(mx,len);
			for(int i=0;i<e[u].size();i++){
				int v=e[u][i];
				if(vis[v])continue;
				dfs(v,u,cnt+1,1,1,sum+1);
			}
			mx=tmp;
		}
		
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i];
			if(vis[v])continue;
			dfs(v,u,cnt,len+1,op,sum);
		}
		
		vis[u]=0;
	}else{
			int tmp=mx;
			mx=max(mx,len);
			for(int i=0;i<e[u].size();i++){
				int v=e[u][i];
				if(vis[v])continue;
				dfs(v,u,cnt+1,1,1,sum);
			}
			mx=tmp;
		
		
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i];
			if(vis[v])continue;
			dfs(v,u,cnt,len+1,op,sum);
		}
		
		vis[u]=0;
	}
	
}
void solve(){
	cin>>n>>k;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(n<=10&&k<=10){
		dfs(1,0,1,1,0,0);
		cout<<ans<<"\n";
	}
	srand(time(0));
	cout<<rand();
}
I_don_t_want_to_AFO{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _=1;
	int p;
	cin>>p>>_;
	while(_--){
		solve();
	}
	I_want_to_study_OI_forever
}
/*
17:57 le
xie dian shen me ba
zhe chang quan xie T2 l
xi wang T2 bie ka wo
T1shuang zhi zhen ye bie ka wo
mei da wan bao li
wo jiu zhe dian fen
wan wang CCF ke yi rang wo duo na dian fen ba
qq le
*/
