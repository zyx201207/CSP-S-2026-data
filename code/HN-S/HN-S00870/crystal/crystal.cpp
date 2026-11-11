#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,sum[500005],arr[500005],maxs;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+arr[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid,ans=-1;
		while(l<=r){
			mid=l+r>>1;
			if(arr[i]*(i-mid+1)-sum[i]+sum[mid-1]<=m){
				r=mid-1;
				ans=mid;
			}
			else{
				l=mid+1;
			}
		}
		maxs=max(maxs,i-ans+1);
	}
	cout<<maxs;
	return 0;
}
