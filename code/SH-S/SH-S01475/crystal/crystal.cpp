#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		long long k=m,z=0;
		for(long long j=i;j>=1;j--){
			if(k>=a[i]-a[j]){
				z++;
				k-=(a[i]-a[j]);
			}
			else{
				break;
			}
		}
		ans=max(ans,z);
	}
	cout<<ans;
	return 0;
} 
