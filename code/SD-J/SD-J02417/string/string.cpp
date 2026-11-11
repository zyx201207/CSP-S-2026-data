#include<iostream> 
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
LL a[300010];
char c[300010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
 	int n,np;
 	scanf("%d",&n);np=n;
    for(int i=1;i<=n;i++)
 	scanf("%lld %c",&a[i],&c[i]);
 	   int sf=1,en=n;
 	   LL ans=0;
    while(sf<en){
 		if(c[sf]==c[en]){
 			if(a[sf]>a[en]){
 				a[sf]-=a[en];
 				en--;
 				np--;
			}
 			else if(a[sf]==a[en]){
 				sf++;en--;
				np-=2;
			}
 			else if(a[sf]<a[en]){
 				a[en]-=a[sf];
 				sf++;
 				np--;
			}
		}
		else{
			if(a[sf]>a[en]){
				ans+=a[en];
 				a[sf]-=a[en];
 				en--;
 				np--;
			}
 			else if(a[sf]==a[en]){
 				ans+=a[sf];
 				sf++;en--;
				np-=2;
			}
 			else if(a[sf]<a[en]){
 				ans+=a[sf];
 				a[en]-=a[sf];
 				sf++;
 				np--;
			}
		}
	}
 	printf("%lld",ans);
	
	return 0;
}
