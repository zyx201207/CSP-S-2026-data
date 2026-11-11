#include<iostream>
#define ll long long
using namespace std;

ll n,a[100010],s[100010],ans;
char c[100010];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		s[i]=s[i-1]+a[i];
	}
	int k1=1,k2=n;
	int i=1,j=s[n];
	while(k1<=k2)
	{
		if(c[k1]!=c[k2])
		{
			if(a[k1]>a[k2])
			{
				ans+=a[k2];
				a[k1]-=a[k2];
				k2--;
			}
			else if(a[k1]<a[k2])
			{
				ans+=a[k1];
				a[k2]-=a[k1];
				k1++;
			}
			else
			{
				ans+=a[k1];
				k1++,k2--;
			}
		}
		else
		{
			if(a[k1]>a[k2])
			{
				a[k1]-=a[k2];
				k2--;
			}
			else if(a[k1]<a[k2])
			{
				a[k2]-=a[k1];
				k1++;
			}
			else
			{
				k1++,k2--;
			}
		}
	}
	cout<<ans;
	return 0;
}

