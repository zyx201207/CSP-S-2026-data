#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[20005],k[505],aa;
long long dis[20005],x,y,ans,t[20005][505];
vector<long long>a[505];
vector<long long>_a[20005];
vector<pair<long long,long long>>v[505]; 
long long spfa(long long x){
	for(long long i=1;i<=n;i++)dis[i]=1e9;
	queue<long long>q;
	dis[x]=0;
	q.push(x);
	while(q.size()){
		long long u=q.front();q.pop();
		for(auto c:v[u]){
			long long to=c.first,w=c.second;
			if(dis[to]>dis[u]+w){
				dis[to]=dis[u]+w;
				q.push(to);
			}
		}
	}
	long long mn=1e9;
	for(long long ss:_a[y])mn=min(mn,dis[ss]+t[y][ss]);
	return mn;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)cin>>w[i];
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>aa;
			a[i].push_back(aa);
			_a[aa].push_back(i);
			cin>>t[aa][i];
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			long long mn=1e9;
			for(long long k:a[i]){
				if(t[k][j]!=0){
					mn=min(mn,t[k][i]+t[k][j]);
				}
			}
			v[i].push_back({j,mn});
			v[j].push_back({i,mn});
		}
	}
	while(q--){
		ans=1e9;
		cin>>x>>y;
		for(long long lu:_a[x]){
			ans=min(spfa(lu)+t[x][lu],ans);
		}
		ans+=w[x];ans+=w[y];
		cout<<ans<<"\n";
	}
	return 0;
} 