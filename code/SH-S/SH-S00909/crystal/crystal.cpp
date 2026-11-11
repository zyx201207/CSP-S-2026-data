#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

long long n,m,a[500005],b[500005],ans=-1,c[500005],sum;
long long minn=1e18,res1,res2,maxn=-1e18,minn2=1e18;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		b[i] = b[i-1]+a[i];
		c[i] = a[i]*i-b[i];
		//cout << i << ":" << m-c[i] << endl;
		if((m-c[i]<minn||(m-c[i]==minn&&i>res1))&&m-c[i]>=0)
		{
			minn = m-c[i];
			res1 = i;
		}
		if(abs(m-c[i])<minn||(m-c[i]==minn&&i>res2))
		{
			minn2 = abs(m-c[i]);
			res2 = i;
		}
	}
	for(int i=1;i<n;i++)
	{
		sum += a[n]-a[i];
	}
	if(m > sum)
	{
		cout << n;
		return 0;
	}
	//cout << a[res1] << " " << a[res2] << endl;
	for(int i=a[res1];i<=a[res2];i++)
	{
		long long cnt=0,sum=0;
		for(int j=n;j>=1;j--)
		{
			if(a[j]>i) continue;
			if(sum+(i-a[j])>m)
			{
				break;
			}
			else
			{
				sum = sum+(i-a[j]);
				cnt ++;
			}
		}
		//cout << i << ":" << cnt << endl;
		ans = max(ans,cnt);
	}
	cout << ans;
	return 0;
}
