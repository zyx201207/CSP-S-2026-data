#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e5+5;
int c,t,n,k,f[N][30],dep[N],fa[N];
struct node{
	int u,v;
}a[N];
int fd(int x){
	if(fa[x]!=x) fa[x]=fd(fa[x]);
	return fa[x];
}
vector <int> g[N];
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	for(auto v:g[u]){
		if(v==fa) continue;
		f[v][0]=u;
		dfs(v,u);
	}
	return ;
}
int lca(int a,int b){
	if(dep[a]<dep[b]) swap(a,b);
	for(int i=25;i>=0;i--){
		if(dep[f[a][i]]>=dep[b]) a=f[a][i];
	}
	if(a==b) return a;
	for(int i=25;i>=0;i--){
		if(f[a][i]!=f[b][i]){
			a=f[a][i];
			b=f[b][i];
		} 
	}
	return f[a][0];
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		vector <int> vc;
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			a[i]={u,v};
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		for(int i=1;i<=25;i++){
			for(int j=1;j<=n;j++){
				f[j][i]=f[f[j][i-1]][i-1];
			}
		}
		for(int i=1;i<=n;i++){
			if(i<=k) vc.push_back(1);
			else vc.push_back(0);
		}
		vc.push_back(0);
		reverse(vc.begin(),vc.end());
		int ans=0x7fffffff;
		do{
			vector <int> v;
			for(int i=1;i<=n;i++){
				fa[i]=i;
				if(vc[i]) v.push_back(i);
			}
			for(int i=1;i<n;i++){
				if(vc[a[i].u]&&vc[a[i].v]){
					int X=fd(a[i].u);
					int Y=fd(a[i].v);
					if(X!=Y) fa[X]=Y;
				}
			}
			set <int> st;
			for(auto it:v){
				st.insert(fd(it));
			}
			if(st.size()>2) continue;
			int mx=0;
			for(int i=1;i<=n;i++){
				int mn=0x7ffffff;
				if(!vc[i]){
					for(auto j:v){
						mn=min(mn,dep[i]+dep[j]-2*dep[lca(i,j)]);
					}
					mx=max(mx,mn);
				}
			}
			ans=min(ans,mx);
		}while(next_permutation(vc.begin(),vc.end()));
		printf("%d\n",ans);
		for(int i=0;i<=n;i++){
			a[i]={0,0};
			g[i].clear();
			for(int j=0;j<=25;j++){
				f[i][j]=0;
			}
			dep[i]=0;
		}
	}
	return 0;
}

