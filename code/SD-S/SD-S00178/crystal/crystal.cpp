#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
int sum[N],sum2[N],sum3[N];
int ans=0;
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
		sum2[i]=sum2[i-1]+a[i]-a[i-1];
		sum3[i]=sum3[i-1]+sum2[i];
	}
	for(int i=n;i>=1;i--){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(sum[i]-(mid-1)*(a[i]-a[1])+sum3[mid]<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
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
