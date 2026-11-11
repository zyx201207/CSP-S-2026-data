#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],s,sum,num;
char b[200005],c[100000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		sum+=a[i];
		for(long long j=1;j<=a[i];j++)
		{
			s++;
			c[s]=b[i];
		}
	}
	if(sum%2==1)
	{
		for(long long i=1;i<=sum/2;i++)
		{
			if(c[sum/2+1-i]!=c[sum/2+1+i])
			{
				num++;
			}
		}
		cout<<num;
	}
	else
	{
		for(long long i=1;i<=sum/2;i++)
		{
			if(c[sum/2+1-i]!=c[sum/2+i])
			{
				num++;
			}
		}
		cout<<num;
	}
	return 0;
}
