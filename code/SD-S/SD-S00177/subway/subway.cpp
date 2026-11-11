#include<bits/stdc++.h>
using namespace std;
const int N=500+10;
const int M=5e5+10;
int w[M],c[M][N];
int e,n,m,d,q;
struct side{
	int u,k;
};
vector<side>  t[M];
long long ans;
bool vis[M];
void dfs(int root,int k,long long sum,int x){
	//cout<<root<<":"<<sum<<"\n";
	if(root==x){
		ans=min(ans,sum+c[root][k]);
		return ;
	}
	if(sum>=ans) return ;
	vis[root]=1;
	int l=t[root].size();
	for(int i=0;i<l;i++){
		int v=t[root][i].u;
		int kt=t[root][i].k;
		if(vis[v]) continue;
		if(kt==k) dfs(v,kt,sum,x);
		else dfs(v,kt,sum+c[root][k]+c[root][kt],x);
	}
	vis[root]=0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>e>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int kt=0,u=0;
		cin>>kt>>u;cin>>c[u][i];
		for(int j=2;j<=kt;j++){
			int v;
			cin>>v;cin>>c[v][i];
			side tmp;
			tmp.u=v;
			tmp.k=i;
			t[u].push_back(tmp);
			tmp.u=u;
			t[v].push_back(tmp);
			u=v;
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		ans=1e18+10;
		memset(vis,0,sizeof(vis));
		dfs(u,0,0,v);
		ans=ans+w[u]+w[v];
		cout<<ans<<"\n";
	}
	return 0;
}
