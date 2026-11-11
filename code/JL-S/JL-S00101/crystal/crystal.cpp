#include<bits/stdc++.h>
using namespace std;
long long a[5000010];
long long b[5000010]={9999999999999};
long long c[5000010]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n<=5000){
		long long h=ceil(1.0*n/2);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			b[i]=a[h]-a[i];
		}
		sort(b+1,b+h+1);
		int sum=0;
		for(int i=1;i<=n;i++){
			if(m>=b[i]&&b[i]>=0){
				m-=b[i];
				sum++;
			}
		}
		cout<<sum;
	}else{
		for(int i=n;i>=1;i--){
			b[n-i+1]=a[n]-a[i];
			c[n-i+1]+=c[n-i]+b[n-i+1];
		}
		for(int i=1;i<=n;i++){
			if(m<c[i]){
				cout<<i-1;
				break;
			}
		}
	}
	return 0;
}
