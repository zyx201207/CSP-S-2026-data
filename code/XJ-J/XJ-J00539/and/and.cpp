#include <bits/stdc++.h>
#include <string>
using namespace std;

int n , m , cnt , cmt;
int a[10000] , b[10000];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m >> cnt;
	for(int i = 1;i <= cnt;i++)
	{
		a[1]++;
		for(int j = 1;j <= cnt;j++)
		{
			if(a[j == 2])
			{
				a[j + 1]++;
				a[j] = 0;
			}
	    }
	}
	for(int i = 2;i <= n;i++)
	{
		cin >> cmt;
		for(int i = 1;i <= cmt;i++)
		{
			b[1]++;
			for(int j = 1;j <= cmt;j++)
			{
				if(b[j == 2])
				{
					b[j + 1]++;
					b[j] = 0;
				}
		    }
		}
		for(int i = min(cnt,cmt);i >= 1;i--)
		{
			for(int j = min(cnt,cmt);j <= 9999;j++)
			{
				a[j] = 0;
				b[j] = 0;
			}
			if(a[i] == b[i])
			{
				a[i] = b[i];
				b[i] = 0;
			}
		}
	}
	cnt = 0;
	cnt += a[1];
	for(int i = 2;i <= cmt;i++)
	{
		cnt += a[i] * 2 ^ i;
	}
	cout << cnt;
	return 0;
}