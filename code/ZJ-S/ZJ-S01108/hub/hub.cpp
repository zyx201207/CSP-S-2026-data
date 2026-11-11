#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,x,y,minn;
int dp[1000010],st[1000010][25];
bool fl[1000010];
vector<int> f[1000010];
vector<int> v;
void dfs(int x,int fx) {
	st[x][0]=fx;
	dp[x]=dp[fx]+1;
	for (int i=0;i<f[x].size();i++) {
		int sx=f[x][i];
		if (fx==sx) continue ;
		dfs(sx,x);
	}
}
void make() {
	for (int j=1;j<=21;j++)
		for (int i=1;i<=n;i++)
			st[i][j]=st[st[i][j-1]][j-1];
}
int lca(int x,int y) {
	if (dp[x]<dp[y]) swap(x,y);
	int k=dp[x]-dp[y];
	for (int i=21;i>=0;i--) if (k&(1<<i)) x=st[x][i];
	if (x==y) return x;
	for (int i=21;i>=0;i--)
		if (st[x][i]!=st[y][i])
			x=st[x][i],y=st[y][i];
	return st[x][0];
}
int dist(int x,int y) {
	return dp[x]+dp[y]-2*dp[lca(x,y)];
}
bool check() {
	int l1=-1,l2=-1;
	v.clear();
	memset(fl,0,sizeof(fl));
	fl[2]=fl[3]=fl[10]=true;
	for (int i=1;i<=n;i++) if (fl[i]) v.push_back(i);
	return true;
}
void work(int t,int cnt) {
	if (t>=n+1||cnt==k) {
		if (cnt!=k) return ;
		if (!check()) return ;
		int ma=0,mi;
		for (int i=1;i<=n;i++) {
			mi=2e9;
			if (fl[i]) ;
			else {
				for (int j=0;j<v.size();j++)
					mi=min(mi,dist(i,v[j]));
				ma=max(ma,mi);
			}
		}
		exit(0);
		minn=min(minn,ma);
		return ;
	}
	if (cnt+n-t+1<k) return ;
	fl[t]=true;work(t+1,cnt+1);
	fl[t]=false;work(t+1,cnt);
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while (t--) {
		cin>>n>>k;
		memset(st,0,sizeof(st));
		memset(dp,0,sizeof(dp));
		for (int i=1;i<=n;i++) f[i].clear();
		minn=2e9;
		for (int i=1;i<=n-1;i++) {
			cin>>x>>y;
			f[x].push_back(y);
			f[y].push_back(x);
		}
		dfs(1,0);
		make();
		work(1,0);
		cout<<minn<<"\n";
	}
	return 0;
}
