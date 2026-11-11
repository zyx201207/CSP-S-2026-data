#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],cnt=1,maxx=-0x7f;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
	}
	for(int i=1;i<n;i++)
	{
		cnt=1;
		int m1=m;
		for(int j=i;j<n;j++)
		{
			if(m1-b[j+1]*(j-i+1)>=0)
			{
				m1-=b[j+1]*j;
				cnt++;
			}
		}
		if(cnt>maxx)maxx=cnt;
	}
	cout<<maxx;
	return 0;
}
