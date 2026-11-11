#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(long long i = 0;i<n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n,cmp);
	long long cnt = 1;
	for(long long i = 0;i<n;i++)
	{
		long long sum = 0;
		long long meici = 1;
		for(long long j = i+1;j<n;j++)
		{
			if(sum+(a[i]-a[j])<=m)
			{
				sum+=(a[i]-a[j]);
				meici++; 
			}
			else
			{
				break;
			}
		}
		cnt = max(cnt,meici);
	}
	cout << cnt << endl;
	return 0;
}

