#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+10;
int c,n,m,d,q;
struct ovo{
	int w;
}z[N];
int dt[510][N];
vector<pair<int,int>> g[N*2];
signed main(){
	freopen("subway2.in","r",stdin);
	//freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>z[i].w;
		for(int j=1;j<=n;j++){
			g[i].push_back({m+j,z[i].w});
			g[m+j].push_back({i,z[i].w});
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int dk[N],tk[N];
		for(int j=1;j<=k;j++){
		//	int dking,tking;
			cin>>dk[j]>>tk[j];
		}
		for(int j=1;j<=k;j++){
			for(int w=i+1;w<=k;w++){
				g[dk[j]].push_back({dk[w],tk[j]});
				g[dk[w]].push_back({dk[j],tk[w]});
			}
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		int dist[N*2+1];
		memset(dist,0x3f,sizeof(dist));
		dist[s]=0;
		dist[s+n]=z[s].w;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
		pq.emplace(0,s);
		pq.emplace(z[s].w,s+n);
		while(!pq.empty()){
			auto [i,j]=pq.top();
			pq.pop();
			if(i>dist[j]){
				continue;
			}
			for(auto [p,joker]:g[j]){
				if(p!=t){
					if(dist[p]>joker+i+z[p].w){
						dist[p]=joker+i+z[p].w;
						pq.emplace(joker+i,p+z[p].w);
					}
				}else if(dist[p]>joker+i){
					dist[p]=joker+i;
					pq.emplace(joker+i,p);
				}
			}
		}
		//for(int i=1;i<=2*m;i++) cout<<dist[i]<<"\n";
		cout<<dist[t]<<"\n";
	}
	return 0;
}//j:[80,100]+100+[50,80]+[4,28]=[234,308]
//AFO
//CSP-2026=NOIP-2025
