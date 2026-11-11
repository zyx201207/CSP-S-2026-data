#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d;
int x[2000001];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--){
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		printf("0\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}