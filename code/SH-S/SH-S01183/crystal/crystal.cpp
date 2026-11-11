#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],p[500010],ans,mn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mn=max(mn,abs(a[i]));
	}
	sort(a+1,a+n+1);
	if(mn<=100){
		for(long long i=-mn;i<=mn;i++){
			long long need=0;
			long long st=upper_bound(a+1,a+n+1,i)-(a+1);
			for(long long j=st;j>=1;j--){
				need+=i-a[j];
				if(need>m){
					ans=max(ans,st-j);
					break;
				}
				if(j==1){
					ans=max(ans,st);
				}
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		long long need=0;
		for(long long j=i;j>=1;j--){
			need+=a[i]-a[j];
			if(need>m){
				ans=max(i-j,ans);
				break;
			}
			if(j==1)ans=max(ans,i-j+1);
		}
	}
	cout<<ans;
	return 0;
}
