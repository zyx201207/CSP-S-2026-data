#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
long long m,a[500001],b[500000];
int n,sum,ans;
int main(){
	scanf("%d",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++){
		b[i]=abs(a[i]-a[i+1]);
	}
	for(int i=1;i<=n-1;i++){
		if(ans+b[i]<m){
			ans+=b[i];
			sum++;
		}else{
			break;
		}
	}
	printf("%d",sum);
	return 0;
}
