#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > v[500005];
long long c,n,m,d,q,dis[500005],vis[500005],w[500005],cnt=0,sum=0,maxx=0,a[505][505],t[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		v[i].push_back({n+1,w[i]});
		v[n+1].push_back({i,w[i]});
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=2;j<=k;j++){
			v[a[i][j-1]].push_back({a[i][j],0});
			v[a[i][j]].push_back({n+1,t[i][j]});
			v[n+1].push_back({a[i][j],t[i][j]});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int p=1;
		queue<int> q;
		q.push(p);
		memset(dis,-1,sizeof dis);
		dis[p]=0;
		while(!q.empty()){
			int now=q.front();
			q.pop();
			int len=v[now].size();
			for(int j=0;j<len;j++){
				if(vis[v[now][j].first]==0){
					q.push(v[now][j].first);
					vis[v[now][j].first]==1;
				}
				if(dis[j]>dis[now]+v[now][j].second){
					dis[j]=dis[now]+v[now][j].second;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<dis[i]<<"\n";
	}
	return 0;
}
