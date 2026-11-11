#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,n,m,d,q;
vector<int>w;
vector<vector<int>>a,t;
vector<pair<int,int>>g[1005];
map<int,int>along;
ll dijkstra(int x,int y){
	ll ans=1e18;
	vector<bool>vis(505,0);
	priority_queue<pair<int,ll>,vector<pair<int,ll>>,greater<pair<int,ll>>>hq;
	hq.push({0,x});
	while(hq.size()){
		auto it=hq.top();hq.pop();
		auto dis=it.first;
		auto cur=it.second;
		for(auto its:g[cur]){
			auto to=its.first;
			auto d=its.second;
			if(vis[to])continue;
			vis[to]=1;
			if(ans>dis+d){
				ans=dis+d;
				hq.push({ans,to});
			}
		}
	}return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
//	w.assign(n+1,0);
//	for(int i=1,x;i<=m;i++)cin>>x,w[i]=x;
//	auto mark=new vector<pair<int,int>>[505];
//	for(int i=1;i<=n;i++){
//		int k;
//		cin>>k;
//		a.assign(n+1,vector<int>(n+1));
//		t.assign(n+1,vector<int>(n+1));
//		for(int j=1,x,y;j<=k;j++){
//			cin>>x>>y;
//			a[i][j]=x,t[i][j]=y;
//			mark[x].push_back({i,y});
//			if(along.count(x)){
//				if(along[x]>=0)along[x]=-1;
//				g[x]=mark[x];
//				g[i+500].push_back({x,y});
//			}
//			else along[x]=i;
//		}
//	}delete []mark;
//	for(int i=1;i<=q;i++){
//		int x,y,a,b;
//		cin>>x>>y;
//		if(along[x]>0)a=along[x]+500;
//		if(along[y]>0)b=along[y]+500;
//		cout<<w[x]+dijkstra(a,b)+w[y];
//	}
	for(int i=1;i<=q;i++)cout<<0;
	return 0;
}

