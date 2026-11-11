#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100;
vector<int>a[N];
int is[N],vis[N];
int lg[N];
int n,w;
//void dfs(int u,int f){
//	id[u]=++cnt;
//	st[0][id[u]]=u;
//	for(auto v:a[u]){
//		if(v==f)continue;
//		dfs(v,u);
//	}
//} 
//int lca(int u,int v){
//	if(u==v)return u;
//	u=id[u];v=id[v];
//	if(u>v)swap(u,v);
//	u++;
//	int log=lg[v-u+1];
//	int x=st[log][x],y[log][y-(1<<(log-1))];
//	if(id[u]<id[v])return u;
//	else return v;
//}
void dfs1(int u,int f){
//	cout<<u<<"-"<<f<<endl;
	vis[u]=1;
	for(auto v:a[u]){
		if(v==f)continue;
		if(!vis[v]&&is[v])dfs1(v,u);
	}
}
int dfs2(int u,int f){
//	cout<<u<<endl;
	if(is[u])return 0;
	int ans=1000000000;
	for(auto v:a[u]){
		if(v==f)continue;
		ans=min(ans,dfs2(v,u));
	}
	return ans+1;
}
void solve(){
	
	memset(vis,0,sizeof(vis));
	cin>>n>>w;
	if(n>100){
		cout<<(((n+1)/2)-w)/4+1<<endl;
		return ;
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}//cout<<"ofv"<<endl;
//	dfs(1,0);
//	for(int i=1;(1<<i)<=n;i++){
//		for(int j=1;(j+(1<<i)-1)<=n;j++){
//			if(id[st[i-1][j]]<id[st[i-1][j+(1<<(i-1))]]){
//				st[i][j]=st[i-1][j];
//			}else{
//				st[i-1][j]=id[st[i-1][j+(1<<(i-1))]];	
//			}
//		}
//	}
	int anser=1000000000;
	for(int i=1;i<(1<<n);i++){
		memset(vis,0,sizeof(vis));
		int uu=0;
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))){
				is[j]=1;uu++;
			}else{
				is[j]=0;
			}
		}
		if(uu!=w)continue;
		
		int kuai=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&is[j]){
				dfs1(j,0);kuai++;
			}
//			if(i==262){
//				for(int dd=1;dd<=n;dd++)cout<<vis[dd]<<" ";
//				cout<<endl;
//			}
		}
	//	cout<<i;
		if(kuai>2)continue;
		//cout<<i<<endl;
		int ans=0;//cout<<i<<"-----------------------------------------------------------"<<endl;
//		if(i==262){
//			for(int j=1;j<=n;j++){
//				cout<<is[j]<<"| ";
//			}
//		}
		for(int j=1;j<=n;j++){
			if(!is[j]){
//				cout<<"----------------"
				ans=max(ans,dfs2(j,0));
			//	cout<<j<<" "<<dfs2(j,0)<<endl;
			}
		}
		//cout<<"ans"<<ans<<endl;
		anser=min(anser,ans);
	}
	cout<<anser<<endl;
	for(int i=1;i<=n;i++)a[i].clear();
	memset(vis,0,sizeof(vis));	
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	lg[1]=0;
	lg[2]=1;
	for(int i=1;i<=30;i++)lg[i]=lg[i/2]+1;
	int c,t;
	cin>>c>>t;
	//cout<<c<<" "<<t<<endl; 
	while(t--)solve();
}

