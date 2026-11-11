#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i<=b;i++)
#define ll long long
using namespace std;
ll a[500005];
ll n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	cin>>n>>m;
	For(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	ll l = 1,ans = -1,sum = 0;
	For(r,1,n){
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m){
			sum-=(a[r]-a[l]);
			l++;
		}
		ans = max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
