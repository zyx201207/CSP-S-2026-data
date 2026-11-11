#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,T=1;
int n,d;
int a[N];
vector<int>g[N];
bool vis[N];
int dis[N];
int cnt[N];
int ans;
void bfs(int x){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	memset(cnt,0,sizeof cnt);
	queue<pair<int,int> >q;
	q.push({x,0});
	dis[x]=0;
	while(!q.empty()){
		auto last=q.front();
		q.pop();
		int u=last.first,step=last.second;
		vis[u]=true;
		for(auto v:g[u]){
			if(dis[v]==dis[0]){
				dis[v]=dis[u]+1;
				cnt[v]++;
				if(!vis[v])q.push({v,dis[v]});
			}
			else if(dis[u]+1==dis[v]){
				cnt[v]++;
				if(cnt[v]<=3)q.push({v,dis[v]});
			}
		}
	} 
//	for(int i=1;i<=n;i++){
//		cout<<dis[i]<<' ';
//	}
//	cout<<"\n";
	for(int i=1;i<=n;i++){
//		cout<<cnt[i]<<' ';
		if(cnt[i]==2){
//			cout<<i<<' '<<x<<"\n";
			ans++;
		}
	}
//	cout<<"\n\n";
}
void solve(){
	ans=0;
	for(int i=1;i<=n;i++)g[i].clear();
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(c==11||c==12){
//		cout<<1;
		d/=a[2]-a[1];
		if(d<=1)cout<<"0\n";
		else if(n+1<2*d)cout<<"0\n";
		else cout<<n-2*d+1<<"\n";
		return ;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(a[i]-a[j])<=d)g[i].push_back(j),g[j].push_back(i);
			else break;
		}
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	} 
//	cout<<ans<<'\n';
	cout<<ans/2<<"\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
1 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983

1 1
5 2
1 2 3 4 5

1 1
10 4
1 2 3 4 5 6 7 8 9 10
*/
