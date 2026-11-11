#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500005],k[505],y,ans;
//int t[505][500005];
vector<int>a[505],t[505];
bool vis[500005];
vector<int>G[505];
void dfs(int u,int timer){
	if(u==y){
		ans=min(ans,timer);
		return;
	}for(int i=0;i<G[u].size();i++){
		int lin=G[u][i];
		int id;
		for(int j=0;j<k[lin];j++){
			if(a[lin][j]==u){
				id=j;
				break;
			}
		}
		for(int j=0;j<k[lin];j++){
			int v=a[lin][j];
			if(vis[v])continue;
			vis[v]=1;
			dfs(v,timer+t[lin][j]+t[lin][id]);
			vis[v]=0;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			int y,tt;
			scanf("%lld %lld",&y,&tt);
			a[i].push_back(y);
			t[i].push_back(tt);
			G[a[i][j-1]].push_back(i);
			//cout<<'1';
		}
	}while(q--){
		int x;
		ans=1e18;
		scanf("%lld %lld",&x,&y);
		vis[x]=1;
		dfs(x,w[x]+w[y]);
		vis[x]=0;
		cout<<ans<<'\n';
	}
	return 0;
} 
