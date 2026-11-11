#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c,T,n,d,x[50010],ans,v[50010],dist[50010];
queue <pair<ll,ll> > q;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--) {
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>x[i];
		}
		ans=0;
		x[n+1]=3e18;
		for(int j=1; j<=n; j++) {
			memset(dist,0,sizeof dist);
			while(q.size()) q.pop();
			q.push({j,0});
			dist[j]=0;
			memset(v,0,sizeof v);
			while(q.size()) {
				int t=q.front().first,dis=q.front().second;
				if(dist[t]==0) {
					dist[t]=dis;
					v[t]++;
				} else if(dist[t]==dis) v[t]++;
				if(v[t]>2) continue;
				for(int k=t+1;k<=n;k++) {
					if(x[k]-x[t]<=d&&dist[k]==0) {
						q.push({k,dist[t]+1});
					}
				}
			}
			for(int k=j+1;k<=n;k++) {
				if(v[k]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}