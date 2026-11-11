#include<bits/stdc++.h>
using namespace std;
struct P{
	long long v,w;
};
long long c,n,m,d,q,dis[20005];
long long w[20005],a[505][20005],t[505][20005],k[505],v[20005][505];
vector<P> g[20005];
vector<long long> s[20005];
priority_queue<pair<long long,long long> ,vector<pair<long long,long long> >,greater<pair<long long,long long> > > pq;
void djs(long long fx,long long fy){
	memset(dis,0,sizeof(dis));
	memset(v,0,sizeof(v));
	for(auto i:s[fx]){
		pq.push({fx,i});
	}
	dis[fx]=w[fx];
	while(pq.size()>0){
		long long nx=pq.top().first;
		long long ny=pq.top().second;
		pq.pop();
		if(v[nx][ny]==1){
			continue;	
		}
		v[nx][ny]=1; 
		for(auto i:g[nx]){
			if(i.w!=ny){
				if(dis[i.v]>dis[nx]+t[ny][nx]+t[i.w][nx]){
					dis[i.v]=dis[nx]+t[ny][nx]+t[i.w][nx];	
					pq.push({i.v,i.w});
				}
			}else{
				pq.push({i.v,i.w});
			}
			
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][a[i][j]];
			s[a[i][j]].push_back(i);	
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=k[i];j++){
			g[a[i][j]].push_back({a[i-1][j],i});
			g[a[i-1][j]].push_back({a[i][j],i});
		} 
	}
	while(q--){
		long long x,y;
		cin>>x>>y;
		djs(x,y);
		cout<<dis[y]+w[y]<<endl;
	}
	return 0;
}
