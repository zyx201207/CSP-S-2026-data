#include<cstdio>
#define ll long long
int c,t;
ll n,d,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	++t;
	while(--t){
		scanf("%lld%lld",&n,&d);
		for(int i=0;i<n;++i){
			scanf("%lld",&a[i]);
		}
		if(d<2*(a[1]-a[0]))printf("0\n");
		else if(n-2*d/(a[1]-a[0])+1<0)printf("0\n");
		else printf("%lld\n",(n-2*d/(a[1]-a[0])+1));
	}
	return 0;
}
