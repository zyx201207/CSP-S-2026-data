#include<algorithm>
#include<iostream>

using namespace std;

typedef long long LL;
const int N = 5e5 + 5;

LL a[N] = {0};
int ans = 1;

LL m;
int n;

inline int check()
{
	LL vl = a[n] - a[n - 1];
	for(int i = n - 1;i > 1;--i)
	{
		if(a[i] - a[i - 1] != vl)
		{
			return 0;
		}
	}
	return 1;
}

void fun()
{
	LL tm = m;
	int res = 1;
	
	for(int i = n - 1;i > 0;--i)
	{
		if(tm < a[n] - a[i])
		{
			ans = res;
			return ;
		}
		
		tm -= a[n] - a[i];
		
		++res;
	}
	
	ans = res;
	
	return ;
	
}

void sol()
{
	
	if(check())
	{
		fun();
		return ;
	}
	
	for(int i = n;i > 1;--i)
	{
		LL tm = m;
		int res = 0;
		
		for(int j = i - 1;j > 0;--j)
		{
			if(tm < a[i] - a[j])
			{
				break;
			}
			
			tm -= a[i] - a[j];
			++res;
		}
		
		ans = max(ans , res + 1); 
		
		if(ans == i - 1)
		{
			return;
		}
		
	}
	
	return ;
}

int main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;++i)
	{
		cin >> a[i];
	}
	
	sort(a + 1 , a + n + 1);
	
	sol();
	
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
/*
fre
fcl
ret
*/
