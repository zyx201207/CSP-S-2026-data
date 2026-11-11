#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long m,n;
long long a[N];
long long sum[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]+=sum[i-1]+a[i];
	}
	long long ans=0;
	for(long long i=1;i<=n;i++){
		long long l=0,r=i-1;
		while(l<r){
			int mid=(l+r)/2;
			//cout<<l<<" "<<mid<<" "<<r<<"\n";
			if(a[i]*(i-1-mid)-(sum[i-1]-sum[mid])<=m){
				r=mid;
			}
			else l=mid+1;
		}
		ans=max(i-r,ans);
	}cout<<ans;
	return 0;
} 