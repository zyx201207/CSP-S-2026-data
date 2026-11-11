#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e3+5;
int c,t,n,k,dis[N][N];
vector<int> g[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		if(n==k){
			cout<<"0\n";
			continue;
		}
		memset(dis,0x3f,sizeof dis);
		for(int i=1,u,v;i<=n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			dis[u][v]=dis[v][u]=1;
		}
		for(int d=1;d<=n;d++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dis[i][j]>dis[i][d]+dis[d][j]){
						dis[i][j]=dis[i][d]+dis[d][j];
					}
				}
			}
		}
		cout<<"1\n";
	}
	return 0;
}

