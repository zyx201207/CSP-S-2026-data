#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=2000010;
int c,t,n;
int cnt[N],dis[N];
ll d;
ll x[N];
vector<int> g[N];
void bfs(int s){
	for(int i=1;i<=n;++i) cnt[i]=1,dis[i]=-1;
	dis[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:g[u]){
			if(dis[v]!=-1){
				if(dis[u]+1==dis[v]) cnt[v]+=cnt[u];
				continue;
			}
			dis[v]=dis[u]+1;
			cnt[v]=cnt[u];
			q.push(v);
		}
	}
}
void solve(){
	ll ans=0;
	for(int i=1;i<=n;++i)
		g[i].clear();
	for(int i=1;i<=n;++i){
		int r=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
		if(r>n) r=n;
//		cout<<"tiaoshi "<<i<<' '<<r<<'\n';
		for(int j=i+1;j<=r;++j)
			g[i].push_back(j),g[j].push_back(i);
	}
//	for(int i=1;i<=n;++i){
//		cout<<i<<' ';
//		for(auto v:g[i]){
//			cout<<v<<' ';
//		}
//		cout<<'\n';
//	}
	for(int s=1;s<n;++s){
		bfs(s);
//		cout<<"dis ";
//		for(int i=1;i<=n;++i) cout<<dis[i]<<' ';
//		cout<<'\n';
//		cout<<"cnt ";
//		for(int i=1;i<=n;++i) cout<<cnt[i]<<' ';
//		cout<<'\n';
		for(int i=s+1;i<=n;++i){
//			if(s==4&&i==10) cout<<dis[i]<<' ' <<cnt[i]<<'\n';
			if(cnt[i]==2){
				ans++;
//				cout<<"ans "<<s<<' '<<i<<'\n';
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int _=1;_<=t;++_){
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>x[i];
		if(n<=5000){
			solve();
		}
	}
	return 0;
}
/*
0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
*/
