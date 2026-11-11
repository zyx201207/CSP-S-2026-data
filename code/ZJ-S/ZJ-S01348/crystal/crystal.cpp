#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500009];
long long b[500009];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long k=m;
		if(a[i]==a[i-1]){
			b[i]=b[i-1]+1;
		}else{
			for(int j=i;j>=1;j--){
				if(a[i]-a[j]<=k){
					b[i]++;
					k-=(a[i]-a[j]);
				}
			}
		}
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		sum=max(sum,b[i]);
	}
	printf("%lld",sum);
	return 0;
}
