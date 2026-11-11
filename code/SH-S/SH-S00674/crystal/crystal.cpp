#include<stdio.h>
#include<algorithm>
int n;
long long m;
long long a[1<<20];
int cnt,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",a+i);
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
		a[i]+=a[i-1];
	for(int i=1;i<=n;++i){
		int l=1,r=i;
		while(l<r){
			int mid=l+((r-l)>>1);
			cnt=i-mid+1;
			long long sum=a[i]-a[mid-1];
			long long to_add=(a[i]-a[i-1])*cnt-sum;
			if(m>=to_add)
				r=mid;
			else
				l=mid+1;
		}
		cnt=i-l+1;
		if(ans<cnt)
			ans=cnt;
	}
	printf("%d\n",ans);
	return 0;
} 
