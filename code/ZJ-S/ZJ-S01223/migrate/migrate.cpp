#include <bits/stdc++.h>

using namespace std;
int n,d;
const int N=2e6+5;
long long x[N];
vector<int>G[N];
long long mi=1e18;
long long cnt;
bool vis[N];
void dfs(int x,int y,int sum){
	if(sum>mi||(x!=y&&sum==mi))return;
	if(x==y){
		if(mi==sum){
			cnt++;
		}else if(sum<mi){
			cnt=1,mi=sum;
		}
		return;
	}
	for(auto v:G[x]){
		if(vis[v])continue;
		vis[v]=1;
		dfs(v,y,sum+1);
		vis[v]=0;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			G[i].clear();
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					G[i].push_back(j);
					G[j].push_back(i);
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				vis[i]=1;
				cnt=0;mi=1e18;
				dfs(i,j,0);
				vis[i]=0;
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<"\n"; 
	}
	return 0;
} 
