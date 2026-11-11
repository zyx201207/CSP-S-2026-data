#include <bits/stdc++.h>
using namespace std;
int n,DAN=0,b[50005];
long long m,a[50005];
bool cmp(long long a,long long b )
{
	if (a!=b)
	{
		return a>b;
	}
}
int main()
{
	freopen("crystal.in .txt","r",stdin);
	freopen("crystal.out ","w",stdout);
	cin>>n>>m;
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt+=a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long MB=cnt/n;
	for (int i=1;i<=n;i++)
	{
		if (a[i]>MB && a[i+1]<=MB)
		{
			MB=a[i+1];
			break;
		}
	}
	while(m>0)
	{
		for (int i=1;i<=n;i++)
		{
			if (a[i]<MB)
			{
				if (m-(MB-a[i])>=0)
				{
					m=m-(MB-a[i]);
					a[i]+=MB-a[i];
				}
				else
				{
					break;
				}
			}
		}
		for (int i=1;i<=n;i++)
		{
			if (a[i]==a[i+1])
			{
				if (b[i]!=1 && b[i+1]!=1)
				{
					DAN+=2;
				}
				else
				{
					DAN+=1;
				}
				b[i]=1;
				b[i+1]=1;
			}
		}
		break;
	}
	cout<<DAN;
	return 0;
} 