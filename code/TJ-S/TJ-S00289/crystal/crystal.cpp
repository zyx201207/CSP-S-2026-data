#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
ll n,m,a[N],s[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++){
		s[i] = s[i-1]+a[i];
		ll res = 1,l = 1,r = i;
		while(l<=r){
			ll mid = (l+r)>>1;
			if(a[i]*(ll)(i-mid+1)-(s[i]-s[mid-1])<=m) res = i-mid+1,r = mid-1;
			else l = mid+1;
		}
		ans = max(ans,res);
	}
	cout<<ans;
	return 0;
}
