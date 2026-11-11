#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int len,n,c,t,r;
ll cnt,ans,d,a[N],vis[N],sum;
vector<int> ed[N];
queue<int> q;
void dfs(int x,int y,int step) {
	if (x==y) {
		if (step==vis[y]-1) cnt++;
		return;
	}
	for (auto v:ed[x]) {
		if (v>=x&&v<=y) {
			dfs(v,y,step+1);
		}
	}
}
bool check(int x,int y) {
	while (!q.empty()) q.pop();
	q.push(x);
	for (int i=x;i<=y;i++) vis[i]=0;
	vis[x]=1;
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for (auto v:ed[u]) {
			if (!vis[v]) {
				vis[v]=vis[u]+1;
				q.push(v);
			}
		}
	}
	cnt=0;
	dfs(x,y,0);
	return cnt==2;
}
void solve() {
	ans=0;
	scanf("%d%lld",&n,&d);
	for (int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	if (c==11||c==12) {
		if (n<4) {
			printf("0\n");
		} else {
			if (a[4]-a[1]>d&&a[3]-a[1]<=d) printf("%d\n",n-3);
			else printf("0\n");
		}
		return;
	}
	r=1;
	for (int i=1;i<=n;i++) {
		ed[i].clear();
		while (a[r]<=a[i]+d&&r<=n) r++;
		r--;
		for (int j=i+1;j<=r;j++)
			ed[i].push_back(j);
	}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++) {
			if (check(i,j)) {
				ans++;
			}
		}
	printf("%lld\n",ans);
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while (t--) {
		solve();
	}
	return 0;
}
