#include<bits/stdc++.h>
using namespace std;
long long a[200001];
int main(){
		freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,sum=0;
	scanf("%lld%lld",&n,&m);
	

	for(long long i=0;i<n;i++){
		scanf("%lld",&a[i]);
		
	}
	sort(a,a+n);
	sum=a[n-1];

	for(long long i=1;i<m;i++){
		
		sum&=a[n-1-i];
	}

	printf("%lld",sum);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}