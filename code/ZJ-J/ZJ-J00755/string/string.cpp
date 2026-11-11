#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long a[N],sum;

char ch[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>ch[i];
	}
	for(int l=1,r=n;l<=r;)
	{
		if(ch[l]!=ch[r])
		{
			if(a[l]>=a[r])
			{
				sum+=a[r];
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
			else
			{
				sum+=a[l];
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
		}
		else
		{
			if(a[l]>=a[r])
			{
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
			else
			{
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
		}
	}
	cout<<sum;
	return 0;
}

