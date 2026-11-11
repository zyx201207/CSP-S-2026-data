#include<bits/stdc++.h>
using namespace std;
long long n,m,a[550000],k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(k>m-(a[i]-a[i-1])*(i-1)){
			printf("%lld",i-1);
			break;
		}
		k=k+(a[i]-a[i-1])*(i-1);
	}
	return 0;
}
