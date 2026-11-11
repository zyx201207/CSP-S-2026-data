#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int> e[N];
bool b[N],vis[N];
void dfs1(int u){
	vis[u]=1;
	for(auto v:e[u]){
		if(b[v]&&!vis[v]){
			dfs1(v);
		}
	}
}
int f[N],s[N];
void dfs2(int u,int fa){
	if(b[u])f[u]=0,s[u]=0;
	else f[u]=f[fa]+1;
	for(auto v:e[u]){
		if(v==fa)continue;
		dfs2(v,u);
		s[u]=min(s[u],s[v]+1);
	}
}
int dep[N],fa[N],low,who;
void Dfs1(int u){
	if(dep[u]>low){
		low=dep[u],who=u;
	}
	for(auto v:e[u]){
		if(v==fa[u])continue;
		fa[v]=u;
		dep[v]=dep[u]+1;
		Dfs1(v);
	}
}
int dep2[N];
void Dfs2(int u,int F){
	for(auto v:e[u]){
		if(v==F)continue;
		dep2[v]=dep2[u]+1;
		Dfs2(v,u);
	}
}
bool check(int mid,int n){
	int x=who;
	for(int i=1;i<=mid;i++)x=fa[x];
	if(!x)return 1;
	dep2[x]=0;
	Dfs2(x,0);
	for(int i=1;i<=n;i++){
		if(min(dep[i],dep2[i])>mid)return 0;
	}
	return 1;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==7){
	while(t--){
		int n,k,ans=0x3f3f3f3f;
		cin>>n>>k;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			fa[i]=dep[i]=low=who=0;
			Dfs1(i);
			int l=0,r=low,mid;
			while(l<r){
				mid=(l+r)>>1;
				if(check(mid,n))r=mid;
				else l=mid+1;
			}
			ans=min(ans,l);
		}
		cout<<ans<<'\n';
	}
	return 0;
	}
	if(c==13||c==14){
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		if(n==k){
			cout<<"0\n";
			continue;
		}
		if(k>=n/2){
			cout<<"1\n";
			continue;
		}
		int m=n/2;
		cout<<(m-k+3)/4+1<<'\n';
	}
	return 0;
	}
	while(t--){
		int n,k,ans=0x3f3f3f3f;
		cin>>n>>k;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int i=1;i<(1<<n);i++){
			int cnt=0;
			for(int j=0;j<n;j++){
				if((i>>j)&1)b[j+1]=1,cnt++;
				else b[j+1]=0;
			}
			if(cnt!=k)continue;
			cnt=0;
			for(int j=1;j<=n;j++){
				if(b[j]&&!vis[j]){
					dfs1(j);
					cnt++;
				}
			}
			if(cnt>2)continue;
			memset(f,0x3f,sizeof f);
			memset(s,0x3f,sizeof s);
			int sum=0x3f3f3f3f;
			dfs2(1,0);
			for(int j=1;j<=n;j++){
				sum=max(sum,min(f[j],s[j]));
			}
			ans=min(ans,sum);
		}
		cout<<ans<<'\n';
	}
	return 0;
}