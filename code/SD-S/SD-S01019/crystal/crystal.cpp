#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
int n,ans;
ll m,a[N],d[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
//	for(int i=1;i<=n;++i) d[i]=a[i]-a[i-1];
//	for(int i=n;i>=1;--i){
//		int l=0;
//		ll cost=0;
//		for(int j=i-l;j>=1;--j){
//			cost+=a[i]-a[j];
//			if(cost>m){
//				l=j;
//				break;
//			}
//		}
//		ans=max(ans,i-l);
//	}
//	cout<<ans;
	int l=1;
	ll s=0;
	for(int r=1;r<=n;++r){
		s+=a[r];
		while(a[r]*(r-l+1)-s>m) s-=a[l++];
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
