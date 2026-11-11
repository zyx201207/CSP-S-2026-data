#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long ans=0;
	long long check1=0;
	long long check2=0;
	long long n,m;
	cin>>n>>m;
	long long a[500005];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	check1=a[2]-a[1];
		for(long long i=2;i<=n;i++){
		if(a[i]-a[i-1]!=check1){
			check2=1;break;
		}
	} 
	if(check2==0){ans++;
		for(long long i=1;i>0;i++){
			if(m<i*check1){
		break;
			}
			ans++;m-=i*check1;
		}
		ans=min(n,ans);
	}
	else{
		for(long long i=1;i<=n;i++){long long ans1=1;long long p=m;
		for(long long j=i-1;j>=1;j--){
			if(p>=a[i]-a[j]){
				ans1++;p-=(a[i]-a[j]);
			} 
			else break;
		}
		ans=max(ans,ans1);
	}}
	cout<<ans;
	return 0;
}
