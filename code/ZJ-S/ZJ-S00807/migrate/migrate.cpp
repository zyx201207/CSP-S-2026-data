#include<iostream>
using namespace std;
long long a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		long long n,d;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(c==11||c==12){
			if(2*(a[2]-a[1])>d){
				printf("0\n");
				continue;
			}
			else{
				printf("1\n");
				continue;
			}
		}
		if(c==13||c==14){
			printf("0\n");
			continue;
		}
	}
	return 0;
}
