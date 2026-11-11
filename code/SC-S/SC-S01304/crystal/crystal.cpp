#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll n,m;cin>>n>>m;
	vector<ll> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	ll sum = 0,ans = 0;
	for(ll l=0,r=0;r<n-1;){
		//尝试r往右移动一位
		r++;
		sum += (a[r]-a[r-1])*(r-l);//现在一共要消耗这么多的能量值
		while(sum>m){
			sum-=(a[r]-a[l]);
			l++;
		}
		ans = max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}