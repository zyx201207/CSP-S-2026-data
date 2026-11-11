#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+5;
ll n,m;
ll a[N];
ll pos;
unordered_map<ll,ll> ntol,lton;
ll far[N];
ll fara[N];
// ntol 值的离散位
// lton 离散位的原值
void init(){
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		ntol[a[i]] = ++pos;
		lton[pos] = a[i];
//		cnt[ntol[a[i]]] ++;
	}
	for(int i=1;i<=pos;i++){
		far[i] = lton[1] - lton[i];
		fara[i] = fara[i-1] + far[i];
	}
	return;
}
void solve(){
	ll ans = 0;
	for(int i=1;i<=n;i++){
//		for(int j=1;j<=i;j++){//现在是硬枚举，优化需要二分
//			if(fara[i]-fara[j-1]+abs(far[i])*(i-j+1)<=m){
//				ans = max(ans,i-j+1);
//			}
//		}
		ll l = 1,r=i;
		while(l<=r){
			ll mid = l+r>>1;
			if(fara[i]-fara[mid-1]+abs(far[i])*(i-mid+1)<=m){
				ans = max(ans,i-mid+1);
				r = mid-1;
			}else{
				l = mid+1;
			}
		}
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	init();
	solve();
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
