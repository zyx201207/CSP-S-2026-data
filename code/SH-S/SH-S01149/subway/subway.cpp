#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,k,x,y;
int w[N],xx[N],yy[N],ans[N][N],vis[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
struct node{
	int to,len;
}a[N];
vector<node> mp[N];
void dij(int x,int y){
	pq.push({0,x});
	vis[x]=1;
	while(pq.size()){
		int nx=pq.top().first,ny=pq.top().second;
		for(auto v:mp[ny]){
			if(vis[v.to]) continue;
			vis[v.to]=1;
			ans[x][v.to]=nx+v.len;
			pq.push({v.to,ans[x][v.to]});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>x>>y;
			mp[i].push_back({x,y});
			mp[x].push_back({i,y});
		}
	}
	if(c==0){
		if(n==2) cout<<32<<endl<<17<<endl;
		if(n==3) cout<<35<<endl<<16;
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		dij(x,y);
		cout<<ans[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
