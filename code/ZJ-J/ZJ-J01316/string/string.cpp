#include<bits/stdc++.h>
using namespace std;
long long n,l,r,cnt,sum;
long long a[200010];
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=1,r=n;
	sum=n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	while(l!=r)
	{
		if(c[l]!=c[r])
		{
			if(a[l]>a[r])
			{
				cnt+=a[r];
				a[l]-=a[r];
				r--;
				sum--;
			}
			else if(a[l]<a[r])
			{
				cnt+=a[l];
				a[r]-=a[l];
				l++;
				sum--;
			}
			else
			{
				cnt+=a[l];
				l++;
				r--;
				if(sum>2)
				{
					sum-=2;
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
				sum--;
			}
			else if(a[l]<a[r])
			{
				a[r]-=a[l];
				l++;
				sum--;
			}
			else
			{
				l++;
				r--;
				if(sum>2)
				{
					sum-=2;
				}
				else
				{
					break;
				}
			}
		}
	}
	cout<<cnt;
}