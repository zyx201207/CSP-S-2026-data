#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,T,x,y,i,k,vis[1001000],dis[1001000],sx,sg,w[500010],z,j;
vector<int> f[1001000],g[1001000];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>T;
	for(i=1;i<=m;i++) cin>>w[i];
	for(i=1;i<=m;i++){
		f[i].push_back(i+m);
		f[i+m].push_back(i);
		g[i].push_back(w[i]);
		g[i+m].push_back(w[i]);
	}
	for(i=1;i<=n;i++){
		cin>>k;
		for(j=1;j<=k;j++){
			cin>>x>>z;
			f[x].push_back(i+2*m);
			f[i+2*m].push_back(x);
			g[x].push_back(z);
			g[i+2*m].push_back(z);
		}
	}
	while(T--){
		cin>>x>>y;
		x+=m;y+=m;
		for(i=1;i<=2*m+n;i++) dis[i]=2e9,vis[i]=0;
		q.push(make_pair(0,x));
		dis[x]=0;
		vis[x]=1;
		while(!q.empty()){
			x=q.top().second;
			q.pop();
			vis[x]=0;
			for(i=0;i<f[x].size();i++){
				sx=f[x][i];sg=g[x][i];
				if(dis[sx]>dis[x]+sg){
					dis[sx]=dis[x]+sg;
					if(!vis[sx]) vis[sx]=1,q.push(make_pair(dis[sx],sx));
				}
			}
		}
		if(!q.empty()) q.pop();
		cout<<dis[y]<<"\n";
	}
	return 0;
}

