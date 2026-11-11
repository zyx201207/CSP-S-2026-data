#include <bits/stdc++.h>
using namespace std;
//priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> dis;
int dis[500005];
vector<vector<pair<int,int>>> e;
bool vis[500005];
void leitingchushihua(){
	for(int i=1;i<=500005;i++){
		dis[i]=20000000;
		vis[i]=0;
	}
}
void djsta(int s,int end){
	if(s==end) return;
	for(auto i:e[s]){
		if(i.second<dis[i.first]){
			dis[i.first]=i.second;
			vis[i.first]=1;	
			djsta(i.first,end);	
		} 
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,chuzhan[500005];
	cin>>c>>n>>m>>d>>q;
	if(c>=7 && c<=11){
		for(int i=1;i<=m;i++){
			cin>>chuzhan[i];
		}
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			int u,v,t1,t2;
			cin>>u>>t1>>v>>t2;
			pair<int,int> tmp1={u,t1};
			pair<int,int> tmp2={v,t2};
			e[u].push_back(tmp2);
			e[v].push_back(tmp1);
		}
	for(int i=1;i<=q;i++){
		int ru,cu;
		leitingchushihua();
		cin>>ru>>cu;
		djsta(ru,cu);
		cout<<dis[cu]+chuzhan[ru]+chuzhan[cu]<<'\n';
	}
	}
	else{
		for(int i=1;i<=m;i++){
			cin>>chuzhan[i];
		}
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			int un[500005],ut[500005];
			for(int j=1;j<=k;j++){
				cin>>un[j]>>ut[j];
			}
			for(int j=1;j<=k;j++){
				for(int jjj=j+1;jjj<=k;jjj++){
					e[un[j]].push_back({un[jjj],ut[jjj]});
					e[un[jjj]].push_back({un[j],ut[j]});
				}
			}
		}
		for(int i=1;i<=q;i++){
			int ru,cu;
			leitingchushihua();
			cin>>ru>>cu;
			djsta(ru,cu);
			cout<<dis[cu]+chuzhan[ru]+chuzhan[cu]<<'\n';
		}
	}
	return 0;
}