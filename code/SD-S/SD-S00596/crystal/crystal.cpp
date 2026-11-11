#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+10;
const int INF=2e17;
const int MOD=1e9+7;
const int MX=1e12;
int n,m,a[N],sum[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=MX;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(int l=1,r=1;r<=n;r++){
		while((r-l+1)*a[r]-(sum[r]-sum[l-1])>m){
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
}
signed main(){
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	
	return 0;
}

