#include<bits/stdc++.h>
using namespace std;
long long a[5000000];
long long n=0,m=0,maxn=0,cnt=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		int k=m;
		for(int j=i-1;j>=1;j--)
		{
			if(a[i]-a[j]<=k)
			{
				cnt++;
				k-=a[i]-a[j];
			}
			else
			{
				break;
			}
		}
		if(cnt>maxn)
		{
			maxn=cnt;
		}
		cnt=0;
	}
	cout<<maxn+1;
	return 0;
}

