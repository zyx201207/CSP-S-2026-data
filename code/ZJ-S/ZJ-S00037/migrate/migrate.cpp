#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int>edge[5010];
ll a[5010];
int dis[5010][3];
priority_queue<pair<int,int>>q;
void dijkstra(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s][0]=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int u=q.top().second;
		int d=-q.top().first;
		q.pop();
		for(int i=0;i<edge[u].size();i++){
			int v=edge[u][i];
			if(d+1<=dis[v][0]){
				dis[v][2]=dis[v][1];
				dis[v][1]=dis[v][0];
				dis[v][0]=d+1;
				q.push(make_pair(-dis[v][0],v));
			}else if(d+1<=dis[v][1]){
				dis[v][2]=dis[v][1];
				dis[v][1]=d+1;
				q.push(make_pair(-dis[v][1],v));
			}else if(d+1<=dis[v][2]){
				dis[v][2]=d+1;
				q.push(make_pair(-dis[v][2],v));
			}
		}
	}
}
int main(){
	// freopen("E:\\down\\migrate\\migrate3.in","r",stdin);
	// freopen("E:\\down\\migrate\\migrate3.out","w",stdout);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			edge[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					edge[i].push_back(j);
					edge[j].push_back(i);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			dijkstra(i);
			for(int j=i+1;j<=n;j++){
				if(dis[j][0]==dis[j][1]&&dis[j][1]<dis[j][2]){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}