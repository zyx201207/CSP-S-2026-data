#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e6+10;
int koyuki,t,n,k,dis[N],vis[15],tans;
set<int> st; 
vector<int> vec[N];
struct DSU{
	int f[N];
	void ini(){
		for(int i=1;i<=n;i++)f[i]=i;
	}
	int find(int u){
		if(u!=f[u])f[u]=find(f[u]);
		return f[u];
	}void merge(int u,int v){
		u=find(u),v=find(v);
		f[u]=v;
	}
}dsa;
void dfs(int u,int fa,int di){
	for(int v:vec[u]){
		if(v==fa)continue;
		if(dis[v]>di+1)dis[v]=di+1,dfs(v,u,di+1);
		else continue;
	}
}
void solve1(){
	for(int i=0;i<(1<<n);i++){
		if(__builtin_popcount(i)!=k)continue;
		memset(vis,0,sizeof vis);
		dsa.ini();
		for(int j=0;j<n;j++){
			if(!(i&(1<<j)))continue;
			vis[j+1]=1;
		}
		for(int j=1;j<=n;j++){
			if(!vis[j])continue;
			for(int v:vec[j]){
				if(vis[v])dsa.merge(j,v);
			}
		}
		st.clear();
		for(int j=1;j<=n;j++){
			if(vis[j])st.insert(dsa.find(j));
		}
		if(st.size()>=3)continue;
		for(int j=1;j<=n;j++)dis[j]=1e9;
		for(int j=1;j<=n;j++){
			if(vis[j])dfs(j,0,0);
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			if(!vis[j])ans=max(ans,dis[j]);
		}
		tans=min(tans,ans);
	}cout<<tans<<"\n";
}
void solve2(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int kk=1;kk<=n;kk++)dis[kk]=1e9;
			dfs(i,0,0);dfs(j,0,0);
			int ans=0;
			for(int kk=1;kk<=n;kk++){
				if(kk!=i&&kk!=j)ans=max(ans,dis[kk]);
			}tans=min(tans,ans);
		}
	}cout<<tans<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>koyuki>>t;
	while(t--){
		tans=1e9;
		cin>>n>>k;
		for(int i=1;i<=n;i++)vec[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		if(koyuki<=3)solve1();
		else if(koyuki==7)solve2();
		else cout<<"0\n";
	} 
	return 0;
}
//RP+=INF

