#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,ans,x,y,min_dist,dst[550][550];
int w[550],k,t[500005],a[500005],flag[550],f[550][550];
vector<pair<int,int> > g[505];
void dfs(int u,int v,ll dist){
	if(dst[u][v]>=0){
		min_dist=min(min_dist,dist+dst[u][v]);
		return;
	}
	for(int i=0;i<g[u].size();i++){
		int p=g[u][i].first,r=g[u][i].second;
		if(flag[p]==0){
			flag[p]=1;
			dfs(p,v,dist+r);
			flag[p]=0;
		}
	}
}
void solve(){
	memset(flag,0,sizeof(flag));
	cin>>x>>y;
	ans=w[x]+w[y];
	min_dist=1e9;
	dfs(x,y,0);
	ans+=min_dist;
	dst[x][y]=min_dist;
	cout<<ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(dst,-1,sizeof(dst));
	for(int i=1;i<=m;i++){
		dst[i][i]=0;
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			for(int l=1;l<j;l++){
				if(f[a[j]][a[l]]==0){
					f[a[j]][a[l]]=g[a[j]].size()-1;
					f[a[l]][a[j]]=g[a[l]].size()-1;
					g[a[j]].push_back(make_pair(a[l],t[j]+t[l]));
					g[a[l]].push_back(make_pair(a[j],t[j]+t[l]));
				}
				else{
					int p=g[a[j]][f[a[j]][a[l]]].second,r=t[j]+t[l];
					g[a[j]][f[a[j]][a[l]]].second=min(p,r);
					g[a[l]][f[a[l]][a[j]]].second=min(p,r);
				}
			}
		}
	}
	while(q--){
		solve();
		cout<<"\n";
	}
	return 0;
}

