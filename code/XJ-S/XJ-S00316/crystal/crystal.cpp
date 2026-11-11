#include<bits/stdc++.h>
using namespace std;
const int N=1e7+12;
long long n,m,a[N],diff[N],summ[N],sum,cnt,ans,b[N],t;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		diff[i]=a[i]-a[i+1];
	}
	summ[0]=0;
	for(int i=1;i<n;i++)
	{
		summ[i]=summ[i-1]+diff[i];
	}
	for(int i=0;i<n-1;i++)
	{
		cnt=0;
		t=m;
		sum=0;
		for(int j=n-1;j>i;j--)
		{
			b[++cnt]=summ[j]-summ[i];
		}
		for(int j=cnt;j>=1;j--)
		{
			if(t>=b[j])
			{
				t-=b[j];
				sum++;
				ans=max(ans,sum);
			}
			else
			{
				break;
			}
		}
	}
	cout<<ans+1;
	return 0;
}
