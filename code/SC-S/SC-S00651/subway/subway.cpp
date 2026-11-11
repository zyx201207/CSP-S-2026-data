#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[600005],k[505],X,Y,u[505][505],dis[505];
vector<long long>a[505],t[505],x[600505],y[600505];
vector<pair<long long,long long>>s[600505];
priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>f;
long long dijkstra(long long q,long long z){
	long long vis[505];
	for(int i=1;i<=n;i++){
		dis[i]=0x3f3f3f3f3f3f;
		vis[i]=0;
	}
	for(int i=0;i<x[z-n].size();i++){
		vis[x[z-n][i]]=i+1;
	}
	long long ans=0x3f3f3f3f3f3f;
	for(int i=0;i<s[q].size();i++){
		f.push({s[q][i].first,s[q][i].second});
		dis[s[q][i].first]=s[q][i].second;
	}
	while(!f.empty()){
		long long u=f.top().first;
		if(vis[u]){
			long long r=vis[u];
			ans=min(ans,dis[u]+y[z-n][r-1]);
		}
		f.pop();
		for(int i=0;i<s[u].size();i++){
			long long v=s[u][i].first,w=s[u][i].second;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				f.push({v,dis[v]});
			}
		}
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>X;
			a[i].push_back(X);
			x[X].push_back(i);
			cin>>Y;
			t[i].push_back(Y);
			y[X].push_back(Y);
			s[X+n].push_back({i,Y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			u[i][j]=0x3f3f3f3f3f3f3f;
		}
	}
	for(int i=1;i<=m;i++){
		if(x[i].size()>=2){
			for(int j=0;j<x[i].size();j++){
				for(int l=0;l<j;l++){
					u[x[i][j]][x[i][l]]=min(u[x[i][j]][x[i][l]],y[i][j]+y[i][l]);
					u[x[i][l]][x[i][j]]=min(u[x[i][l]][x[i][j]],y[i][l]+y[i][j]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			s[i].push_back({j,u[i][j]});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>X>>Y;
		cout<<dijkstra(X+n,Y+n)+w[X]+w[Y]<<endl;
	}
	return 0;
} 