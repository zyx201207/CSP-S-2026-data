#include<bits/stdc++.h>
#define int long long
#define rep(i,a,n) for(int i=a; i<=n; i++)
#define dop(i,a,n) for(int i=n; i>=a; i--)
#define cios cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
using namespace std;
const int N=5e5+10;
int n,m,a[N],sum,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cios;
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1;a[0]=a[1];
	rep(i,1,n){
		sum+=(a[i]-a[i-1])*(i-l);
		while(l<i&&sum>m) sum-=(a[i]-a[l++]);
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}

