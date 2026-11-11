#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[510000],sum[510000];
int main(){
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	int ans = 1;
	for(int i = 1 ; i <= n ; i++){
		sum[i] = sum[i-1]+(i-1)*(a[i]-a[i-1]);
		int l = 1,r = i,mid;
		while(l<=r){
			mid = (l+r)/2;
			if(sum[i]-sum[mid]-(a[i]-a[mid-1])*(mid-1)>m) l = mid+1;
			else r = mid-1;
		}
		ans = max(ans,i-l+1);
	}
	cout << ans;
	return 0;
}
