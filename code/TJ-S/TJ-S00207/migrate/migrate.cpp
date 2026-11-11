#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int const N=2000010;
int c,t;
int n;
ll d,a[N],res;
bool f[N],g[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf("%d %d",&c,&t);
	if (c==11 || c==12){
		ll h;
		for (int x=1;x<=t;x++){
			scanf("%d %lld",&n,&d);
			for (int i=1;i<=n;i++){
				scanf("%lld",&a[i]);
			}
			h=a[2]-a[1];
			if (d<2*h || d>=3*h){
				printf("0\n");
			}
			else if (n<=3){
				printf("0\n");
			}
			else{
				printf("%d\n",n-3);
			}
		}
	}
	else{
		for (int x=1;x<=t;x++){
			res=0;
			scanf("%d %lld",&n,&d);
			for (int i=1;i<=n;i++){
				scanf("%lld",&a[i]);
			}
			if (n<4){
				printf("0\n");
				continue;
			}
			for (int i=1;i+3<=n;i++){
				if (a[i+1]-a[i]<=d && a[i+2]-a[i]<=d && a[i+3]-a[i+1]<=d && a[i+3]-a[i+2]<=d && a[i+3]-a[i]>d){
					f[i]=1,res++;
				}
			}
			for (int k=4;k<n;k++){
				for (int i=1;i+k<=n;i++){
					if (f[i] && f[i+1]){
						if ((a[i+1]-a[i]<=d && a[i+k]-a[i+k-1]>d) ||
							(a[i+1]-a[i]>d && a[i+k]-a[i+k-1]<=d)){
							g[i]=1,res++;
						}
					}
				}
				for (int i=1;i+k<=n;i++) f[i]=g[i];
			}
			printf("%lld\n",res);
		}
	}
	
	return 0;
}

