#include<bits/stdc++.h>
using namespace std;
char s[200005];
int n;
long long a[200005],cnt=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %c",&a[i],&s[i]);
	}
	int l=1,r=n;
	while(l<r)
	{
		if(s[l]==s[r])
		{
			if(a[l]==a[r])
			{
				l++;
				r--;
			}
			else if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else
			{
				a[r]-=a[l];
				l++;
			}
		}
		else
		{
			if(a[l]==a[r])
			{
				cnt+=a[l];
				l++;
				r--;
			}
			else if(a[l]>a[r])
			{
				cnt+=a[r];
				a[l]-=a[r];
				r--;
			}
			else
			{
				cnt+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	printf("%lld",cnt);
	return 0;
}
