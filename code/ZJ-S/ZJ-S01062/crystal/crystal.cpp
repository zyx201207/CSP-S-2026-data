#include<bits/stdc++.h>
using namespace std;
long long n, m;
long long a[1002001], c[1002001];
long long ans = 0, cost = 0;
long long maxx = -1e18;
void solveA()
{
	long long tmp = 0,res = 0;
	long long i = 1;
		while(tmp + i <= m)
		{
			tmp += i;
			res ++;
			i ++;
		}
	
	
	cout << res + 1;
	return;
}
void solveB(long long x)
{
	long long tmp = 0,res = 0;
	long long i = x;
		while(tmp + i <= m)
		{
			tmp += i;
			res ++;
			i += x;
		}
	
	
	cout << res + 1;
	return;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    bool flag = true;
    long long temp = 0;
    for(long long i = 1; i <= n; i ++)
    {
    	cin >> a[i];
    	if(a[i] != i)
    	{
    		flag = false;
		}
		
	}
	sort(a + 1, a + n + 1);
	if(flag)
	{
		solveA();
		return 0;
	}
	flag = true;
	for(long long i = 2; i <= n; i ++)
	{
		c[i] = a[i] - a[i - 1];
	}
	for(long long i = 2; i < n; i ++)
	{
		if(c[i] != c[i + 1])
			flag = false;
	}
	if(flag)
	{
		solveB(c[2]);
		return 0;
	}
    for(long long i = 1; i <= n; i ++)
    {
    	ans = 1, cost = 0;
    
    	for(long long j = i - 1; j >= 1; j --)
    	{
    		if(cost + (a[i] - a[j]) <= m)
    		{
    			cost += (a[i] - a[j]);
    			ans ++;
			}
    		
		}
		maxx = max(maxx, ans);
	}
	cout << maxx;
    return 0;
}
