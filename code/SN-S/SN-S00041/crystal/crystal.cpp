#include<bits/stdc++.h>
using namespace std;
long long a[500001],ans[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=1;i<n;i++){
		long long z=m;
		for(long long j=i-1;j>=0;j--){
			if(z-a[i]+a[j]>=0){
				z=z-a[i]+a[j];
				ans[i]++;
			}else{
				break;
			}
		}
	}
	sort(ans,ans+n);
	cout<<ans[n-1]+1;
	return 0;
}
