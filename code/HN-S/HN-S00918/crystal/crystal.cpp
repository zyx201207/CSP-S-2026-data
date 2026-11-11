#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],sum[500005];
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
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=0,r=i+1;
		while(l+1<r){
			int mid=l+r>>1;
			if((i-mid)*a[i]-(sum[i-1]-sum[mid-1])<=m){
				r=mid;
			}else{
				l=mid;
			}
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans; 
	return 0;
} 
