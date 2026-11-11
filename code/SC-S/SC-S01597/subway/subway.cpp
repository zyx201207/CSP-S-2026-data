#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N=5e5+10,M=5e2+10;
struct sc{
	int u,t;
};
struct node{
	int road,t;
};
int a[M];
bool vis[M];
vector<sc>g1[N+M];
vector<node>g2[N+M];
int mn=INT_MAX;
void dfs(int x,int y,int sum){
	if(x==y)mn=min(mn,sum);
	for(auto it1:g2[x]){
		for(auto it2:g1[it1.road]){
			if(!vis[it2.u]){
				vis[it2.u]=1;
				dfs(it2.u,y,sum+it2.t+it1.t);
				vis[it2.u]=0;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int u,t;
			cin>>u>>t;
			g1[i].push_back({u,t});
			g2[u].push_back({i,t});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		vis[x]=1;
		dfs(x,y,0);
		vis[x]=0;
		cout<<mn+a[x]+a[y]<<"\n";
		mn=INT_MAX;
	}
	return 0;
} 