#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=500005;
int n,m;
int a[MAXN];
int f[MAXN];
int cnt=0;
int sum[MAXN];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cnt=m;
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		f[i]=a[i]-a[i-1];
		sum[i]=sum[i-1]+f[i];
	}
	int l=1;
	int fmx=-1e9;
	for(int i=2;i<=n;i++)
	{	
		cnt-=f[i]*(i-l);
		if(cnt<0)
		{
			cnt+=sum[i]-sum[l];
			l++;
		}
		if(cnt==0)
		{
			if(f[i+1]!=0)
			{
				fmx=max(fmx,i-l);
				l++;
				cnt+=sum[i]-sum[l];
			}
			else
				fmx=max(fmx,i-l);
		}
		if(cnt>0)
		{
			fmx=max(fmx,i-l);
		}
	}
	cout<<fmx+1;
}