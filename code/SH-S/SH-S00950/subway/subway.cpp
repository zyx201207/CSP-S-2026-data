#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll c,n,m,d,p,k,x,y,t,ans=1e18;
ll v[N];
ll vis[N];
struct node{ll e,t,f;};
vector<node>ve[N];
ll dfs(ll a,bool f,ll cnt) {
	if(a==y&&f==0) {
		ans=min(ans,cnt);
		return ans;
	}
	
	for(ll i=0;i<ve[a].size();i++) {
		ll e=ve[a][i].e;
		if(ve[a][i].f!=f||vis[e]==1) continue;
		cnt++;
		vis[e]=1;
		if(f==1) f=0;
		else f=1;
		ans=min(dfs(e,f,cnt),ans);
		cnt--;
		vis[e]=0;
	}
	return ans;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++) {
		cin>>v[i];
	}
	for(ll i=-1;i>=0-n;i--) {
		cin>>k;
		for(ll j=1;j<=k;j++) {
			ll e;
			cin>>e>>t;
			ve[i].push_back({e,t,1});
			ve[e].push_back({i,t,0});
		}
	}
	
	while(p--) {
		memset(vis,0,sizeof vis);
		cin>>x>>y;
		vis[x]=1;
		cout<<dfs(x,0,0)*t+v[x]+v[y]<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
