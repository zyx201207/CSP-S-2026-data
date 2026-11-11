#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);


	long long c,t;

	scanf("%lld %lld",&c,&t);
	
	for(int u = 0;u < t;u ++){
		long long n,d;scanf("%lld %lld",&n,&d);
		long long lst = 0;
		long long p;
		for(int i = 0;i < n;i ++){
			long long q;
			scanf("%lld",&q);
			if(i==0)lst = q;
			else if(i == 1)p = q-lst;
		}

		//printf("p:%lld,d%lld,1:%lld,2:%lld\n",p,d,x[n-1],x[n-2]);
		if(p == 0 || d <= p){
			printf("0\n");
			continue;
		}
		long long w = d / p;
		long long ans = max((long long)0,n-(w*2)+1);
		printf("%lld\n",ans);
	}

	return 0;
}