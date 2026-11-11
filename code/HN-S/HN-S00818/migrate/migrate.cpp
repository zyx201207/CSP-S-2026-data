#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e6+5;
int c,_,n,d;
int x[N],dis[N],cnt[N];
bool vis[N];
vector<int> G[N];
struct NODE{
	int v,val;
	bool operator < (const NODE &b) const{
		return val>b.val;
	}
};

void bfs(int s){
	for(int i=1;i<=n;i++)
		dis[i]=1e18,vis[i]=0,cnt[i]=0;
	priority_queue<NODE> q;
	q.push({s,0});
	dis[s]=0,cnt[s]=1;
	while(!q.empty()){
		auto cur=q.top();
		q.pop();
		if(vis[cur.v])
			continue;
		vis[cur.v]=1;
		for(int i:G[cur.v])
			if(dis[i]>dis[cur.v]+1)
				dis[i]=dis[cur.v]+1,cnt[i]+=cnt[cur.v],q.push({i,dis[i]});
	}
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		G[i].clear();
	for(int i=1;i<=n;i++)
		cin>>x[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j&&abs(x[i]-x[j])<=d)
				G[i].push_back(j);
	int ans=0;
	for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=1;j<=n;j++)
			cout<<cnt[j]<<' ';
		cout<<'\n';
		for(int j=i+1;j<=n;j++)
			if(cnt[j]==2) ans++;
	}
	cout<<ans<<'\n';
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>_;
	while(_--)
		solve();
	return 0;
}
