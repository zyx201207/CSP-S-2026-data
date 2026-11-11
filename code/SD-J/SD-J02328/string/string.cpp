#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[200005],k,l,r;long long ans;char c[200005];
int main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	scanf("%d",&n);k=n,l=0,r=n-1;
	for(int i=0;i<n;i++)scanf("%d %c",&a[i],&c[i]);
	while(l<r){
		if(c[l]!=c[r])ans+=min(a[l],a[r]);
		if(a[l]>a[r])a[l]-=a[r],r--;
		else if(a[l]<a[r])a[r]-=a[l],l++;
		else r--,l++;
	}
	printf("%lld",ans);
	return 0;
}

