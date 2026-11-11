#include<bits/stdc++.h>
#define For(i,j,k) for(int i=j;i<=k;i++)
#define ll long long
#define pb push_back
using namespace std;
const int N = 5e5+5;
const int Q = 1e5+5;
int c,n,m,d,q;
bool vis[N];
int w[N],a[505][N],t[505][N];
int f[505][N];
int ans =INT_MAX;
void dfs(int u,int v,long long cost){
	if(cost>=ans) return;
	if(vis[u])return;
	if(u==v){
		ans=min(cost,ans);
		return;
	}
	cost+=w[u];
	For(i,1,n){
		if(t[i][u]==0)continue;
		vis[u]=true;
		for(int e:a[i]){
			if(e==u)continue;
			cost+=t[i][e];
			dfs(e,v,cost);
		}
		vis[u]=false;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	For(i,1,m){
		cin>>w[i];
	}
	For(i,1,n){
		int k;
		cin>>k;
		For(j,1,k){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			w[a[i][j]]+=t[i][j];
		}
	}
	For(i,1,q){
		int x,y;
		cin>>x>>y;
		dfs(x,y,0);
		cout<<ans<<endl;
		ans=LLONG_MAX;
	}
}
