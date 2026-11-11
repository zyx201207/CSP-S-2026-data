#include<bits/stdc++.h>
using namespace std;
int n;
int cnt[200005];
char a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&cnt[i]);
		cin>>a[i];
	}
	long long ans=0;
	for(int l=1,r=n;l<r;)
	{
		if(a[l]==a[r])
		{
			if(cnt[l]>cnt[r])
			{
				cnt[l]-=cnt[r];
				cnt[r]=0;
				r--;
			}
			else if(cnt[l]<cnt[r])
			{
				cnt[r]-=cnt[l];
				cnt[l]=0;
				l++;
			}
			else
			{
				cnt[l]=0;
				cnt[r]=0;
				l++;
				r--;
			}
		}
		else
		{
			if(cnt[l]>cnt[r])
			{
				ans+=cnt[r];
				cnt[l]-=cnt[r];
				cnt[r]=0;
				r--;
			}
			else if(cnt[l]<cnt[r])
			{
				ans+=cnt[l];
				cnt[r]-=cnt[l];
				cnt[l]=0;
				l++;
			}
			else
			{
				ans+=cnt[r];
				cnt[r]=cnt[l]=0;
				l++;
				r--;
			}
		}
	}
	printf("%lld\n",ans);
}