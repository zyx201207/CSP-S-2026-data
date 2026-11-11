#include<bits/stdc++.h>
#define sjh0626s return
#define code 0
#define ll long long
#define PII pair<int,int>
#define all(v) v.begin(),v.end()
using namespace std;
int T=1,c,n,m,u,v,a[1000010],ans;
vector<int>g[1000010];
void dfs(){
	
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=n;i++){
		cin>>u>>v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	cout<<max(n/m-1,1LL)<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)solve();
	sjh0626s code;
}
/*
神秘，试图 greedrand 化
再见了，I'm @luogu(user=1129497)，明年见
*/