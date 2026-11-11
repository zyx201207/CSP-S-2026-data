#include<bits/stdc++.h>
#define int long long
#define fr first
#define sc second
using namespace std;
const int N=5e3+3;
const int inf=1e18;

int c;
int n,d;
int x[N];
vector<int> g[N];
int dis[N],cnt[N];
queue<int> q;
void bfs(int s) {
	for(int i=1; i<=n; i++)dis[i]=inf,cnt[i]=0;
	dis[s]=0,cnt[s]=1;
	q.push(s);
	while(q.size()) {
		int u=q.front();
		q.pop();
		for(auto v:g[u]) {
			if(dis[v]>dis[u]+1) {
				dis[v]=dis[u]+1;
				cnt[v]=0;
				q.push(v);
			}
			if(dis[v]==dis[u]+1)cnt[v]++;
		}
	}
}
void solve() {
	cin>>n>>d;
	for(int i=1; i<=n; i++) {
		cin>>x[i];
		g[i].clear();
	}
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			if(abs(x[i]-x[j])<=d) {
				g[i].push_back(j);
			}
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		bfs(i);
		for(int j=i+1; j<=n; j++) {
			if(cnt[j]==2) {
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}

signed main() {
	int T=1;
	freopen("migrate2.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
/*
多测要清空
注意 ll 和 double 精度
ds 要 build
不要饭堂qwq
*/

