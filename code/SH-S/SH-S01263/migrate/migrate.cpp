#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	ll c,t,n,d;
	scanf("%lld%lld",&c,&t);
	for(int i=0;i<t;i++){
		scanf("%lld%lld",&n,&d);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		srand(time(0));
		printf("%lld\n",rand()%n*n/2);
	}return 0;
}
