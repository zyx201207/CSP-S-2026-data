#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int nmax = 1159764;

int n,k;
vector<int>g[nmax];
int fa[nmax],dep[nmax];
int sz[nmax];
int wc[nmax];
int top[nmax];
void dfs(int u,int pa){
	sz[u]=1;
	fa[u]=pa;
	dep[u]=dep[pa]+1;
	for(int v:g[u]){
		if(v==pa)continue;
		dfs(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[wc[u]])wc[u]=v;
	}
}
void dfs2(int u){
	if(wc[u]){
		top[wc[u]]=top[u];
		dfs2(wc[u]);
	}
	for(int v:g[u]){
		if(v==fa[u] or v==wc[u])continue;
		top[v]=v;
		dfs2(v);
	}
}
int LCA(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		u=fa[top[u]];
	}return dep[u]<dep[v]?u:v;
};
int dist(int i,int j){
	int dis1=dep[i];
	int dis2=dep[j];
	int lcaij=LCA(i,j);
	//cout<<i<<" "<<j<<" "<<lcaij<<"\n";
	int dis3=dep[lcaij];
	int dis=dis1+dis2-dis3-dis3;
	return dis;
}
//ll dp[1050][1005][2]; // dp[u][k][is]
//// u wei geng de zi shu zhong
//// xuan ze k ge dian
//// gai zi shu nei de hua fei
//// u xuan le (is=1) mei xuan (is=0)
//void DFS(int u,int k,int cnt,bool is){
//	if(cnt>2)return;
//	
//}
int cnt_blocks;
int tag[nmax];
void dfs_judge(int u){
	if(tag[u] and !tag[fa[u]])cnt_blocks++;
	if(cnt_blocks>=3)return;
	for(int v:g[u]){
		if(v==fa[u])continue;
		dfs_judge(v);
	}
}
bool judge(int mask){
	for(int i=0;i<n;i++)
		if((mask>>i)&1)
		 tag[i+1]=1;
	cnt_blocks=0;
	dfs_judge(1);
	for(int i=1;i<=n;i++)tag[i]=0;
	if(cnt_blocks<=2)return 1;
	return 0;
}
int d[nmax];
void solve(){
 cin>>n>>k;
 for(int i=1;i<=n;i++)g[i].clear();
 memset(fa,0,sizeof fa);
 memset(sz,0,sizeof sz);
 memset(dep,0,sizeof dep);
 memset(wc,0,sizeof wc);
 memset(top,0,sizeof top);
 for(int i=1;i<n;i++){
 	int u,v;cin>>u>>v;
 	g[u].push_back(v);
 	g[v].push_back(u);
	}
	dfs(1,0);
	top[1]=1;
	dfs2(1);
	ll ans=1e9;
 for(int mask=1;mask<(1<<n);mask++){
 	int cnt_1s=0;//cout<<mask<<"\n";
		for(int i=0;i<n;i++)
 		if((mask>>i)&1)
			 cnt_1s++;
		if(cnt_1s!=k)continue;
		if(k!=2 and judge(mask)==0)continue;
		//cout<<"gens "<<mask<<"\n";
		for(int i=0;i<n;i++)if((mask>>i)&1)tag[i+1]=1;
		for(int i=1;i<=n;i++)d[i]=1e9;
		for(int i=1;i<=n;i++){
			//cout<<i<<" ";
		 if(tag[i]){d[i]=0;continue;}
		 for(int j=1;j<=n;j++)
			 if(tag[j]){
			 	int Dis=dist(i,j);
				 d[i]=min(d[i],Dis);
				}
				//cout<<"WHY?\n";
		}
		ll SUM=0;
		for(int i=1;i<=n;i++)tag[i]=0,SUM=max(SUM,d[i]*1ll);
		//,cout<<d[i]<<" ";
		ans=min(ans,SUM);
		//cout<<": ";cout<<SUM<<"\n";
	}
	cout<<ans<<"\n";
	return;
};
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
 freopen("hub.out","w",stdout);
int TEST_ID,CASE;cin>>TEST_ID>>CASE;
while(CASE--)solve();
	// rp++
	// hp++
	// pts++
 return 0;
};