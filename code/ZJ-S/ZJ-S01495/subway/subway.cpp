#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,Q,w[500005],vis[500005];
int ff=0,ans=0;
int dis[500005];
struct nodde{
	int v,ti;
};
struct cmp{
	bool operator()(nodde x,nodde y){
		return x.ti>y.ti;
	}
};
vector<nodde> e[500005];
priority_queue< nodde , vector<nodde> ,cmp > q;
int k,a[500005]={},t[500005]={};
void solve(){
	int x,y;
	cin>>x>>y;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<nodde,vector<nodde>,cmp > qq;
	swap(q,qq);
	q.push({x,0});
	dis[x]=0;
	while(!q.empty()){
		nodde now=q.top();
		q.pop();
		if(vis[now.v]) continue;
		vis[now.v]=1;
		for(auto to:e[now.v]){
			if(!vis[to.v]&&dis[to.v]>dis[now.v]+to.ti){
				dis[to.v]=dis[now.v]+to.ti;
				q.push({to.v,dis[to.v]});
			}
		}
	}
	cout<<dis[y]+w[x]+w[y]<<endl;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=2;j<=k;j++){
			for(int mid=1;mid<j;mid++){
				int sum=t[mid]+t[j];
				e[a[j]].push_back({a[mid],sum});
				e[a[mid]].push_back({a[j],sum});
			}
		}
	}
	while(Q--){
		solve();
	}
	return 0;
}
