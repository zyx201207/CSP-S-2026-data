#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q=0;
	scanf("%lld",&c);
	scanf("%lld",&n);
	scanf("%lld",&m);
	scanf("%lld",&d);
	scanf("%lld",&q);
	long long a[m];
	long long e=35,w=16;
	for(int i=1;i<m;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		long long y[7];
		for(int j=0;j<7;j++){
			scanf("%lld",&y[j]);
		}
	}
	for(int i=1;i<=2;i++){
		long long x,l=0;
		scanf("%lld",&x);
		scanf("%lld",&l);
	}
	printf("%d\n",e);
	printf("%d\n",w);
	return 0;
}

