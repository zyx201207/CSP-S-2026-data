#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int b[N],a[N],t[N],vis[N],dis[N];
struct node{
	int v,w;
	bool operator < (const node&others)const{
		return w>others.w;
	}
};
vector<node> vec[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int z,x;
		cin>>z>>x;
		vec[i*m+z].push_back({z,x});
		vec[z].push_back({i*m+z,x});
		for(int j=2;j<=k;j++){
			int zz,xx;
			cin>>zz>>xx;
			vec[i*m+zz].push_back({i*m+z,0});
			vec[i*m+z].push_back({i*m+zz,0});
			
			vec[i*m+zz].push_back({zz,xx});
			vec[zz].push_back({i*m+zz,xx});
			z=zz,x=xx;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=(m+1)*(n+1);i++){
			vis[i]=0;
			dis[i]=1e18;
		}
		priority_queue<node> pq;
		pq.push({x,0});
		dis[x]=0;
		while(pq.size()){
			node to=pq.top();
			pq.pop();
			if(vis[to.v]) continue;
			vis[to.v]=1;
			for(node z:vec[to.v]){
				if(dis[z.v]>dis[to.v]+z.w){
					dis[z.v]=dis[to.v]+z.w;
					pq.push({z.v,dis[z.v]});
				}
			}
		}
		cout<<b[x]+b[y]+dis[y]<<'\n';
	}
	return 0;
}
