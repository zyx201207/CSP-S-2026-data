#include<bits/stdc++.h>
#define INF 1000000000000001
using namespace std;
int n,m,q;
long long w[500001],tran[501][501],dis[501][501];
vector<pair<int,long long> >lb[500001];
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >dj;
int main(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>q>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)tran[i][j]=INF,dis[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int k,i=1;i<=n;i++){
		cin>>k;
		for(int a,t,j=1;j<=k;j++)cin>>a>>t,lb[a].push_back({i,t});
	}
	for(int i=1;i<=m;i++){
		for(int j=lb[i].size()-1;j;j--){
			for(int k=j-1;k>=0;k--){
				tran[lb[i][k].first][lb[i][j].first]=min(tran[lb[i][k].first][lb[i][j].first],lb[i][j].second+lb[i][k].second);
				tran[lb[i][j].first][lb[i][k].first]=min(tran[lb[i][j].first][lb[i][k].first],lb[i][j].second+lb[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dj.push({0,i});
		while(!dj.empty()){
			int tmp=dj.top().second;
			dj.pop();
			for(int j=1;j<=n;j++){
				if(dis[i][j]>dis[i][tmp]+tran[tmp][j])dis[i][j]=dis[i][tmp]+tran[tmp][j],dj.push({dis[i][j],j});
			}
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		long long ans=INF;
		for(pair<int,long long>G:lb[s]){
			for(pair<int,long long>H:lb[t]){
				ans=min(ans,w[s]+w[t]+G.second+H.second+dis[G.first][H.first]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
