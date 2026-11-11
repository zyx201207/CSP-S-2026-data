#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,n,d,a[N],dd,x;
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			
		}
		if(d<a[2]-a[1]){
			printf("0");
			cout<<'a';
		}
		else{
			x=d/(a[2]-a[1]);
			x*=2;
			printf("%lld\n",(n-x+1)>=0? n-x+1:0);
		}
	}
}
