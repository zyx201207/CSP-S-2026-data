#include<bits/stdc++.h>
using namespace std;
long long t,n,d,a[2000100],dt,l;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//-------------------------
	scanf("%lld",&t);
	scanf("%lld",&t);
	for(int ti=1;ti<=t;ti++){
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		dt=a[2]-a[1];
		if(d<dt*2){
			printf("0\n");
			continue;
		}
		l=d/dt;
		l=l*2-1;
		long long z=0;
		printf("%lld\n",max(n-l,z));
	}
	//-------------------------
	fclose(stdin);
	fclose(stdout);
	return 0;
}
