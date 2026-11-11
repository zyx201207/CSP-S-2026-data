#include<bits/stdc++.h>
using namespace std;
#define int long long
int ls[2000002];
signed main(){
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
		while (t--){
			int n,d;
			scanf("%lld%lld",&n,&d);
			for (int i=1;i<=n;i++){
				scanf("%lld",&ls[i]);
			}
			int num=d/(ls[2]-ls[1]);
			if (num==1||num==0){
				printf("0\n");
				continue;
			}
			int ans=0;
			if (n-(2*num-1)>0){
				ans=n-(2*num-1);
			}
			printf("%lld\n",ans);
		}
	return 0;
}
