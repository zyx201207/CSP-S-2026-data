#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],dis[500005],vis[500005];
struct _{
	int to,val;
};
vector<_>g[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		vector<int>st,time;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			for(int u=0;u<st.size();u++){
				g[a].push_back({st[u],time[u]+t});
				g[st[u]].push_back({a,time[u]+t});
			}
			st.push_back(a);
			time.push_back(t);
		}
	}
	while(q--){
		for(int j=1;j<=m;j++){
			dis[j]=1e18;
			vis[j]=0;
		}
		int x,y;
		cin>>x>>y;
		queue<int>q;
		q.push(x);
		dis[x]=0;
		vis[x]=1;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=0;i<g[u].size();i++){
				if(g[u][i].val+dis[u]<dis[g[u][i].to]){
					dis[g[u][i].to]=g[u][i].val+dis[u];
					if(!vis[g[u][i].to]){
						vis[g[u][i].to]=1;
						q.push(g[u][i].to);
					}
				}
			}
		}
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
/*
shit 优先队列忘记怎么拼了 只能用 SPFA 了。 
*/
