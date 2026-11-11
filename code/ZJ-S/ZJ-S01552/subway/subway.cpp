#include<bits/stdc++.h>
#define int long long
#define pi pair<int,int>
using namespace std;
int dis[500005],vis[500005],ans[505][505];
int c,n,m,d,Q,w[500005],k[500005],v[500005],t[500005];
int cnt,x,y,i,j;
vector<int> V[500005];
vector<int> bel[500005],cost[500005];
struct xx{
	int v,l;
};
vector<xx> a[500005];
priority_queue<pi,vector<pi>,greater<pi> >q;
void dij(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	q.push({0,s});dis[s]=0;
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto i:a[u]){
			int v=i.v,l=i.l;
			if(dis[u]+l<dis[v]){
				dis[v]=dis[u]+l;
				q.push({dis[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>v[j]>>t[j];
			bel[v[j]].push_back(i);
			cost[v[j]].push_back(t[j]);
		}
		cnt+=k[i];
	}
	for(int i=1;i<=m;i++){
		for(int jj=0;jj<bel[i].size();jj++){
			int j=bel[i][jj];
			for(int pp=0;pp<bel[i].size();pp++){
				int p=bel[i][pp];
				if(j==p)continue;
				a[j].push_back({p,cost[i][jj]+cost[i][pp]});
			}
		}
	}
	/*cout<<cnt<<"\n";
	for(int i=1;i<=cnt;i++){
		cout<<cost[i]<<" ";
	}
	cout<<"\n";
	cout<<"-------------\n";
	for(int i=1;i<=cnt;i++){
		cout<<i<<":\n";
		for(auto j:a[i]){
			cout<<j.v<<" "<<j.l<<"\n";
		}
		cout<<"\n";
	}*/
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			ans[i][j]=LLONG_MAX;
		}
	}
	/*for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			for(auto x:V[i]){
				dij(x);
				for(auto y:V[j]){
					ans[i][j]=min(ans[i][j],dis[y]+cost[x]+cost[y]);
				}
			}
			ans[j][i]=ans[i][j];
		}
	}*/
	while(Q--){
		cin>>i>>j;
		if(ans[i][j]!=LLONG_MAX){
			cout<<ans[i][j]<<"\n";
		}
		else{
			for(int xx=0;xx<bel[i].size();xx++){
				int x=bel[i][xx];
				dij(x);
				for(auto yy=0;yy<bel[j].size();yy++){
					int y=bel[j][yy];
					ans[i][j]=min(ans[i][j],dis[y]+cost[i][xx]+cost[j][yy]+w[i]+w[j]);
				}
			}
			ans[j][i]=ans[i][j];
			cout<<ans[i][j]<<"\n";
		}
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/