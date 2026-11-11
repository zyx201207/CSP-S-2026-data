#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 5e5 + 10;
long long m;
int n;
long long a[N];

bool check(int x)
{
	long long minn = 0, dlt = 0;
	for(int i = 1; i <= x; i ++ )
		minn += (a[x] - a[i]);
	dlt = minn;
	
	for(int i = x + 1; i <= n; i ++ )
	{
		dlt = dlt + (x - 1) * (a[i] - a[i - 1]) - (a[i - 1] - a[i - x]);
		minn = min(minn, dlt);
		
	}
	
	return minn <= m;
}


int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i ++ )
	{
		scanf("%lld", &a[i]);
	}
	
	sort(a + 1, a + n + 1);
	
	int left = 1, right = n;
	while(left < right)
	{
		int mid = left + (right - left) / 2 + 1;
		if(check(mid))
			left = mid;
		else
			right = mid - 1;
		
	}
	
	printf("%d", left);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
