#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=3e5+5,mod=998244353;
int n,k;
int c,t;
int v[N],vis[N];
int dep[N];
vector<int>g[N];
void dfs(int p){
	vis[p]=1;
	for(int j:g[p]){
		if(v[j]&&!vis[j]){
			dfs(j);
		}
	}
}
int f[N];
void dfsy(int p,int fa){
	dep[p]=dep[fa]+1;
	f[p]=fa;
	for(int j:g[p]){
		if(j!=fa){
			dfsy(j,p);
		}
	}
}
int dist(int a,int b){
	if(dep[a]<dep[b])swap(a,b);
	int ans=0;
	while(dep[a]>dep[b]){
		ans++;
		a=f[a];
	}
	while(a!=b){
		ans+=2;
		a=f[a];
		b=f[b];
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfsy(1,0);
		if(n<=10){
			int ans=1000000000000;
			for(int i=1;i<=(1<<n);i++){
				int sum=0;
				for(int j=1;j<=n;j++){
					if(((1<<(j-1))&i)){
						v[j]=1;
						sum++;
					}else{
						v[j]=0;
					}
					vis[j]=0;
				}
				if(sum!=k)continue;
				int cnt=0;
				for(int j=1;j<=n;j++){
					if(v[j]&&vis[j]==0){
						cnt++;
						dfs(j);
					}
				}
				if(cnt<=2){
					int sans=0;
					for(int k=1;k<=n;k++){
						int tans=1000000000000;
						for(int j=1;j<=n;j++){
							if(v[j]){
								tans=min(tans,dist(j,k));
							}
						}
						sans=max(sans,tans);
					}
					ans=min(ans,sans);
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
