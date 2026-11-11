#include <bits/stdc++.h> 
using namespace std;
long long a[100000007];
long long b[100000007];
long long c[100000007];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,sum=0;
	cin >> n >>m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=2;i<n;i++)
	{
		sum+=a[i];
	}
	int k=sum/(n-2);
	for(int i=1;i<=n;i++)
	{
		if(k>=a[i])b[i]=a[i]-k;
	}
	sort(b+1,b+n+1);
	for(int i=n;i>=1;i--)
	{
		if(a[i]-b[i]==k&&m>=abs(b[i])&&m>=0)
		{
			a[i]+=(abs(b[i])+1);
			m-=abs(b[i]);
			b[i]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[j]!=0&&a[j]==a[j+1])
			{
				c[i]++;
			}
		}
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++)
	{
		if(i==n) cout << c[n]+1;
	}
	return 0;
}
