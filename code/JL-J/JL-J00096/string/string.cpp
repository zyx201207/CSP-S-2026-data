#include <cstdio>
long long n,a[200010],t,len,ans,flag;
char c[200010],k[100000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld %s",&a[i],&c[i]);
		len+=a[i];
		if(len>100000000){
			flag=1;
		}
		if(!flag){
			for(long long x=1;x<=a[i];x++){
				k[++t]=c[i];
			}
		}
	}
	if(flag){
		printf("%lld",len/2);
		return 0;
	}
	for(long long i=1,j=len;i<=j;i++,j--){
		if(k[i]!=k[j]){
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
