#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
#define ll long long
#define pa pair
#define u first
#define v second
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,x,y;cin>>c>>n>>m>>d>>q;
	vector<ll>w(m);
	vector<vector<pa<int,ll> > >A(m); 
	for(int i=0;i<m;i++)cin>>w[i];
	for(int i=0;i<n;i++){
		int k;cin>>k;
		vector<int>a(k),t(k);
		for(int j=0;j<k;j++)cin>>a[j]>>t[j];
		for(int j=0;j<k;j++){
			for(int e=j+1;e<k;e++){
				A[a[j]-1].push_back({a[e]-1,t[j]+t[e]}),
				A[a[e]-1].push_back({a[j]-1,t[j]+t[e]});
			} 
		}
	}
	while(q--){
		vector<ll>vis(m,1e18);
		cin>>x>>y;
		queue<int>p;p.push(x-1);vis[x-1]=0;
		while(p.size()){
			int u=p.front();p.pop();
			for(int i=0;i<A[u].size();i++){
				if(vis[u]+A[u][i].v<vis[A[u][i].u]){
					p.push(A[u][i].u);
					vis[A[u][i].u]=vis[u]+A[u][i].v;
				}
			}
		}
		cout<<vis[y-1]+w[x-1]+w[y-1]<<"\n";
	}
	return 0;
}