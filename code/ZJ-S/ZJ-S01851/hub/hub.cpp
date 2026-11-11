#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int c,t,n,k;
vector<int> a[N];
int ans[15];
bool usd[15];
int fa[15];
int f[15][10];
int dep[15];
int tans=1e18;
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	int c=dep[x]-dep[y];
	for(int i=4;i>=0;--i){
		if(c>>i&1) x=f[x][i];
	}
	if(x==y) return x;
	for(int i=4;i>=0;--i){
		if(f[x][i]!=f[y][i]){
			x=f[x][i],y=f[y][i];
		}
	}
	return f[x][0];
}
void df(int u,int v){
	dep[u]=dep[v]+1;
	f[u][0]=v;
	for(int i=1;i<=4;++i){
		f[u][i]=f[f[u][i-1]][i-1];
	}
	for(auto it:a[u]){
		if(it==f[u][0]) continue;
		df(it,u);
	}
}
void dfs(int d){
	if(d>k){
		int cnt=0;
		for(int i=1;i<d;++i) fa[ans[i]]=ans[i];
		for(int i=1;i<d;++i){
			for(auto it:a[ans[i]]){
				fa[it]=fa[ans[i]];
			}
		}
		for(int i=1;i<d;++i){
			if(fa[ans[i]]==ans[i]){
				cnt++;
			}
		}
		if(cnt>2) return ;
		for(int i=1;i<d;++i){
			cout<<ans[i]<<' ';
		}
		cout<<'\n';
		int maxn=-1;
		for(int i=1;i<=n;++i){
			int minn=1e18;
			for(int j=1;j<d;++j){
				int len=lca(i,ans[j]);
				minn=min(minn,dep[i]+dep[ans[j]]-(2*dep[len]));
			}
			maxn=max(maxn,minn);
		}
		tans=min(tans,maxn);
	}else{
		for(int i=d;i<=n;++i){
			if(usd[i]) continue;
			usd[i]=1;
			ans[d]=i;
			dfs(d+1);
			ans[d]=0;
			usd[i]=0;
		}
	}
}
void solve(){
	tans=1e18;
	cin>>n>>k;
	int x,y;
	for(int i=1;i<n;++i){
		cin>>x>>y;
		if(x>y) swap(x,y);
		a[x].push_back(y);
	}
	df(1,0);
	dfs(1);
	cout<<tans<<'\n';
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
		for(int i=1;i<=n;++i){
			a[i].clear();
		}
		memset(usd,0,sizeof(usd));
	}
	return 0;
}
