#include<bits/stdc++.h>
using namespace std;
#define int long long
//int rp=0;
//rp+=INT_MAX;
//15:07ÇÐ 
int a[500010];
int pre[500010];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(i!=1)
		{
			pre[i]=pre[i-1]+(a[i]-a[i-1])*(i-1);
		}
		//cout<<pre[i]<<endl;
	}
//	if(n<=5000)
//	{
//		int maxn=1;
//		for(int i=1;i<=n;i++)
//		{
//			int cnt=1;
//			int sy=m;
//			for(int j=i-1;j>=1;j--)
//			{
//				if(sy-(a[i]-a[j])>=0)
//				{
//					sy-=(a[i]-a[j]);
//					cnt++;
//				}
//			}
//			maxn=max(maxn,cnt);
//		}
//		cout<<maxn;
//	}
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)/2;
		int flag=0;
		//cout<<mid<<endl;
		for(int i=mid;i<=n;i++)
		{
			int num=pre[i]-pre[i-mid+1]-(a[i]-a[i-mid+1])*(i-mid);
			//cout<<i<<" "<<num<<endl;
			if(num<=m)
			{
				flag++;
			//	break;
			}
		}
		//cout<<endl;
		if(flag)
		{
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	cout<<l-1;
	return 0;
}
