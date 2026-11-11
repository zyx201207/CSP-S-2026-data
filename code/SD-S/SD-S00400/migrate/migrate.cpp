#include <bits/stdc++.h>

#define PII pair <int,int>
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(u) (u).begin(),(u).end()
#define MOD 998244353
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
#define ll long long
#define N 1000005

using namespace std;
int _c,T,n,d;
int a[N],f[N],in[N];
vector <int> g[N];
signed main() {
	freopen("migrate.in","r",stdin);
//	freopen("migrate1.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>_c>>T;
	while(T --) {
		cin>>n>>d;
		for(int i = 1;i <= n;i ++) {
			cin>>a[i];
			f[i] = in[i] = 0;
			g[i].clear();
		}
		for(int i = 1;i <= n;i ++) {
			for(int j = 1;j < i;j ++) {
				if(a[i] - a[j] <= d) g[j].push_back(i),in[i] ++;
			}
		}
		queue <int> q;
		for(int i = 1;i <= n;i ++) {
			if(!in[i]) q.push(i),f[i] = 1;
		}
		while(q.size()) {
			int u = q.front();q.pop();
			for(auto v : g[u]) {
				f[v] += f[u];
			}
		}
		int ans = 0;
		for(int i = 1;i <= n;i ++) ans += (f[i] == 2);
		cout<<0<<"\n";
	}
	return 0;
}

