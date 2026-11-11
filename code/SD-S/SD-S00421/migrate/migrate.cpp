#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int c,T;
int n;
ll d;
ll a[N];
ll dp[N];
ll dis[N];
ll ans=0;
bool vis[N];
vector<int>g[N];
void bfs(int s){
	for (int i=n;i>=s;i--){
		vis[i]=0;
		dp[i]=0;
	}
	vis[s]=1,dp[s]=1;
	dis[s]=0;
	queue<int>q;
	q.push(s);
	while (!q.empty()){
		int u=q.front();
		q.pop();
		for (auto v:g[u]){
			if (!vis[v]) vis[v]=1,dp[v]=dp[u],dis[v]=dis[u]+1,q.push(v);
			else if (dis[u]+1==dis[v]) dp[v]+=dp[u];
		}
	}
	for (int i=n;i>s;i--){
		ans+=(dp[i]==2);
	}
}
void suba(){
	while (T--){
		ans=0;
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		ll g=a[n]-a[n-1];
		for (ll i=4;i<=n;i+=2){
			if (i/2*g<=d&&d<(i/2+1)*g) ans+=n-i+1;
		}
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if (c==11||c==12){
		suba();
		return 0;
	}
	while (T--){
		ans=0;
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			g[i].clear();
			cin>>a[i];
		}
		for (int i=n;i>=n-2;i--){
			for (int j=i-1;j>=n-2;j--){
				if (a[i]-a[j]<=d){
					g[j].push_back(i);
					g[i].push_back(j);
				}
			}
		}
		for (int i=n-3;i>=1;i--){
			for (int j=n;j>i;j--){
				if (a[j]-a[i]<=d) {
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
			bfs(i);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
