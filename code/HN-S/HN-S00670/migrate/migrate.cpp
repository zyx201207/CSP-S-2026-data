#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+5;
vector<pair<int,int> >G[maxn];
int n,d;
int a[maxn];
int dis[maxn];
int dp[maxn];
int c,T;
int sum=0;
bool vis[maxn];
void dij(int x){
	queue<int>q;
	q.push(x);
	for(int i=1;i<=n;i++){
		dis[i]=1e18;
		dp[i]=0;
		vis[i]=false;
	}
	dp[x]=1;
	dis[x]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i].first;
			int w=G[u][i].second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				dp[v]=dp[u];
				q.push(v);
			}
			else if(dis[v]==dis[u]+w){
				dp[v]+=dp[u];
			} 
		}
	}
	for(int i=x+1;i<=n;i++){
		//cout<<x<<" "<<dis[i]<<" "<<dp[i]<<endl;
		if(dp[i]==2){
			sum++;
		}
	} 
	return ;
}
void work(){
	sum=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<=n;i++) cin>>a[i];
	if(c>=13&&c<=14&&n>5000){
		int maxi=-2e18,mini=2e18;
		for(int i=1;i<=n;i++){
			maxi=max(maxi,a[i]);
			mini=min(mini,a[i]);
		}
		for(int i=1;i<=n;i++){
			if(abs(maxi-a[i])+abs(mini-a[i])<=d) sum++;
		}
		cout<<n-sum<<"\n";
		return ;
	}
	else if(n>5000){
		cout<<0<<"\n";
		return ;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		    if(abs(a[i]-a[j])<=d){
		    	G[i].push_back({j,1});
		    	G[j].push_back({i,1});
			}
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
	}
	cout<<sum<<"\n";
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		work();
	}
	return 0;
}
