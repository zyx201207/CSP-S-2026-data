#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,m;
int a[500005];
int sum[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	sum[0]=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
//	for(int i=1;i<=n;i++){
//		cout<<sum[i]<<" ";
//	}
//	cout<<'\n';
	int ans=1;
	for(int i=2;i<=n;i++){
		int l=1,r=i-1,res=0;
		while(l<=r){
			int mid=(l+r)/2;
//			cout<<i<<":"<<l<<" "<<r<<" "<<mid<<" "<<mid*a[i]<<" "<<sum[i-1]-sum[i-mid]<<'\n';
			if(mid*a[i]-sum[i-1]+sum[i-mid-1]<=m){
				l=mid+1;
				res=mid;
			}
			else{
			    r=mid-1;
			}
		}
		ans=max(ans,res+1);
	}
	cout<<ans<<'\n'; 
	return 0;
}
/*
5 5 
1 2 4 8 9
*/
/*
5 8
-3 -1 2 2 7
*/
