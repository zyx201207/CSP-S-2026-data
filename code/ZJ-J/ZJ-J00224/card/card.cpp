#include<bits/stdc++.h>
using namespace std;
const long long M=5e5+10;
long long n,m,a[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]>=m){
			printf("%lld ",m);
		}else{
			printf("%lld ",i);
		}
	}
	return 0;
}