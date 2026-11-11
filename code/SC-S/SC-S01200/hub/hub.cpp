#include<bits/stdc++.h>
using namespace std;
#define int long long
int C,T,n,k,dis[1000006];
vector<int> G[1000006];
queue<int> q;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			G[u].push_back(v);G[v].push_back(u);
		}
		int ans=1e18+7;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				int sum=0;
				for(int t=1;t<=n;t++) dis[t]=1e18+7;
				q.push(i);q.push(j);dis[i]=dis[j]=0;
				while(!q.empty()){
					int u=q.front();q.pop();
					for(auto v:G[u]){
						if(dis[v]>dis[u]+1){
							dis[v]=dis[u]+1;
							q.push(v);
						}
					}
				}
				for(int t=1;t<=n;t++) sum=max(sum,dis[t]);ans=min(ans,sum);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/