#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long

int const N=5e5+10;
int n,m,an[N],sum[N],ans;

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>an[i];
	sort(an+1,an+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+an[i];
	for(int i=1;i<=n;i++){
		int l=0,r=i+1;
		while(l+1<r){
			int mid=(l+r)/2;
			if(mid*an[i]-(sum[i]-sum[i-mid])<=m) l=mid;
			else r=mid;
		}
		ans=max(ans,l);
	}
	cout<<ans;
	return ;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
	return 0;
}

