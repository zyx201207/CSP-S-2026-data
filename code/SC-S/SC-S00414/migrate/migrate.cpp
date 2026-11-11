#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int x[(int)2e6+10];
vector<int>g[(int)2e6+10];
int cnt[(int)2e6+10];
int dist[(int)2e6+10];
int vis[(int)2e6+10];
int ans=0;
struct node{
	int to,w;
};
void dijstra(int x){
	for(int i=1;i<=n;i++)dist[i]=1e9,cnt[i]=0,vis[i]=0;
	queue<node>q;
	dist[x]=0;
	q.push({x,0});
	cnt[x]=1;
	while(q.size()){
		node f=q.front();q.pop();
		if(vis[f.to])continue;
		vis[f.to]=1;
		for(int i=0;i<g[f.to].size();i++){
			int to=g[f.to][i];
			if(dist[to]>dist[f.to]+1){
				dist[to]=dist[f.to]+1;
				cnt[to]=cnt[f.to];
				q.push({to,dist[to]});
			}
			else if(dist[to]==dist[f.to]+1)cnt[to]+=cnt[f.to];
		}
	}
	for(int i=1;i<=n;i++){
		if(cnt[i]==2)ans++;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	//cout<<c<<' '<<t<<'\n';
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			g[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(x[j]-x[i]<=d){
					g[i].push_back(j);
				}
			}
		}
		for(int i=1;i<=n;i++){
			dijstra(i);
		}
		cout<<ans<<'\n';
	}
	return 0; 
}