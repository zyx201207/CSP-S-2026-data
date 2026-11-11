#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int M=5e5+10;
long long n,m,c,d,q,w[M],a[M],t2[N][M],f[M],ans=0,vis[M],cnt_huan=0; 
struct node{
	long long x,z;
};
struct chan{
	long long t[5];
} huan[M];
vector<node> e[M];
void dfs(int u,int fa,int en){
	if(u==en) return ;
	if(u==fa) return ;
	for(auto v:e[u]){
		if(u==v.x) continue ;
		if(vis[f[u]]!=vis[v.x]){
			ans+=huan[u].t[f[u]]+huan[u].t[v.x];
		}
		dfs(v.x,u,en);
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t2[i][j];
			if(vis[a[j]]==0) vis[a[j]]=i;
			else{
				cnt_huan++;
				huan[cnt_huan].t[i]=t2[i][j];
			}
			e[a[j-1]].push_back({a[j],t2[i][j]});
			f[a[j]]=a[j-1];
		}
	}
	long long u,v;
	for(int i=1;i<=q;i++){
		cin>>u>>v;
		ans=0;
		dfs(u,f[u],v);
		cout<<ans+w[u]+w[v]+t2[vis[v]][v]+t2[vis[u]][v];
	}
	return 0;
}