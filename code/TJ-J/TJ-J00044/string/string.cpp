#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
char b[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum = 0;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		cin >> b[i];
	}
	int l = 1,r = n,k = 0,x = a[1],maxn,minn;
	char y = b[1];
	while(l < r)
	{
		if(k == 0)
		{
			if(y == b[r])
			{
				if(x == a[r])
				{
					x = a[l+1];
					y = b[l+1];
					k = 0; 
					l += 1;
					r -= 1;
				}
				else
				{
					if(x < a[r])
					{	
						minn = x;
						maxn = a[r];
						y = b[r];
						k = 1;
						l += 1;
					}
					else
					{
						minn = a[r];
						maxn = x;
						r -= 1;
					}
					sum += minn;
					x = maxn-minn;
				}
			}
			else
			{
				if(x == a[r])
				{
					sum += x;
					x = a[l+1];
					y = a[l+1];
					k = 0;
					l += 1;
					r -= 1;
				}
				else
				{
					if(x < a[r])
					{	
						minn = x;
						maxn = a[r];
						y = b[r];
						k = 1;
						l += 1;
					}
					else
					{
						minn = a[r];
						maxn = x;
						r -= 1;
					}
					sum += minn;
					x = maxn-minn;
				}
			}
		}
		else
		{
			if(y == b[l])
			{
				if(x == a[l])
				{
					x = a[r-1];
					y = b[r-1];
					k = 1; 
					l += 1;
					r -= 1;
				}
				else
				{
					if(x < a[l])
					{	
						minn = x;
						maxn = a[l];
						y = b[l];
						k = 0;
						r -= 1;
					}
					else
					{
						minn = a[l];
						maxn = x;
						l += 1;
					}
					sum += minn;
					x = maxn-minn;
				}
			}
			else
			{
				if(x == a[l])
				{
					sum += x;
					x = a[r-1];
					y = a[r-1];
					k = 1;
					l += 1;
					r -= 1;
				}
				else
				{
					if(x < a[l])
					{	
						minn = x;
						maxn = a[l];
						y = b[l];
						k = 0;
						r -= 1;
					}
					else
					{
						minn = a[l];
						maxn = x;
						l += 1;
					}
					sum += minn;
					x = maxn-minn;
				}
			}
		}
	}
	cout << sum;
	return 0;
}
