#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
const double eps=1e-6;
int n,a[N],m,dp[N],ans,b[N],cnt;
vector<int> g[40];
map<int,int> mp;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int x=a[i];
		cnt=0;
		while(x>0){
			b[++cnt]=x%2;
			if(x&1)g[cnt].pb(i);
			x/=2;
		}
	}cnt=0;
	for(int i=31;i>=1;i--){
		if((int)g[i].size()<m)continue;
		int tot=0;
		for(int j=0;j<(int)g[i].size();j++){
			int x=g[i][j];
			if(mp[x]==cnt)tot++;
		}
		if(tot<m)continue;
		for(int j=0;j<(int)g[i].size();j++){
			int x=g[i][j];
			if(mp[x]==cnt)mp[x]++;
		}
		cnt++;
		ans+=(1ll<<i-1);
	}
	cout<<ans<<'\n';
}
signed main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}

