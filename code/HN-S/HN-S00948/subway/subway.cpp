#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,d,q,c;
int tai[500005];
vector<int> mp[500005];
int dp[5005][5005];
int st,et;
void dfs(){
	
}
signed main(){
	memset(mp,0,sizeof(mp));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>tai[i];
	}
	for (int i=1;i<=n;i++){
		int k;
		cin>>k;
		int u,val;
		cin>>u>>val;
		for (int i=1;i<=k-1;i++){
			int v,va;
			cin>>v>>va;
			mp[u][v]=val+va;
			mp[v][u]=val+va;
			u=v;
			val=va;
		}
	}
	while(q--){
		cin>>st>>et;
		
	}
	return 0;
}
