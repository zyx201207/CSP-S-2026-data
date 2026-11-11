#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q,a[500020],ans=2147483647;
vector<pair<int,int>>t[520];
vector<pair<int,int>>s[500020];
bool vis[500020];
//priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
/*void d(int x,int endd,int k,int sum){
	//huan
	if(x==endd) ans=min(ans,sum);
	if(vis[x]) continue;
	vis[x]=1;
	for(auto i:s[x]){
		if(i.first==k) continue;
		dfs(x,endd,i.first,sum+i.second+s[x]);
	}
	for(auto i:t[x]){
		if(vis[i.first]) continue;
		dfs(i.first,endd,k,sum);
	}
}*/
int main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int u,v;cin>>u>>v;
			t[i].push_back({u,v});
			s[u].push_back({i,v});
		}
	}
	while(q--){
		int beg,ed;ll t=0;
		cin>>beg>>ed;
		t+=(a[beg]+a[ed]);
		vis[beg]=1;
		cout<<t<<endl;
	}
	return 0;
}
