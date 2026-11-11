//#include<bits/stdc++.h>
//using namespace std;
//const int N=5e5+10;
//long long a[N];
//int n;
//long long m,ans=1;
//int main()
//{
//	freopen("crystal4.in","r",stdin);
//	//freopen("crystal.out","w",stdout);
//	cin>>n>>m;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>a[i];
//	}
//	sort(a+1,a+n+1);
//	long long l=1,r=n,b=m;
//	while(l<=r)
//	{
//		b=m;
//		long long maxn=0;
//		long long mid=(l+r)/2;
//		for(int i=mid;i>=1;i--)
//		{
//			b=b-(a[mid]-a[i]);
//			if(b>=0)
//			{
//				maxn++;
//			}
//			else	break;
//		}
//		if(ans<maxn)
//		{
//			ans=maxn;
//		}
//		if(b>=0)
//		{
//			l=mid+1;
//		}
//		else
//		{
//			r=mid-1;
//		}
//	}
//	cout<<ans;
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
int n;
long long m,ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,r=n,b=m;
	while(l<=r)
	{
		b=m;
		long long maxn=1;
		long long mid=(l+r)/2;
		int i=mid-1;
		while(b>=0&&mid<=r&&i>=1)
		{
			if(a[mid+1]>=a[mid])
			{
				if(a[mid]-a[i]<=(a[mid+1]-a[mid])*maxn)
				{
					b=b-(a[mid]-a[i]);
					i--;
				}
				else
				{
					b=b-(a[mid+1]-a[mid])*maxn;
					mid++;
				}
			}
			else
			{
				b=b-(a[mid]-a[i]);
				i--;
			}
			if(b>=0)
			{
				maxn++;
			}
			else	break;
		}
		if(ans<maxn)
		{
			ans=maxn;
		}
		if(b>=0)
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
