#include<bits/stdc++.h>
using namespace std;
const int N=2e6+100;
long long x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	long long n,d;
	while(T--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		if(c==11||c==12){
			if(d<(2*(x[2]-x[1]))){
				printf("%d\n",0);
				continue;
			}
			int t=d/(2*(x[2]-x[1]));
			t*=2;
			t--;
			printf("%d\n",n-t+1);
		}
		else{
			printf("0\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}