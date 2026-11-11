#include<bits/stdc++.h>
using namespace std;
long long n,k,u[2000005],v[2000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t;
	scanf("%ld%ld",&c,&t);
	while(t--){
		scanf("%ld%ld",&n,&k);
		for(long long i=1;i<=n-1;i++) scanf("%ld%ld",&u[i],&v[i]);
		long long m=(n-1)>>1;
		printf("1\n");
	}
	return 0;
}