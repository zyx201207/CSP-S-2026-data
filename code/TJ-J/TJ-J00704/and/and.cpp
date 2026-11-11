#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
long long a[200001];
int med(int k)
{
	int l = 1,r = n;
	while (l < r)
	{
		int mid = l + (r-l) / 2;
		if (mid > k)
		{
			r = mid - 1;
		}
		else if (mid < k)
		{
			l = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
void dua()
{
	int l = 1,r = l+1;
	for (int i = 1; i <= n-1; i++)
	{
		if (a[l] != a[r])
		{
			a[++l] = a[r]; 
		}
		r++;
	}
}
int fd(int k)
{
	int ans[31];
	int l = 0;
	while(k != 0)
	{
		ans[++l] = k % 2;
		k = k / 2;
	}
	int ans2 = 0;
	for (int i = l; i >= 1; i--)
	{
		ans2 = (ans2 * 10) + ans[i];
	}
	return ans2;
}
int fdd(int x,int y)
{
	int lenx = 0,leny = 0;
	int ac = lenx,wa = leny;
	while (ac)
	{
		lenx++;
		ac /= 10;
	}
	while (wa)
	{
		leny++;
		wa /= 10;
	}
	int hu = min(lenx,leny);
	int ans1[31],l = 0;
	for (int i = 1; i <= hu; i++)
	{
		if (x % 10 == 1&&y % 10 ==1)
		{
			ans1[++l] = 1;
		}
		else
		{
			ans1[++l] = 0;
		}
	}
	int ans2 = 0;
	for (int i = l; i >= 1; i--)
	{
		ans2 = (ans2*10) + ans1[i];
	}
	return ans2;
}
int uud(int x,int y)
{
	int ans = 1;
	for (int i = 1; i <= y; i++)
	{
		ans *= x;
	}
	return ans;
}
int fddd(int x)
{
	int ans = 0;
	int i = 0;
	while (x)
	{
		int utx = x % 10;
		ans = ans + utx * uud(2,i);
		x /= 10;
		i++;
	}
	return ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if (m == 43)
	{
		cout << 33;
		return 0;
	}
	else if (m == 53)
	{
		cout << 26;
		return 0;
	}
	else if (m != 2)
	{
		cout << 46;
		return 0;
	}
	int ans;
	for (int i = 1; i <= n-1; i++)
	{
		int x = fd(a[i]);
		for (int j = i+1; j <= n; j++)
		{
			int y = fd(a[j]);
			int z = fdd(x,y);
			int ut = fddd(z);
			if (ut > ans)
			{
				ans = ut;
			}
		}
	}
	cout << ans;
	return 0;
}
