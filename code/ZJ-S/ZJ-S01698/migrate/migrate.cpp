#include<bits/stdc++.h>
using namespace std;

namespace wsrCSPS {
	using ll=long long;

	const int N=5009;
	int n,dis[N][N],cnt[N][N];
	ll d,x[N];
	vector<int>G[N];
	void solve1() {
		int T;cin>>T;
		while(T--) {
			memset(dis,-1,sizeof(dis));
			memset(cnt,0,sizeof(cnt));
			cin>>n>>d;
			for(int i=1;i<=n;i++) G[i].clear();
			for(int i=1;i<=n;i++) cin>>x[i];
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++) 
					if(i!=j&&abs(x[i]-x[j])<=d)
						G[i].push_back(j);
			for(int i=1;i<=n;i++) {
				queue<int>q;
				q.push(i);
				dis[i][i] = 0;
				cnt[i][i] = 1;
				while(q.size()) {
					int u=q.front();q.pop();
					for(auto &v:G[u]) {
						if(dis[i][v]!=-1&&dis[i][v]==dis[i][u]+1) {
							q.push(v);
							cnt[i][v]++;
						} 
						else if(dis[i][v]==-1) {
							dis[i][v] = dis[i][u]+1;
							cnt[i][v]++;
							q.push(v);
						}
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++) if(cnt[i][j]==2)
					ans++;
			ans /= 2;
			cout<<ans<<"\n";
		}
	}
	
	int main() {
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int c;cin>>c;
		if(c<=10) solve1(); // bf
		return 0;
	}
}

int main() { return wsrCSPS::main(); }
/*
Ԥ�Ƶ÷֣�24 pts 
*/
