#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+15,D=1e12;

int a[N];
int n,m;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		a[i]+=D;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		a[i]+=a[i-1];
	}
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		int l=1,r=i;
		int k=a[i]-a[i-1];
		while(l<r)
		{
			int mid=l+r>>1;
			if(k*(i-mid+1)-(a[i]-a[mid-1])<=m)r=mid;
			else l=mid+1;
		}
//		cout<<i-l+1<<"\n";
		ans=max(ans,i-l+1);
	}
	printf("%lld\n",ans);
	return 0;	
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/