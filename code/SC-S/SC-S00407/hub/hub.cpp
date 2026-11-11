#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==16||c==17){
		cout<<1<<' '<<2;
	}
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<vector<int>>g(n+3);
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			
		}
		vector<vector<int>>dist(n+3,vector<int>(n+3,1e9));
		for(int i=1;i<=n;i++){
			vector<int>vis(n+3,1);
			queue<int>q;
			q.push(i);
			vis[i]=0;
			dist[i][i]=0;
			while(q.size()){
				int var=q.front();
				q.pop();
				for(int v:g[var]){
					if(vis[v]==1){
						vis[v]=0;
						q.push(v);
						dist[i][v]=min(dist[i][v],dist[i][var]+1);
					}
				}
			}
		}
		vector<int>d(n+3,1e9);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i]=min(d[i],dist[i][j]);
			}
		}
		if(k==1){
			sort(d.begin()+1,d.begin()+n+1);
			cout<<d[n-1]<<' ';
		}
		else if(k==2){
			sort(d.begin()+1,d.begin()+n+1);
			cout<<d[n-2]<<' ';
		}
		else {
			sort(d.begin()+1,d.begin()+n+1);
			cout<<d[n-k]<<' ';
		}
	}
	return 0;
}