#include<bits/stdc++.h>
using namespace std;
long long int c,t;
long long int a[2000050];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		long long int n,d;
		scanf("%lld%lld",&n,&d);
		for(long long int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		long long int cha=a[2]-a[1];
		long long int summax=d/cha;
		long long int sum=0;
		if(d<=cha){
			printf("0\n");
		}
		else{
			if(summax>=2){
				long long int flag=1;
				while(2+flag*summax<=a[n]){
					sum+=(n-1-flag*summax);
					flag++;
				}
				printf("%lld",sum);
			}
			if(summax<2){
				printf("0\n");
			}
		}
		memset(a,0,sizeof(a));
	}
	return 0;
}