#include<bits/stdc++.h>
using namespace std;
long long t,n,m,cnt,mx=1;
long long a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
//	t=1;
//	cin>>t;
//	while(t--){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
//		cnt=1;
		int l=1,r=i-1;
		while(l<r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		mx=max(mx,(long long)i-(long long)l+1);
//		cout<<l<<' '<<i<<'\n';
	} 
	cout<<mx;
//	}
	return 0;
} 


