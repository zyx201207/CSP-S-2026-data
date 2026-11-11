#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k,start,endd,ans;
long long w[500005];
long long a[500005][505];
long long tmp;
long long x[500005],t;
vector<pair<long long,long long>> tu[500005];
long long dist[500005];
void dji(long long s){
	fill(dist+1,dist+m+1,1e18);
	priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<>> pq;
	dist[s]=w[s];
	pq.push({dist[s],s});
	while(!pq.empty()){
		auto u=pq.top();
		pq.pop();
		if(u.first>dist[u.second])continue;
		for(auto i:tu[u.second]){
			if(dist[u.second]+a[u.second][i.second]+a[i.first][i.second]<dist[i.first]){
				dist[i.first]=dist[u.second]+a[u.second][i.second]+a[i.first][i.second];
				pq.push({dist[i.first],i.first});
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
		cin>>k;
		tmp=0;
		for(int j=1;j<=k;j++){	
			cin>>x[j]>>t;
			for(int l=1;l<=j;l++){
				tu[x[l]].push_back({x[j],i});
				tu[x[j]].push_back({x[l],i});
			}	
			a[x[j]][i]=t;
		}
	}
	while(q--){
		cin>>start>>endd;
		dji(start);
		cout<<dist[endd]+w[endd]<<endl;
	}
	return 0;
}
