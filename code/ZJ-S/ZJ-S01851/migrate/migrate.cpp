#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+5;
int c,t,n,a[N],d;
int ans=0;
map<pair<int,int>,int> mp;
int bk[N],dp[N][N];
bool usd[N];
void dfs(int x,int dep,int nm){
	int l=x,r=nm;
//	cout<<x<<' '<<dep<<' '<<nm<<'\n';
	if(l>r) swap(l,r);
	if(dp[l][r]<dep) return ;
	if(l!=r&&mp.find({l,r})==mp.end()){
	//	cout<<l<<' '<<r<<' '<<dep<<'\n';
		mp[{l,r}]=1;
	}else if(l!=r){
	//	cout<<l<<' '<<r<<' '<<dep<<'\n';	
		mp[{l,r}]++;
	}
	for(int i=x+1;i<=n&&a[i]-a[x]<=d;++i){
		if(i==nm||usd[i]) continue;
		usd[i]=1;
		dfs(i,dep+1,nm);
		usd[i]=0;
	}
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		bk[i]=i;
		for(int j=i-1;j>0&&a[i]-a[j]<=d;--j){
			bk[i]=j;
		}
	}
	for(int i=1;i<n;++i){
		for(int j=1;j<=n;++j){
			dp[i][j]=0;
		}
	}
	for(int i=1;i<n;++i){
		for(int j=i+1;j<=n;++j){
			int id=max(bk[j],i);
			dp[i][j]=dp[i][id]+1;
		//	cout<<dp[i][j]<<' ';
		}
	//	cout<<'\n';
	}
	for(int i=1;i<=n;++i){
		memset(usd,0,sizeof(usd));
		dfs(i,0,i);
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(mp[{i,j}]==2){
				//cout<<i<<' '<<j<<'\n';
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		memset(bk,0,sizeof(bk));
		solve();
		mp.clear();
	}
	return 0;
}
