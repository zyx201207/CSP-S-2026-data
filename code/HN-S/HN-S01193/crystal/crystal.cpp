#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read()
{
	int x = 0 , f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
			f = -1;
		ch = getchar();	
	}	
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
const int N = 5e5 + 5;
int n , m;
int a[N];
int sum[N];
//bool pd(int x)
//{
//	int sss = 0;
//	for(int i = x - 1;i > 0; -- i)
//	{
//		sss += a[i];
//		if(sss > m)
//			return 0;
//	}
//	return 1;
//}

signed main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	n = read() , m = read();
	int num3 = 0;
	for(int i = 1;i <= n; ++ i)
	{
		a[i] = read();
		if(a[i] == i)
			num3 ++;
	}
	sort(a + 1 , a + n + 1);
	int ans = -0x3f3f3f3f , num = 1;
	for(int i = 1;i <= n; ++ i)
	{
		sum[i] = a[i + 1] - a[i];
		ans = max(ans , num);
		if(a[i] == a[i + 1])
			num ++;
		else
			num = 1;
	} 
	sum[n] = 0x3f3f3f3f;
	int num2 = 1;
	for(int i = 1;i <= n; ++ i)
	{
		if(sum[i] == sum[i + 1])
			num2 ++;
	}
	if(num2 == n)
	{
		cout << floor(m * 1.0 / sum[1]);
		return 0;
	}
	if(num3 == n)
	{
		cout << min(n , m + 1);
		return 0;
	}
//	sort(sum + 1 , sum + n + 1);
	int mm = 0;
	for(int i = 1;i < n; ++ i)
	{
		int num = sum[i] * i;
		if(num > m)
			break;
		else
		{
			m -= num;
			mm ++;
		}
	}
	cout << max(mm , ans) + 1;
//	int l = 1 , r = n , mid;
//	while(l < r)
//	{
//		mid = (l + r) >> 1;
//		if(pd(mid))
//			l = mid;
//		else
//			r = mid - 1; 
//	}
//	cout << max(ans , l);
	return 0;
}
