#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=205+5;
ll c,n,m,d,q,w[N],num,st[N],ed[N],k[N],a[N][N],t[N][N],mn;
vector<pair<int,int>>g[N];
void dfs(int fa,int st,int ed,ll sum){
	if(st==ed){
		mn=min(mn,sum);
		return ;
	}
	for(auto v:g[st]){
		int u=v.first,w=v.second;
		if(u==fa)continue;
		dfs(st,u,ed,sum+w);
	}
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			g[a[i][j-1]].push_back({a[i][j],w[i]+t[i][j]});
		}
	}
	for(int i=1;i<=n;i++){
		for(auto u:g[i])cout<<u.first<<" "<<u.second<<"  ";
	}
	for(int i=1;i<=q;i++){
		cin>>st[i]>>ed[i];
		dfs(0,st[i],ed[i],0);
		cout<<mn<<"\n";
	}
	return 0;
} 