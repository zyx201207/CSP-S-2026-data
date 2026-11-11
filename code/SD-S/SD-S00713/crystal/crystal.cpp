/*
走了那么久，难道又回头吗 ——《依·抱》
All for myself, not anyone else.
*/
/*
sorta，看差多少 
枚举a，要把高度持平到哪个位置
直接二分看要用多少次
2nlogn解决，5e5足够 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define TERRY_MC
#define endl '\n'
const int N=5e5+10;
ll n,a[N],m,sum[N];
int main() {
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#ifndef TERRY_MC
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
#endif
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	ll ans=1;
	for(int i=1;i<=n;i++) {
		sum[i]=sum[i-1]+a[i];
		ll l=1,r=i,answ=i+1,mid;
		while(l<=r) {
			mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m) {
				r=mid-1;
				answ=mid;
			}
			else l=mid+1;
		}
		ans=max(ans,i-answ+1);
	}
	cout<<ans<<endl;
	return 0;
}
//fin.

