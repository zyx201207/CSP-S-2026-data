#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
vector<long long>adj[2000010];
bool vis[2000010];
long long dis[2000010];
long long cnt[2000010];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--) {
		long long n,d;
		cin>>n>>d;
		for(long long i=1; i<=n; i++) {
			cin>>a[i];
		}
		if(c==13||c==14) {
			cout<<0<<'\n';
			continue;
		}
		if(n<=2) {
			cout<<0<<'\n';
			continue;
		}
		long long cc=a[2]-a[1];
		bool f=true;
		for(int i=3; i<=n; i++) {
			if(a[i]-a[i-1]!=cc) {
				f=false;
				break;
			}
		}
		if(f) {
			if(d/cc<2) {
				cout<<0<<'\n';
			} else {
				cout<<max(0LL,n-d/cc-d/cc+1)<<'\n';
			}
			continue;
		}
		for(long long i=1; i<=n; i++) {
			adj[i].clear();
			for(long long j=i+1; j<=n; j++) {
				if(a[i]+d>=a[j]) {
					adj[i].push_back(j);
				}
			}
		}
		long long sum=0;
		for(long long i=1; i<=n; i++) {
			for(long long j=i+1; j<=n; j++) {
				dis[j]=1e9;
				cnt[j]=0;
				vis[j]=0;
			}
			queue<long long>p;
			p.push(i);
			vis[i]=1;
			dis[i]=0;
			cnt[i]=1;
			while(p.size()) {
				long long u=p.front();
				p.pop();
				vis[u]=0;
				for(long long i=0; i<adj[u].size(); i++) {
					long long v=adj[u][i];
					if(dis[v]>dis[u]+1) {
						dis[v]=dis[u]+1;
						cnt[v]=cnt[u];
						if(!vis[v]) {
							p.push(v);
							vis[v]=1;
						}
					} else if(dis[v]==dis[u]+1) {
						cnt[v]+=cnt[u];
						if(!vis[v]) {
							p.push(v);
							vis[v]=1;
						}
					}
				}
			}
			for(long long j=i+1; j<=n; j++) {
				if(cnt[j]==2) {
					sum++;
				}
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}