#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long k=m,sum=0;
		for(int j=i;j>=1;j--){
			if(a[i]-a[j]<=k){
				sum++;
				k-=(a[i]-a[j]);
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}