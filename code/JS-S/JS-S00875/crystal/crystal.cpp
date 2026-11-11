#include<stdio.h>
#include<algorithm>

using namespace std;

int n,ans;
long long m,a[500005];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%lld",&n,&m);

	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);

	sort(a+1,a+n+1);

	int l=1,r=0;
	long long s=0;

	for(r=1;r<=n;r++){
		s+=(a[r]-a[r-1])*(r-l);

		while(s>m)
			s-=(a[r]-a[l++]);

		ans=max(ans,r-l+1);
	}

	printf("%d\n",ans);

	return 0;
}