#include<bits/stdc++.h>
#define int long long
#define pi pair<int,int>
using namespace std;
const int mx=5e5+5;
const int inf=1e18;
int c,n,m,d,q,w[mx],dis[1005][505],a[1005][1005],t[1005][1005],k[10005];
//void dij(int st){
//	vector<int> vis(n+1,0);
//	vector<int> dis(n+1,inf);
//	dis[st]=;
//	priority_queue<pi,vector<pi>,greater<pi> > q;
//	q.push({0,st});
//	while(!q.empty()){
//		pi u=q.top(); q.pop();
//		if(vis[u.second]) continue;
//		vis[u.second]=1;
//		for(int v:e[u.second]){
//			
//			if(dis[v]>u.first+1){
//				dis[v]=u.first+1;
//				q.push({dis[v],v});
//			}
//		}
//	}
//	
//}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][1]>>t[i][1];
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		int wq=1e18;
		for(int w=1;w<=n;w++){
		for(int i=1;i<=k[w];i++){
			for(int j=1;j<=k[w];j++){
				if(a[w][i]==l&&a[w][j]==r) wq=min(wq,t[w][i]+t[w][j]);
			}
		}
		}
		cout<<w[l]+w[r]+wq<<'\n';
	}
	return 0;
}