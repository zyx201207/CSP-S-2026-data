#include <bits/stdc++.h>
#define prs " \n"
#define linf 0x3f3f3f3f3f3f3f3fll
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N=5e5+10;
int n,ans;
i64 m,a[N],sum[N];
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=2;i<=n;i++)
	{
//		i64 tm=m;
//		int j=i;
//		while(j>0&&tm>=(a[i]-a[j]))
//			tm-=(a[i]-a[j--]);
//		ans=max(ans,i-j);改二分
		//k=(a[i]*m)-(sum[i-1]-sum[i-m-1])
		//k随着m的增大而增大
		//对于m,k单调递增
		int l=1,r=i;
		while(l<r)
		{
			int mid=((l+r)>>1);
			i64 km=a[i]*(i-mid)*1ll-(sum[i-1]-sum[mid-1]);
			if(km>m) l=mid+1;
			else r=mid,ans=max(ans,i-mid+1);	
		}
	}
	cout<<ans;
	return 0;
}
/*
卑鄙我去吧，瞬间就爱上雷神 
Baby watchin' it burn,send death to ISOLATION!!
*/
