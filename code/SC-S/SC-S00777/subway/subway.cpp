#include<bits/stdc++.h>
using namespace std;
using PII=pair<int,int>;
const int N=5e3+10;
int w[N],t[N][N],a[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	vector<vector<PII>> node(n+1);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			if(j>=2){
				node[a[i][j+1]].push_back({a[i][j],t[i][j]});
			}
		}
	}
	int ans=0;
	for(int j=1;j<=q;j++){
		int x,y;
		cin>>x>>y;
		priority_queue<PII,vector<PII>,greater<PII>> qe;
		vector<int> dist(n+1,1e9),vis(n+1,0);
		qe.push({dist[1]=0,1});
		while(qe.size()){
			auto [d,var]=qe.top();
			qe.pop();
			if(vis[var]) continue;
			vis[var]=1;
			for(auto [x,w]:node[var]){
				if(dist[x]>w+dist[var]){
					qe.push({dist[x]=w+dist[var],x});
				}
			}
		}
		ans=dist[y]-dist[x]+w[x]+w[y];
		cout<<ans<<endl;
	}
}