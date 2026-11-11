#include<cstdio>
const int maxn=200005;
int a[maxn];
char s[maxn][5];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sn=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%s",&a[i],&s[i][1]),sn+=a[i];
	long long c=0;
	if(sn%2) for(int i=1;i<=n;i++){
		c+=a[i];
		if(c>=(sn+1)/2){
			a[i]--;
			break;
		}
	}
	long long ans=0;
	for(int i=1,j=n;i<j;){
		if(s[i][1]==s[j][1]){
			if(a[i]==a[j]) i++,j--;
			else if(a[i]>a[j]) a[i]-=a[j],j--;
			else a[j]-=a[i],i++;
		}else{
			//printf("a[%d]=%d,a[%d]=%d\n",i,a[i],j,a[j]);
			if(a[i]==a[j]) ans+=a[i],i++,j--;
			else if(a[i]>a[j]) ans+=a[j],a[i]-=a[j],j--;
			else ans+=a[i],a[j]-=a[i],i++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
