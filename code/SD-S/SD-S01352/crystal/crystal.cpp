#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m;
int ans;
ll a[N],sum[N];
bool check(ll mid,ll pos){
	return (m>=a[pos]*(pos-mid+1)-sum[pos]+sum[mid-1]);
}
int main(void){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);  cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		int l=1,r=i-1,pos=1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(!check(mid,i)) l=mid+1;
			else r=mid-1,pos=mid;
		}
		ans=max(ans,i-pos+1);
	}
	cout<<ans<<'\n';
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
