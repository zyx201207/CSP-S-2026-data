#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1005,inf=1e18,mod=1e9+7;
ll t,n,k,c,ans,d[N][N];
bool vis[N][N],vis1[N];
vector<ll> v[N],a;
void solve(){
	ll res=0;
	for(int i=1;i<=n;i++){
		for(auto j:a) if(!vis1[i]) res=max(res,d[i][j]);
	}
	ans=max(ans,res);
	return ;
}
void dfs(ll x,ll y,ll cnt,ll s){
	if(cnt==k){
		solve();
		return ;
	}
	for(int i=s;i<=n-(k-cnt);i++){
		if(vis[i][x]==1||vis[i][y]==1){
			a.push_back(i);
			vis1[i]=1;
			dfs(x,y,cnt+1,i+1);
			vis1[i]=0;
			a.pop_back();
		}
	}
}
void getd(ll x,ll fa){
	d[x][fa]=d[fa][x]=1;
	if(v[x].size()==0) return ;
	for(auto i:v[x]){
		if(i!=fa) getd(i,x);
		for(int j=1;j<=n;j++){
			if(j!=x) d[x][j]=d[j][x]=d[i][j]+1;
		}
		d[x][i]=d[i][x]=1;
	}
}
signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ll ans=-inf;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j]=0;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			ll x,y;
			cin>>x>>y;
			v[x].push_back(y),v[y].push_back(x);
			vis[x][y]=vis[y][x]=1;
		}
		getd(1,0);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<d[i][j]<<' ';
			}
			cout<<'\n';
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				a.push_back(i);
				a.push_back(j);
				dfs(i,j,2,3);
				a.clear();
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
