#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int>
int w[500005];
int k[505];
vector<int>b[500005];
vector<pi>g[505];
map<pi,int>t;
int x[100005];
int y[100005];
int c,n,m,d,p;
int dis[505][505];
int vis[505];
map<pi,int>mp;
int dijk(int s){
	for(int i=1;i<=n+1;i++){
		dis[s][i]=1e12;
		vis[i]=0;
	}
	priority_queue<pi,vector<pi>,greater<pi>>q;
	dis[s][s]=0;
	q.push({s,dis[s][s]});
	while(!q.empty()){
		int u=q.top().first;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(auto cc:g[u]){
			int v=cc.first;
			int w=cc.second;
			if(dis[s][u]+w<=dis[s][v]){
				dis[s][v]=dis[s][u]+w;
				q.push({v,dis[s][v]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int aa,tt;
			cin>>aa;
			cin>>tt;
			t[{i,aa}]=tt;
			b[aa].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		for(auto cu:b[i]){
			for(auto cv:b[i]){
				if(cu==cv)continue;
				int ww=t[{cu,i}]+t[{cv,i}];
				if(mp[{cu,cv}]<ww){
					g[cu].push_back({cv,ww});
				}
				mp[{cu,cv}]=ww;
			}
		}
	}
	for(int i=1;i<=n;i++){
		dijk(i);
	}
	for(int i=1;i<=p;i++){
		cin>>x[i]>>y[i];
		int ans=1e12;
		for(auto l:b[x[i]]){
			for(auto r:b[y[i]]){
				ans=min(dis[l][r]+w[x[i]]+w[y[i]]+t[{l,x[i]}]+t[{r,y[i]}],ans);
			}
		}
		cout<<ans<<endl;
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


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/