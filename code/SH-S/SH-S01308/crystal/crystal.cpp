#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[500005];
long long sum[500005];
long long ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	bool flag=true;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		if(i>=3){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2])flag=false;
		}
	}
	if(flag){
		cout<<m/(2*(a[2]-a[1]));
		return 0;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i+ans;j<=n;j++){
			if(m>=(j-i+1)*a[j]-sum[j]+sum[i-1]){
				ans=max(ans,j-i+1);
			}else{
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}  
