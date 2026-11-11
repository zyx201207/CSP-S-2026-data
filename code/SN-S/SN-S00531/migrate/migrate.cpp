//SN-S00531 张之奇 西安市铁一中学
#include <bits/stdc++.h>
using namespace std;

const int maxn=2e6+5;
const int inf=1e9;
int cas;
int n;
long long d,x[maxn];
vector<int> G[maxn];

queue<int> Q;
int dis[maxn],vis[maxn];
long long cnt[maxn],sum[maxn];

void bfs(int s){
	for (int i=1;i<=n;i++)	dis[i]=inf,cnt[i]=vis[i]=0;
	dis[s]=0;vis[s]=cnt[s]=1;Q.push(s);
	while (Q.size()){
		int u=Q.front();Q.pop();
		for (int v:G[u]) {
			if (!vis[v]){
				Q.push(v);
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				vis[v]=1;
			}
			else if (dis[v]==dis[u]+1)	cnt[v]+=cnt[u];
		}
	}
}

void solve(){
	cin>>n>>d;
	for (int i=1;i<=n;i++)	cin>>x[i];
	if (n==1){
		cout<<0<<"\n";
		return ;
	}
	if (cas<=10){
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) if (i!=j){
			if (abs(x[j]-x[i])<=d)	G[i].push_back(j);
		}
		long long ans=0;
		for (int i=1;i<=n;i++){
			bfs(i);
			for (int j=i+1;j<=n;j++)	ans+=(cnt[j]==2);
		}
		cout<<ans<<endl;
		for (int i=1;i<=n;i++)	G[i].clear();
	}
	else if (cas==11||cas==12){
		int t=d/(x[2]-x[1]); t=2*t-1;
		if (d<2*(x[2]-x[1])){
			cout<<0<<"\n";
			return ;
		}
		long long ans=0;
		for (int i=1;i<=n;i++) if (i+t<=n)	ans++;
		cout<<ans<<"\n";
	}
	else if (cas==13||cas==14){
		int mn=n,mx=0;
		for (int i=1;i<=n;i++) if (abs(x[i]-x[1])<=d&&abs(x[i]-x[n])<=d)	mn=min(mn,i),mx=max(mx,i);
		long long ans=0;
		cnt[mx+1]=sum[mx+1]=upper_bound(x+1,x+n+1,x[mx+1]+d)-x-mx-2;
		for (int i=mx+2;i<=n;i++){
			int l=upper_bound(x+1,x+n+1,x[i-1]+d)-x;
			int r=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
			cnt[i]=r-l+1;
			sum[i]=sum[i-1]+cnt[i];
		}
		for (int i=1;i<=mn-1;i++){
			int l=upper_bound(x+1,x+n+1,d+x[i])-x-1;
			ans+=(sum[l]-sum[mx]);
		}
		cout<<ans<<"\n";
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;for (cin>>cas>>T;T--;)
	solve();
	return 0;
}

/*
13 1
6 5
0 1 2 5 6 10
*/
