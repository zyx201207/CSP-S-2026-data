#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[500005]={},h[500005]={},m;
int main()
{/**/
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin>>n>>m;
	long long now121;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&now121);
		a[i]=now121;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		h[i]=h[i-1]+a[i];
	}
	int ans=0,l=0,r,mid;
	for(int i=1;i<=n;i++)
	{
		r=i;
		while(r>=l)
		{
			mid=(l+r)/2;
			if((i-mid)*a[i]-(h[i-1]-h[mid-1])<=m)
			{
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		//cout<<i<<' '<<l<<' '<<r<<endl;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
