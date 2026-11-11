#include<bits/stdc++.h>
using namespace std;
struct P{
	long long v,w;
};
long long c,t,n,d;
long long dis[2000005],vis[2000005],a[2000005],cnt[2000005];
vector<P> g[2000005];
priority_queue<long long,vector<long long>,greater<long long> > pq;
void djs(long long x){
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	pq.push(x);
	while(pq.size()>0){
		long long nx=pq.top();
		pq.pop();
		if(vis[nx]==1){
			continue;	
		}
		vis[nx]=1; 
		for(auto i:g[nx]){
			if(dis[i.v]>dis[nx]+i.w){
				dis[i.v]=dis[nx]+i.w;	
				pq.push(i.v);
			}else if(dis[i.v]==dis[nx]+i.w){
				cnt[i.v]++;
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				g[i].push_back({j,a[j]-a[i]});
				g[j].push_back({i,a[j]-a[i]});
			}
		}
		for(int i=1;i<=n;i++){
			djs(i);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=cnt[i];j++){
				ans+=j;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
