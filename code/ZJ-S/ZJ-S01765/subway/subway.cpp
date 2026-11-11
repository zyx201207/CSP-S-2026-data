#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long w[maxn];
int k[maxn];
int a[510][maxn];
long long t[510][maxn];
int c,n,m,d,q;
long long mp[510][maxn];
vector<int>G[maxn];
long long dits[maxn];
const int mn=1e8;
int vis[maxn];
void di(int s,int n){
	for(int i=1;i<=n;i++){
		dits[i]=mn;
		vis[i]=false;
	}
	dits[s]=0;
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>dq;
	dq.push({0,s});
	while(!dq.empty()){
		int u=dq.top().second;
		dq.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(auto [v,w]:G[u]){
			if(dits[v]>dits[u]+w){
				dits[v]=dits[u]+w;
				dq.push({dits[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			G[a[i][j]].push_back({a[i][j],t[i][j]});
		}
	}
	for(int i=1;i<=n;i++){
		memset(dits,0,sizeof(dits));
		di(i,n);
		for(int j=1;j<=m;j++){
			fa[i][j]=dits[i];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		long long ans=fa[x][y]+w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}