#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+7;
int n;
long long  m;
long long a[N];
int ans;


int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	scanf("%d %lld", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		int num = 1;
		long long cost = 0;
		for (int j = i+1; j <= n; j++)
		{
			long long tcost = cost + (a[j]-a[j-1])*(j-i);
			if (tcost <= m)
			{
				cost += (a[j]-a[j-1])*(j-i);
				num++;
			}
			else break;
		}
		
		ans = max(ans, num);
		//printf("%d %d\n", num, ans);
	}
	printf("%d", ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
