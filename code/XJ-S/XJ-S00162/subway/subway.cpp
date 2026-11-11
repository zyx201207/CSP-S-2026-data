#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
const int inf=0x3f;
struct node{
	ll v,w;
};
ll c,n,m,d,q,w[505],k[N],a[505][1005],t[505][1005],dist[N];
vector<node> e[505];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		cin >>k[i];
		for(int j=1;j<=k[i];j++){
			cin >> a[i][j];
			cin >> t[a[i][j]][i];
		}
		for(int x=1;x<=k[i];x++){
			for(int y=x+1;y<=k[i];y++){
//				cout<<a[i][x]<<' '<<a[i][y]<<' '<<t[a[i][x]][i]+t[a[i][y]][i]<<endl;
				e[a[i][x]].push_back((node){a[i][y],t[a[i][x]][i]+t[a[i][y]][i]});
				e[a[i][y]].push_back((node){a[i][x],t[a[i][x]][i]+t[a[i][y]][i]});
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=0;j<e[i].size();j++){
//			cout<<i<<"->"<<e[i][j].v<<" ¼ÛÖµ"<<e[i][j].w<<endl;
//		}
//	}
	while(q--){
		int x,y;
		cin >> x >> y;
		priority_queue<ll> pq;
		pq.push(x);
		memset(dist,inf,sizeof dist);
		dist[x]=0;
		while(!pq.empty()){
			int u=pq.top();
			pq.pop();
			for(int i=0;i<e[u].size();i++){
				int vv=e[u][i].v,ww=e[u][i].w;
				if(dist[vv]>dist[u]+ww){
					pq.push(vv);
					dist[vv]=dist[u]+ww;
				}
			}
		}
		cout<<dist[y]+w[x]+w[y]<<endl;
	}
	return 0;
}
