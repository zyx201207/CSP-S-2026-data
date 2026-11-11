#include<bits/stdc++.h>
#define endl '\n'
#define int int64_t
#define pairint pair<int,int>
#define F first
#define S second
using namespace std;
int c,n,m,d,q,w[500010],cnt[500010];
vector<pairint>v[5000010];
vector<int>dis;
vector<bool>vis;
int dij(int s,int t){
	priority_queue<pairint,vector<pairint>,greater<pairint>>pq;
	dis.clear();
	vis.clear();
	dis.resize((n+1)*d+1,1e18);
	vis.resize((n+1)*d+1,0);
	dis[s]=0;
	pq.push({0,s});
	while(!pq.empty()){
		auto tp=pq.top();pq.pop();
		int x=tp.S,dd=tp.F;
//		if(dd>dis[x]) continue;
		if(vis[x]) continue;
		vis[x]=1;
		for(auto p:v[x]){
			if(dis[p.F]>dd+p.S){
				dis[p.F]=dd+p.S;
				vis[p.F]=0;
				pq.push({dis[p.F],p.F});
			}
		}
	}
	return dis[t];
}
int32_t main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	while(m--){
		vector<int>vc;
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int x,z;
			cin>>x>>z;
			vc.push_back(x);
			cnt[x]++;
			v[x].push_back({n+(x-1)*d+cnt[x],z});
			v[n+(x-1)*d+cnt[x]].push_back({x,z});
		}
		for(int i=1;i<k;i++){
			int x=vc[i-1],y=vc[i];
			int nx=n+(x-1)*d+cnt[x],ny=n+(y-1)*d+cnt[y];
			v[nx].push_back({ny,0});
			v[ny].push_back({nx,0});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(x==y) cout<<"0\n";
		else cout<<dij(x,y)+w[x]+w[y]<<endl;
	}
	return 0;
}

