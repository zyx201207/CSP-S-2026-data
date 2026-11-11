#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=6e5+5;
const int M=505;
const ll inf=4e18;
struct edge{
	int v,w;
};
int c,n,m,d,q;
ll val[N],mp[M][M];
vector<edge> a[N];
ll solve(int x,int y){
	ll ret=inf;
	for(auto u:a[x])
		for(auto v:a[y])
			ret=min(ret,mp[u.v][v.v]+u.w+v.w);
	return ret;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>val[i];
	int u,v,w;
	for(int i=1;i<=n;i++){
		cin>>u;
		while(u--){
			cin>>v>>w;
			a[v].push_back({i,w});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			mp[i][j]=(i==j)?0:inf;
	for(int i=1;i<=m;i++){
		for(auto j:a[i]){
			for(auto k:a[i]){
				ll u=j.v,v=k.v,w=j.w+k.w;
				mp[u][v]=min(mp[u][v],w);
				mp[v][u]=min(mp[v][u],w);	
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
	for(int i=1;i<=q;i++){
		cin>>u>>v;
		cout<<val[u]+val[v]+solve(u,v)<<endl;
	}
	return 0;
}

