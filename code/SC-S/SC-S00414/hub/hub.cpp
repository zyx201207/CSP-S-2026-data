#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,k;
vector<int>g[(int)2e6+10];
int ans=1e18;
int vis[(int)2e6+10];
int fa[(int)2e6+10];
int siz[(int)2e6+10];
int d[2010][2010];
int cnt[(int)2e6+10];
int dep[(int)2e6+10];
int cnt2[(int)2e6+10]; 
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy)return;
	if(siz[fx]>siz[fy])swap(fx,fy);
	fa[fx]=fy;
	siz[fy]+=siz[fx]; 
}
int check(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		siz[i]=1;
		cnt[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0)continue;
		for(int j=0;j<g[i].size();j++){
			if(vis[g[i][j]]){
				merge(i,g[i][j]);
			}
		}
	}
	int tot=0;
	int k=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			int mn=1e18;
			for(int j=1;j<=n;j++){
				if(vis[j]==1){
					mn=min(mn,d[i][j]);
				}
			}
			k=max(k,mn); 
		}else{
			int fx=find(i);
			if(cnt[fx]==0)tot++;
			if(tot>2)return ans;
			cnt[fx]++;
		}
	}
	return k;
}
void dfs(int x,int y){
	if(y>k)return;
	if(x==n+1){
		if(y!=k)return;
	//	for(int i=1;i<=n;i++)cout<<vis[i]<<' ';
	//	puts("");
	//	cout<<check()<<'\n';
		ans=min(ans,check());
		return;
	}
	vis[x]=1;
	dfs(x+1,y+1);
	vis[x]=0;
	dfs(x+1,y);
}
void dfs2(int x,int y,int dis,int rt){
	d[rt][x]=dis;
	for(int i=0;i<g[x].size();i++){
		int to=g[x][i];
		if(to==y)continue;
		dfs2(to,x,dis+1,rt);
	}
}
vector<int>mx;
vector<int>mx1;
void dfs3(int x,int y){
	dep[x]=dep[y]+1;
	if(mx.size()==0||dep[x]>dep[mx[0]]){
		mx.clear();
		mx.push_back(x);
	}else{
		if(dep[x]==dep[mx[0]]){
			mx.push_back(x);
		}
	}
	for(int i=0;i<g[x].size();i++){
		int to=g[x][i];
		if(to==y)continue;
		dfs3(to,x);
	}
} 
void dfs4(int x,int y){
	dep[x]=dep[y]+1;
	if(mx1.size()==0||dep[x]>dep[mx1[0]]){
		mx1.clear();
		mx1.push_back(x);
	}else{
		if(dep[x]==dep[mx1[0]]){
			mx1.push_back(x);
		}
	}
	for(int i=0;i<g[x].size();i++){
		int to=g[x][i];
		if(to==y)continue;
		dfs3(to,x);
	}
}
vector<int>k1[1010];
int tag;
int cntt[1010];
signed main(){
	//freopen("C:\\Users\\user\\Documents\\down\\hub\\hub1.in","r",stdin);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
//	t=1;
	while(t--){
		cin>>n>>k;
		ans=1e18;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x); 
		}
		for(int i=1;i<=n;i++){
			dfs2(i,0,0,i);
		}
		dfs(1,0);
		cout<<ans<<'\n';
	} 
	return 0;
} 