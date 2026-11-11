#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long n;
long long m,a[N],sum[N],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		int res=i;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-m<=sum[i]-sum[mid-1]) res=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,(long long)i-res+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
