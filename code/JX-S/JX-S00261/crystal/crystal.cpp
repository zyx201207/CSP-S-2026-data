#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5;
int n,m,a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int ans = 1;
	for(int i = 1;i<=n;i++){
		sum[i] = sum[i-1]+a[i];
		int l = 1ll,r = i-1,id = -1;
		while(l<=r){
			int mid = (l+r)>>1;
			int cnt = (sum[i-1]-sum[mid-1]),len = (i-1-mid+1);
			if(a[i]*len-cnt<=m) r = mid-1,id = mid;
			else l = mid+1;
		}
		if(id==-1) continue;
		ans = max(ans,i-id+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
