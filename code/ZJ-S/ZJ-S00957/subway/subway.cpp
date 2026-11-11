#include <bits/stdc++.h>
using namespace std;
int a[510][30],b[510][30],w[500010],dp[500010],di[500010];
vector<pair<int,int> >s[500010];
int bfs(int x,int g){
	queue<int>q;
	q.push(x);
	dp[x]=1;
	while(!q.empty()){
		int y=q.front();
		q.pop();
		if(y==g){
			return di[y];
		}
		for(int i=0;i<s[y].size();i++){
			if(dp[s[y][i].first]==0){
				di[s[y][i].first]=di[y]+s[y][i].second;
				dp[s[y][i].first]=1;
				q.push(s[y][i].first);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,p,q;
	cin>>c>>n>>m>>p>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>b[i][j];
			for(int l=1;l<j;l++){
				s[a[i][j]].push_back({a[i][l],b[i][j]+b[i][l]});
				s[a[i][l]].push_back({a[i][j],b[i][j]+b[i][l]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		int ans=w[u]+w[v];
		ans+=bfs(u,v);
		cout<<ans<<endl;
	}
	return 0;
}