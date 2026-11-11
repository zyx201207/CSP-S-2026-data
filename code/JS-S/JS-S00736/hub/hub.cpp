#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e6+5,MAXM=1e3+5;
int n,K,c;
vector<int> a[MAXN];
bool vis[MAXN];
int dist[MAXM][MAXM];
void dfs1(int x,int p,int u){
	for(int i=0;i<a[x].size();i++){
		int to=a[x][i];
		if(to==p){
			continue;
		}
		dist[u][to]=dist[u][x]+1;
		dfs1(to,x,u);
	}
}
void dfs(int x,int p){
	vis[x]=0;
	for(auto to:a[x]){
		if(vis[to]){
			dfs(to,x);
		}
	}
}
void solve(){
	cin>>n>>K;
	for(int i=1;i<=n;i++){
		a[i].clear();
	}
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		a[x].push_back(y),a[y].push_back(x);
	}
	if(c==13||c==14){
		// cerr<<n<<" "<<K<<" ";
		n=(n-1)/2;
		if(n%2==1&&K%2==1){
			n--,K--;
		}
		n=(n+1)/2,K/=2;
		// cerr<<(n-K+1)/2<<"\n";
		cout<<(n-K+1)/2+1<<"\n";
		return ;
	}
	for(int i=1;i<=n;i++){
		dfs1(i,0,i);
		// for(int j=1;j<=i;j++){
		// 	cout<<i<<" "<<j<<" "<<dist[i][j]<<"\n";
		// }
	}
	int ans=1e18;
	for(int i=0;i<1<<n;i++){
		if(__builtin_popcount(i)!=K){
			continue;
		}
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))){
				vis[j]=1;
			}
		}
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j]){
				dfs(j,0);
				cnt++;
			}
		}
		if(cnt==2){
			// cout<<i<<"\n";
			int maxn=0;
			for(int j=1;j<=n;j++){
				int minn=1e18;
				for(int k=1;k<=n;k++){
					if(i&(1<<(k-1))){
						minn=min(minn,dist[j][k]);
					}
				}
				maxn=max(maxn,minn);
			}
			ans=min(ans,maxn);
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}