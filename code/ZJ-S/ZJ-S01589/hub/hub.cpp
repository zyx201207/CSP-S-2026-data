#include<bits/stdc++.h>
using namespace std;
#define int long long
 int n,m,ans=1e18;
 int ds[2000010];
 bool vs[2000010],vs0[2000010];
 vector<int>vr[2000010];
void dfs0(int p,int ft,int ln){
	ds[p]=min(ds[p],ln);
	for(auto x:vr[p])if(x!=ft)dfs0(x,p,ln+1);
}
void dfs01(int p,int ft){
	vs0[p]=1;
	for(auto x:vr[p])if(x!=ft&&vs[x])dfs01(x,p);
}
void calc(int p,int p0){
	if(!p0){
		int as=0,as0=0;
		for(int i=1;i<=p;i++)vs[i]=0;
		for(int i=1;i<=n;i++)ds[i]=1e18;
		for(int i=1;i<=n;i++)vs0[i]=0;
		for(int i=1;i<=n;i++){
			if(vs0[i]||!vs[i])continue;
			as0++;
			if(as0>2)return ;
			dfs01(i,i);
		}
		for(int i=p+1;i<=n;i++)if(vs[i])dfs0(i,i,0);
		for(int i=1;i<=n;i++)as=max(as,ds[i]);
		ans=min(ans,as);
		return ;
	}
	vs[p]=1;
	calc(p-1,p0-1);
	if(p<=p0)return ;
	vs[p]=0;
	calc(p-1,p0);
}
void init(){
	ans=1e18;
	for(int i=1;i<=n;i++)vr[i].clear();
	for(int i=1;i<=n;i++)vs[i]=0;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _;
	cin>>_;
	cin>>_;
	while(_--){
		cin>>n>>m;
		init();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			vr[u].push_back(v);
			vr[v].push_back(u);
		}
		calc(n,m);
		cout<<ans<<"\n";
	}
	return 0;
}