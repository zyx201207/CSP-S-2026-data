#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > >pq;
vector<pair<long long,long long > >v[501001];
long long vis[501001];
long long d[501001];
long long a[501001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long n,m,q,x,y,z;
	cin>>q>>n>>m>>q>>q;
	
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>y>>z;
			v[m+i].push_back({z,y});
			v[y].push_back({z,m+i});
		}
	}
	while(q--){
		for(int i=1;i<=n+m;i++)d[i]=5e18,vis[i]=0;
		cin>>x>>y;
		pq.push({0,x});
		d[x]=0;
		while(!pq.empty()){
			z=pq.top().first;
			long long s=pq.top().second;
			pq.pop(); 
			if(vis[s]==1)continue;
			vis[s]=1;
			for(int i=0;i<v[s].size();i++){
				if(z+v[s][i].first<d[v[s][i].second]){
					d[v[s][i].second]=z+v[s][i].first;
					pq.push({d[v[s][i].second],v[s][i].second});
				}
			}
		}cout<<d[y]+a[x]+a[y]<<endl;
	}
	return 0;
} 
