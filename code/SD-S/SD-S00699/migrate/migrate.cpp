#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int c,T;
int n,d;
int a[N];
int dis[N],pos[N];
vector<int>edge[N];
int vis[N];
void bfs(int now) {
	for(int i=1; i<=n; i++) {
		pos[i]=0;
		vis[i]=0;
	}
	dis[now]=0;
	pos[now]=1;
	vis[now]=1;
	queue<int>q;
	q.push(now);
	while(q.size()) {
		int t=q.front();
		q.pop();
		for(int i=0; i<edge[t].size(); i++) {
			int nxt=edge[t][i];
			if(vis[nxt]){
				if(dis[nxt]==dis[t]+1){
					pos[nxt]+=pos[t];
				}
			}else{
				q.push(nxt);
				vis[nxt]=1;
				dis[nxt]=dis[t]+1;
				pos[nxt]=pos[t];
			}
		}
	}
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>c>>T;
	while(T--) {
		cin>>n>>d;
		for(int i=1; i<=n; i++)cin>>a[i];
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(abs(a[j]-a[i])<=d) {
					edge[i].push_back(j);
				}
			}
		}
		int ans=0;
		for(int i=1; i<n; i++) {
			bfs(i);
			for(int j=1+i; j<=n; j++) {
				if(pos[j]==2) {
					ans++;
				}
			}
		}

		cout<<ans<<"\n";
	}
	return 0;
}

