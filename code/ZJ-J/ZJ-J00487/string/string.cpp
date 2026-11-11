#include <bits/stdc++.h>
using namespace std;
long long a[200005],b[200005],sum[200005];
char ca[200005],cb[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int s=0;
	cin >> n;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
		cin>> ca[i];
		b[n+1-i]=a[i];
		cb[n+1-i]=ca[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+b[i];
	}
	int num=0;
	int l=1,bl=1;
	for(int i=1;i<=n;i++)
	{
		if(ca[l]==cb[bl])
		{
			if(a[l]>=b[bl])
			{
				a[l]-=b[bl];
				b[bl]=0;
				bl++;
				if(a[l]==0)l++;
				s+=b[bl];
			}
			else
			{
				b[bl]-=a[l];
				a[l]=0;
				l++;
				if(b[bl]==0)bl++;
				s+=a[l];
			}
		}
		else
		{
			if(a[l]>=b[bl])
			{
				a[l]-=b[bl];
				num+=b[bl];
				b[bl]=0;
				bl++;
				if(a[l]==0)l++;
				s+=b[bl];
			}
			else
			{
				b[bl]-=a[l];
				num+=a[l];
				a[l]=0;
				l++;
				if(b[bl]==0)bl++;
				s+=a[l];
			}
		}
		if(s*2>=sum[n])
		{
			cout << num;
			break;
		}
	}
	return 0;
}
