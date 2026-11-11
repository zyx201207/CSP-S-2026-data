#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,ma;
long long a[N],s[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.ont","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=l+r>>1;
			if(s[i]-s[mid-1]+m>=a[i]*(i-mid+1)) r=mid;
			else l=mid+1;
		}
		ma=max(ma,(i-l+1));
	}
	printf("%d\n",ma);
	return 0;
} 
