#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d;
int a[2000005];
vector<int> g[2000005];
queue<int> q;
bool vis[2000005];
int dist[2000005];
int minn[2000005];
int tot[2000005];
void dfs(int u,int sum) {
	if(minn[u]>sum) {
		minn[u]=sum;
		tot[u]=1;
	} else if(minn[u]==sum) {
		tot[u]++;
	}
	for(int v:g[u]) {
		if(!vis[v]) {
			vis[v]=1;
			dfs(v,sum+1);
			vis[v]=0;
		}
	}
}
void solve() {
	cin>>n>>d;
	cin>>a[1]>>a[2];
	int D=a[2]-a[1],flag=1;
	for(int i=3; i<=n; i++) {
		cin>>a[i];
		if(a[i]-a[i-1]!=D) {
			flag=0;
		}
	}
	for(int i=1; i<=n; i++) {
		g[i].clear();
	}
	if(flag) {
		int i=1;
		while(a[i]-a[1]<=d) {
			i++;
		}
		i-=2;
		if(n<2*i||i<=1) {
			cout<<"0\n";
		} else {
			cout<<n-2*i+1<<"\n";
		}
		return ;
	} else {
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(a[j]-a[i]<=d) {
					g[i].push_back(j);
				}
			}
		}
	}
	int ans=0;
	for(int T=1; T<=n; T++) {
		memset(minn,0x3f,sizeof minn);
		memset(tot,0,sizeof tot);
		memset(vis,0,sizeof vis);
		dfs(T,0);
		for(int i=T+1; i<=n; i++) {
			if(tot[i]==2) {
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
		solve();
	return 0;
}
