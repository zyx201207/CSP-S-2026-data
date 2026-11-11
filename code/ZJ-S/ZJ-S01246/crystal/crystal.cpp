#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+100;
int n,m;
int a[N],b[N];
//bool check(int u)
//{
//	if(b[u])
//}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=1;
	for(int i=n;i>=1;i--)
	{
		int cnt=0;
		bool ok=true;
		for(int j=1;j<=i;j++)
		{
			cnt+=(a[i]-a[j]);
			if(cnt>m)
			{
				ok=false;
				break;
			}
		} 
		if(ok)
		{
			ans=i;
			break;
		} 
	}
	cout<<ans;
//	for(int i=n;i>=1;i--)
//	{
//		b[i]=b[i+1]+a[n]-a[i];
//	}
//	for(int i=1;i<=n;i++)
//	{
//		int l=1,r=i;
//		int mid=(l+r)/2;
//		while(l<r)
//		{
//			if(check(mid,i))
//			{
//				r=mid;
//			}
//			else
//			{
//				l=mid+1;
//			}
//		}
//		ans=max(ans,i-l+1);
//	}
	
	return 0;
} 
