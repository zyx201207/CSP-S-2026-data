#include<bits/stdc++.h>
using namespace std;

long long c,t;
long long x[2000000];
long long n,d,ans;
bool b;

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(long long i=1; i<=t; i++) {
		scanf("%lld%lld",&n,&d);
		for(int j=1; j<=n; j++) {
			scanf("%lld",&x[j]);
		}
		b=false;
		if(c>=11&&c<=12){
			if(x[2]-x[1]>d||n<=3){
				printf("%lld\n",0);
			}else{
				for(long long j=4;x[j]-x[j]<2*d&&j<=n;j+=2){
					if(x[j/2+1]-x[1]<=d&&x[j/2+2]-x[1]>d){
						printf("%lld\n",n-j+1);
						b=true;
						break;
					}
				}
				if(!b){
					printf("%lld\n",0);
				}
			}
		}

	}
	return 0;
}
//提交前把freopen注释去掉！！！
