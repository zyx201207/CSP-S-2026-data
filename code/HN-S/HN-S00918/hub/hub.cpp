#include<bits/stdc++.h>
using namespace std;
int T,n,m;
vector<int>tr[4005];
int Fa[4005];
int find(int x){
	return Fa[x]==x?x:Fa[x]=find(Fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x!=y){
		Fa[x]=y;
	}
	return;
}
int dep[4005],f[4005][15],op[4005],d[4005],mp[4005];
void dfs(int u,int fa){
	dep[u]=dep[fa]+1,f[u][0]=fa;
	for(int i=1;(1<<i)<=dep[u];i++){
		f[u][i]=f[f[u][i-1]][i-1];
	}
	for(auto v:tr[u]){
		if(v==fa){
			continue;
		}
		dfs(v,u);
	}
	return;
}
int LCA(int x,int y){
	if(dep[x]<dep[y]){
		swap(x,y);
	}
	for(int i=13;i>=0;i--){
		if(dep[f[x][i]]>=dep[y]){
			x=f[x][i];
		}
	}
	if(x==y){
		return x;
	}
	for(int i=13;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i],y=f[y][i];
		}
	}
	return f[x][0];
} 
int query(int x,int y){
	int lca=LCA(x,y);
	return dep[x]+dep[y]-2*dep[lca];
}
int ans;
void Dfs(int step){
	if(step>n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=op[i],Fa[i]=i,mp[i]=0,d[i]=1e9;
		}
		if(cnt!=m){
			return;
		}
		for(int i=1;i<=n;i++){
			for(auto j:tr[i]){
				if(op[i]&&op[j]){
					merge(i,j);
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(!op[i]){
				continue;
			}
			mp[find(i)]=1;
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=(mp[i]>0);
		}
		if(cnt>2){
			return;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(!op[j]){
					continue;
				}
				d[i]=min(d[i],query(i,j));
			} 
		}
		int r=0;
		for(int i=1;i<=n;i++){
			r=max(r,d[i]);
		}
		ans=min(ans,r);
		return;
	}
	op[step]=1;
	Dfs(step+1);
	op[step]=0; 
	Dfs(step+1);
	return;
}
void work(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		tr[i].clear();
	}
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		tr[u].push_back(v),tr[v].push_back(u);
	}
	ans=1e9;
	dfs(1,0);
	Dfs(1);
	cout<<ans<<"\n";
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T>>T;
	while(T--){
		work();
	}
	return 0;
} 
