#include<bits/stdc++.h>
using namespace std;
long long n,m;

long long a[500005],dp[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f=1;
	long long ca=0;
	cin>>a[0]>>a[1];
	ca=a[1]-a[0];
	for(long long i=2;i<n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=ca)f=0;
	}
	if(f){
		long long ans=0,tm=0;
		for(long long i=1;i<=n;i++){
			if(tm+i*ca<=m){
				ans++;
				tm+=i*ca;
			}
		}		
		cout<<ans;
	}
	else{
		
		sort(a,a+n);
		long long ma=-1;
		for(int long long i=n-1;i>=0;i--){
			long long k=a[i],c2=0,cnt=0;
			for(long long j=i;j>=0;j--){
				if(cnt+(k-a[j])<=m){
					cnt+=k-a[j];
					c2++;
				}
				else{
					break;
				}
			}
			ma=max(ma,c2);
		}
		cout<<ma;
		
	}	
	
	return 0;
}

