#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int c,T,n,k,ans,fa[N][30],dep[N],a[N],b[N];
bool used[N];
vector<int> g[N];
void dfs(int u,int f){
	fa[u][0]=f;
	for(int i=1;i<=20;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	dep[u]=dep[f]+1;
	for(auto v:g[u])
		if(v^f)
			dfs(v,u);
}
int getlca(int u,int v){
	if(dep[u]<dep[v])
		swap(u,v);
	for(int i=20;i>=0;i--)
		if(dep[fa[u][i]]>=dep[v])
			u=fa[u][i];
	if(u==v)
		return u;
	for(int i=20;i>=0;i--)
		if(fa[u][i]^fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int rt(int x){
	if(b[x]^x)
		return b[x]=rt(b[x]);
	return x;
}
bool check(int u,int f){
	for(auto v:g[u])
		if(v^f&&used[v]){
			check(v,u);
			b[rt(v)]=rt(u);
		}
}
int calc(){
	int res=0;
	for(int i=1;i<=n;i++)
		if(!used[i]){
			int dis=1e18;
			for(int j=1;j<=k;j++){
				int lca=getlca(i,a[j]);
				dis=min(dis,dep[i]+dep[a[j]]-2*dep[lca]);
			}
			res=max(res,dis);
		}
	return res;
}
void getans(int cnt){
	for(int i=1;i<=n;i++)
		if(!used[i]){
			used[i]=true;
			a[cnt]=i;
			if(cnt==k){
				for(int j=1;j<=k;j++)
					b[a[j]]=a[j];
				check(a[1],0);
				int cn=0;
				for(int j=1;j<=k;j++)
					if(b[a[j]]==a[j])
						cn++;
				if(cn<=2)
					ans=min(ans,calc());
			}
			else
				getans(cnt+1);
			used[i]=false;
		}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		ans=1e18;
		for(int i=0;i<=n;i++){
			g[i].clear();
			used[i]=dep[i]=fa[i][0]=0;
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		getans(1);
		cout<<ans<<"\n";
	}
	return 0;
}
