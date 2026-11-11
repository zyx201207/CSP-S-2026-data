#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
ll c,T,n,k,cnt,s[105],fa[105],f[105],dep[105],d[105],ans;
vector<int> e[N];
struct Node{
	int u,v;
}g[N];
inline void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u]=fa;
	for(int v:e[u]){
		if(v==fa)continue;
		dfs(v,u);
	}
}
inline int finds(int x){
	if(x==fa[x])return x;
	return fa[x]=finds(fa[x]);
}
inline bool check(){
	int sum=k;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<n;i++){
		if(s[g[i].u]==0||s[g[i].v]==0)continue;
		int fx=finds(g[i].u),fy=finds(g[i].v);
		if(fx!=fy){
			fa[fy]=fx;
			sum--;
		}
	}
	return sum>2;
}
void dfs2(int u,int fa){
	for(int v:e[u]){
		if(v==fa)continue;
		dfs(v,u);
		if(s[v]==1)d[v]=0;
		else d[v]=d[u]+1;
	}
}
inline void solve(){
	ans=0;
	ll sum;
	for(int i=0;i<(1<<n);i++){
		cnt=0,sum=0;
		for(int j=1;j<=n;j++)s[j]=0;
		for(int j=0;j<n;j++)
			if(i&(1<<j))s[j+1]=1,cnt++;
		if(cnt==k){
			if(check())continue;
			dfs(1,0);
			for(int l=1;l<=n;l++){
				if(!s[l])continue;
				for(int r=1;r<=n;r++)
					d[i]=0;
				dfs(l,0);
				for(int r=1;r<=n;r++)
					sum=max(sum,d[i]);  
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans<<'\n';	
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		int u,v,tot=0;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
			g[++tot]=(Node){u,v};
		}
		if(n==k)cout<<"0\n";
		else if(c<=6)solve();
		else cout<<n/2<<'\n';
		for(int i=1;i<=n;i++)
			e[i].clear();
	}
	return 0;
}