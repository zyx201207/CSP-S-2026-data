#include<cstdio>
#include<cstring>
const int MAXN=200005;
int a[MAXN];
char h[MAXN];
long long s[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%s",&a[i],&h[i]);
	for(int i=1;i<=n;i++)s[i]=a[i]+s[i-1];
	long long sum=0;
	for(int i=1;i<=n;i++)sum+=a[i];
	long long ans=0;
	for(long long i=1,j=sum;i<=j;i++,j--){
		int sign=0;
		for(int k=1;k<=n;k++){
			if(s[k]>=i){
				sign=k;
				break;
			}
		}
		int sign2=0;
		for(int k=1;k<=n;k++){
			if(s[k]>=j){
				sign2=k;
				break;
			}
		}
		if(h[sign]!=h[sign2])ans++;
	}
	printf("%lld\n",ans);
	return 0;
}
