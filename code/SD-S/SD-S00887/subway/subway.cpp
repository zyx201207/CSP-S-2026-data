#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,qq,w[1000006],k[1000006],a[1005][1005],t[1004][1004],dis[1004][1004],x[1000006],y[1000006];
vector<array<long long,2>> node[100005];
priority_queue<array<long long,2>,vector<array<long long,2>>,greater<array<long long,2>>> q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			for(int l=1;l<j;l++){
				node[a[i][l]].push_back({t[i][j]+t[i][l],a[i][j]});
				node[a[i][j]].push_back({t[i][j]+t[i][l],a[i][l]});
			}
		}
	}
	for(int i=1;i<=m;i++){
		fill(dis[i]+1,dis[i]+m+1,1e17);
		q.push({0,i});
		while(!q.empty()){
			auto u=q.top();
			q.pop();
			if(u[0]>=dis[i][u[1]]) continue;
			dis[i][u[1]]=u[0];
			for(auto v:node[u[1]]){
				if(dis[i][v[1]]>dis[i][u[1]]+v[0]) q.push({dis[i][u[1]]+v[0],v[1]});
			}
		}
	}
	for(int i=1;i<=qq;i++){
		cin>>x[i]>>y[i];
		cout<<w[x[i]]+w[y[i]]+dis[x[i]][y[i]]<<'\n';
	}
	return 0;
}
