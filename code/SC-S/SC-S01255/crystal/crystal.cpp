#include<algorithm>
#include<iostream>
#define ll long long
const int N=500005;
using namespace std;
int n,ans;
ll m;
ll a[N],sum[N];

inline void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
	int l=1;
	for(int i=1;i<=n;++i){
		while(a[i]*1ll*(i-l+1)-(sum[i]-sum[l-1])>m)l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;	
}
/*
5 5
1 2 4 8 9
*/
/*
 从 二分 过渡到 前缀和
在 3:06 P.M. 做出
话说这个键盘好像有问题
敲得我好难受
反正大样例过了 
*/
//inline bool check(int loc){
//	ll cnt=0;
//	int l=1;
//	while(a[l]<=a[loc]&&l<n){
//		l++;
//		cnt+=a[loc]-a[l];
//	}
//	return cnt<=m;
//}

//inline void solve(){
//	cin>>n>>m;
//	for(int i=1;i<=n;++i)cin>>a[i];
//	sort(a+1,a+n+1);
//	int l=1,r=n;
//	while(l<r){
//		int mid=(l+r+1)>>1;
//		if(check(mid))l=mid;
//		else r=mid-1;
////		cout<<l<<" "<<r<<" "<<mid<<"\n";
//	}
//	int ans=0;
//	while(a[ans+1]<=a[l]&&ans+1<=n)ans++;
//	cout<<ans<<"\n";
//	return ;
//}