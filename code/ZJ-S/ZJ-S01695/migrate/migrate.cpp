#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2000010;
vector<int>g[N];
int a[N],vis[N];
int cnt[N],fa[N],s[N][2],ans,n,d;
void dfs(int u){
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		for(auto w:g[v]){
			cnt[w]=i;
		}		
	}
	if(cnt[u]==0)s[u][0]=1;
	if(cnt[u]==1)s[u][1]=1;
	for(auto v:g[u]){
		dfs(v);
		if(cnt[u]==0){
			s[u][0]+=s[v][0];
			s[u][1]+=s[v][1];
		}else if(cnt[u]==1){
			s[u][1]+=s[v][0];
		}
	}
	if(fa[fa[u]]){
		int x=fa[u];
		int y=fa[x];
		int w0=0,w1=0;
		if(x==u+1){
			w0=y-x;
		}else if(x==u+2){
			int p=fa[x-1];
			w0=y-p;
			w1=p-x;
		}else{
			int p1=fa[x-1];
			int p2=fa[x-2];
			w0=y-p1;
			w1=p1-p2;
		}
		ans+=w1;
	}
	if(fa[fa[fa[u]]]){
		int f=fa[u];
		int x=fa[f];
		int y=fa[x];
		int lim=0;
		if(f!=u+1&&x!=f+1){
			if(fa[f-1]==x)lim=fa[x-1];
			else lim=fa[fa[f-1]];
		}
		if(lim==y)s[u][0]=s[u][1]=0;
	}
}
void dfs2(int u){
	for(auto v:g[u]){
		dfs2(v);
	}
	if(fa[fa[fa[u]]]){
		int f=fa[u];
		int x=fa[f];
		int y=fa[x];
		int lim=0;
		if(f!=u+1&&x!=f+1){
			if(fa[f-1]==x)lim=fa[x-1];
			else lim=fa[fa[f-1]];
		}
		int w0=0,w1=0;
		if(x==f+1){
			x=max(x,lim);
			w0=y-x;
		}else if(x==f+2){
			int p=fa[x-1];
			x=max(x,lim);
			p=max(p,lim);
			w0=y-p;
			w1=p-x;
		}else{
			int p1=fa[x-1];
			int p2=fa[x-2];
			p1=max(p1,lim);
			p2=max(p2,lim);
			w0=y-p1;
			w1=p1-p2;
		}
		int q0=0,q1=0;
		q0=s[u][0],q1=s[u][1];
		ans+=w0*q1+w1*q0;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	int cid=0;
	while(T--){
		cid++;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int j=1;
		for(int i=1;i<=n;i++){
			while(j+1<=n&&a[j+1]-a[i]<=d)j++;
			if(j==i){
				vis[i]=1;
			}else{
				fa[i]=j;
				g[j].push_back(i);
			}
		}
		for(int i=1;i<=n;i++){
			if(vis[i]){
				dfs(i);
				dfs2(i);
			}
		}
		cout<<ans<<'\n';
		ans=0;
		for(int i=1;i<=n;i++){
			g[i].clear();
			vis[i]=fa[i]=s[i][0]=s[i][1]=cnt[i]=0;
		}
	}
	return 0;
}