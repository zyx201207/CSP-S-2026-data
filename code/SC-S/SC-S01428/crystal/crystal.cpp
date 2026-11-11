//可以明显发现，明显是一个原题（虽然忘了是哪道但这个题太经典了） 考虑二分+贪心 还需要前缀和辅助
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+100;
#define ll long long
ll n,m,a[N],ans,b[N];
bool check(int x){
	ll used=0;
	for(int i=1;i<=n-x;i++){
		used=b[i+x-1]-b[i-1]+x*a[i+x-1];
		if(used<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]-a[i];
	}
	ll l=1,r=n+1;
	while(l<=r){
		ll mid=l+((r-l)>>1);
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}