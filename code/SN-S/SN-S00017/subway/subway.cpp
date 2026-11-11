#include<bits/stdc++.h> 
using namespace std;
int s[50005];
vector<pair<int,int> > ma[5000510];
vector<int>dist[500005]
const int inf=9000000000;
int vis[1000];
int distpf[500][500];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>s[i];
	}
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int u,t;
			cin>>u>>t;
			ma[u].push_back({i+m,t});
			ma[i+m].push_back({u,t});
			
		}
	}
	if(c<6){
		
		for(int i=0;i<q;++i){
			int x,y;
			cin>>x>>y;
			for(int j=0;j<ma[x].size();++j){
				find(ma[x][y]);
				
			}
		}
	}
	return 0;
}
 













