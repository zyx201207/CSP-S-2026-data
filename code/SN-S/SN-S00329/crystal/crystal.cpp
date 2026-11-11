#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
//#define mod 998244353
#define INF 1'000'000'000'000'000'000
#define bcstr basic_string
#define i128 __int128
using namespace std;
int n,m;
int a[500005];
int sum[500005];
int lower_bound_(int l,int r,int x){
	int res=r;
	while(l<=r){
		int mid=(l+r)/2;
		if((x-mid+1)*a[x]-(sum[mid]-sum[x+1])<=m) res=mid,r=mid-1;
		else l=mid+1;
	}
	return res;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=n;i>0;i--) sum[i]=sum[i+1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int pos=lower_bound_(1,i,i);
		ans=max(ans,i-pos+1);
	}
	cout<<ans;
	return 0;
}
