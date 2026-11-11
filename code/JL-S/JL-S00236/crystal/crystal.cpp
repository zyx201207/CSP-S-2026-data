#include <iostream>
#include <algorithm>
using namespace std;
long long a[500005],d;
long long n,m;
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a,a+n+1);
	d = a[2]-a[1];
	bool delta = 1;
	for(int i = 2;i <= n;i++)
	{
		if((a[i]-a[i-1])!=d)
		{
			delta = 0;
			break;
		}
	}
	if(delta)
	{
		int cnt=0;
		for(int i = d,j = 1;;i+=d,j++)
		{
			cnt += i;
			if((cnt+i+d)>m)
			{
				cout << (j+1);
				break;
			}
		}
	}
	else
	{
		int maxn=1;
		for(int i = 1; i <= n; i++)
		{
			int cur = 1;
			for(int j = i; j-1>0&&m-a[i-1]>=0;j--)
			{
				m-=a[i-1];
				cur++;
			}
			maxn = max(maxn,cur);
		}
		cout << maxn;
	}
	return 0;
}
