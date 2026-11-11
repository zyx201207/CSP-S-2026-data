#include <cstdio>
const int MAXN=2*100009;
int a[MAXN];
char str[MAXN];
//char s[MAXN*509];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%s",&a[i],&str[i]);
	}
	long long ans=0;
	for(int i=1,j=n;i<j;){
		if(str[i]==str[j]){
			if(a[i]<a[j]){
				i++;
				a[j]-=a[i];
			}else if(a[i]==a[j]){
				i++,j--;
			} else{
				j--;
				a[i]-=a[j];
			}
		}else{
			if(a[i]<a[j]){
				i++;
				a[j]-=a[i];
				ans+=a[i];
			}else if(a[i]==a[j]){
				i++,j--;
				ans+=a[i];
			} else{
				j--;
				a[i]-=a[j];
				ans+=a[j];
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
//Trick||Treat!
