#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2e6+5;
int x[N],dis[N],cnt[N];
vector<int>g[N];
int n,d;
void dfs(int u,int w){
	for(int v:g[u]){
		if(w+1<dis[v])dis[v]=w+1,cnt[v]=1;
		else if(w+1==dis[v])cnt[v]++;
		dfs(v,w+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			g[i].clear();
		}
  		for(int i=n-1;i>=1;i--){
  			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d)g[i].push_back(j);
			}
			for(int j=i+1;j<=n;j++)cnt[j]=0,dis[j]=0x3f3f3f3f;
			dfs(i,0);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2){
					ans++;
					//cout<<i<<' '<<j<<'\n';
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/