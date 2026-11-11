#include<bits/stdc++.h>
using namespace std;
#define int long long
long long a[2000010],vis[2000010];
long long n,d;
bool can(int l,int r){
	return abs(a[r]-a[l])<=d;
}
vector<int> g[2000010];
void dfs(int x,int times){
	vis[x]++;
	if(times==0){
		return;
	}
	for(int i=0;i<g[x].size();i++){
		dfs(g[x][i],times-1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		long long sum=0;
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(can(i,j)){
					g[i].push_back(j);
				}
			}
		}
		for(int i=1;i<=n;i++){
			dfs(i,2);
			for(int j=1;j<=n;j++){
				if(vis[j]==2&&j!=i){
					sum++;
				}
				vis[j]==0;
			}	
		}
		cout<<sum<<endl;
	}
	return 0;
}