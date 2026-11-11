#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,ans;
ll m;
ll a[N];
ll sum[N];
bool check(int L,int R,ll x){
	int len=R-L+1;
	if(len*x-(sum[R]-sum[L-1])>m) return false;
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]) continue;
		ll x=a[i];
		int l=1,r=i;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid,i,x)){
				r=mid-1;
				ans=max(ans,i-mid+1);
//				cout<<i<<' '<<mid<<'\n';
			}else{
				l=mid+1;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
