#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;

#define ll long long
ll n,m,sum[N],a[N];
ll getsum(int l,int r){
	return sum[r] - sum[l-1];
}
int check(int l,int r){
	// a[l] a[l+1] a[l+1] …… a[r-1] a[r] 
	ll s = getsum(l,r-1); // 前面的和 
	return 1ll*a[r]*(r-l) - s;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i] = sum[i-1] + a[i];
	int ans = 0;
	for(int i=1;i<=n;i++){
		int l = i, r = n;
		while(l < r){
			int mid = (l+r+1) / 2;
			//cout<<i<<" "<<mid<<" "<<check(i,mid)<<"\n";
			if(check(i,mid) <= m)l = mid;
			else r = mid-1;
		}
		ans = max(ans,r-i+1);
	}
	cout<<ans;
	return 0;
}/*
5 8
-3 -1 2 2 7

*/
