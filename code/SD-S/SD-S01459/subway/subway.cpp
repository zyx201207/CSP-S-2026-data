#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
int c,n,m,d,q;
const int N=5e5+5;
int w[N];
int a[500][22];
int cnt[N];
int data[N];
int k;
int tot=-1;
int to[2*N],nxt[2*N],head[N];
bool flag[N];
int vis[N*2];
void add(int x,int y,int z) {
	to[++tot]=y;
	vis[tot]=z;
	nxt[tot]=head[x];
	head[x]=tot;
}
int ans=0x3f3f3f3f;
void dfs(int x,int sum,int y) {
	if(x==y) {
		ans=min(ans,sum);
		return ;
	}
	flag[x]=true;
	for(int i=head[x]; i!=-1; i=nxt[i]) {
		if(!flag[to[i]]) {
			dfs(to[i],sum+vis[i],y);
		}
	}
	flag[x]=false;
	return ;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(head,-1,sizeof(head));
	for(int i=1; i<=m; i++) cin>>w[i];
	for(int i=1; i<=n; i++) {
		cin>>k;
		int x,y;
		int x1,y1;
		cin>>x1>>y1;

		for(int j=2; j<=k; j++) {
			cin>>x>>y;
			add(x1,x,y1+y);
			add(x,x1,y1+y);
			x=x1;
			y=y1;

		}
	}
	while(q--) {
		int x,y;
		ans=0x3f3f3f3f;
		cin>>x>>y;
		dfs(x,w[x]+w[y],y);
		cout<<ans<<endl;
	}
	return 0;
}

