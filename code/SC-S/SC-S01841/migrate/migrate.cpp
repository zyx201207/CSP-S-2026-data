#include<bits/stdc++.h>
#define ll int64_t
#define endl '\n'
using namespace std;
ll c,t,n,d,x[5000+10],lst[5000+10],nxt[5000+10],dp[5000+10][2];
bool vis[5000+10][5000+10];
vector<pair<ll,ll>> vt;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++) for(ll j=1;j<=n;j++) vis[i][j]=false;
		for(ll i=1;i<=n;i++) nxt[i]=0,lst[i]=0;
		vt.clear();
		for(ll i=1;i<=n;i++) cin>>x[i];
		ll l=1,r=n;
		for(ll i=1;i<=n;i++){
			while(x[l]+d<x[i] && l<=i) l++;
			lst[i]=l;
		}
		for(ll i=n;i>=1;i--){
			while(x[r]-d>x[i] && r>=i) r--;
			nxt[i]=r;
		}
		for(ll i=n;i>=1;i--){
			for(ll j=i+3;j<=n;j++){
				if(nxt[i]<=lst[j]) break;
				if(nxt[i]-lst[j]==1) vis[i][j]=true,vt.push_back({i,j});
			}
		}
		ll ans=0;
		pair<ll,ll> lstt={0,0};
		for(auto v:vt){
			if(lstt.first==v.first || lstt.second==v.second){
				lstt=v;
				continue;
			}
			lstt=v;
			for(ll i=1;i<=v.first;i++){
				dp[i][0]=0;
				dp[i][1]=0;
				if(vis[i][nxt[v.first]] || vis[i][lst[v.second]]) continue;
				dp[i][0]=1;
				dp[i][1]=1;
				for(ll j=lst[i];j<i;j++) dp[i][0]=dp[j][0],dp[i][1]=dp[j][0]+dp[j][1];
			}
			for(ll i=n;i>=v.second;i--){
				dp[i][0]=1;
				dp[i][1]=1;
				if(vis[nxt[v.first]][i] || vis[lst[v.second]][i]) continue;
				for(ll j=nxt[i];j>i;j--) dp[i][0]=dp[j][0],dp[i][1]=dp[j][0]+dp[j][1];
			}
			ans+=dp[v.first][1]*dp[v.second][1];
		}
		cout<<ans<<endl;
	}
	return 0;
}