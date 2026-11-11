#include<bits/stdc++.h>
using namespace std ;
const unsigned long long N = 5e5 + 5 ;
long long tmp[N] , s[N] , inv[N] , n , m , temp , f ;
unsigned long long ans , cnt ;
bool fl = true ;
unsigned long long left(unsigned long long st)
{
	unsigned long long tot = 1e18 , id = 0 ;
	unsigned long long l = 1 , r = st ;
	while(l <= r)
	{
		unsigned long long mid = (l + r) / 2 ;
		unsigned long long cry = tmp[st] - (s[st] * (mid - 1) - inv[mid - 1]) ;
		if(cry > m)
		{
			l = mid + 1 ;
		}
		else
		{
			r = mid - 1 ;
			if(st - mid + 1 > id)
			{
				id = st - mid + 1 ;
				temp = mid - 1 ;
				tot = cry ;
			}
		}
	}
	cnt = max(cnt , id) ;
	return tot ;
}
unsigned long long right(unsigned long long st)
{
	unsigned long long tot = 1e18 , id = 0 ;
	unsigned long long l = st , r = n ;
	while(l <= r)
	{
		unsigned long long mid = (l + r) / 2 ;
		unsigned long long cry = tmp[mid] - (s[mid] * (st - 1) - inv[st - 1]) ;
		if(cry > m)
		{
			r = mid - 1 ;
		}
		else
		{
			l = mid + 1 ;
			if(mid - st + 1 > id)
			{
				id = mid - st + 1 ;
				temp = mid - 1 ;
				tot = cry ;
			}
		}
	}
	cnt = max(cnt , id) ;
	return tot ;
}
int main()
{
	freopen("crystal.in" , "r" , stdin) ;
	freopen("crystal.out" , "w" , stdout) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) , cout.tie(0) ;
	cin >> n >> m ;
	for(unsigned long long i = 1 ; i <= n ; i++)
	{
		cin >> s[i] ;
		if(i == 1)
		{
			f = s[i] ;
		}
		else
		{
			if(s[i] != f)
			{
				fl = false ;
			}
		}
	}
	if(f)
	{
		cout << m / f << "\n" ;
		return 0 ;
	}
	sort(s + 1 , s + n + 1) ;
	inv[1] = tmp[1] = s[1] , tmp[2] = s[2] - s[1] , inv[2] = s[1] + s[2] ;
	for(unsigned long long i = 3 ; i <= n ; i++)
	{
		inv[i] = inv[i - 1] + s[i] ;
		tmp[i] = tmp[i - 1] + abs(s[i] - s[i - 1]) * (i - 1) ;
	}
	//从i到j所需的操作数量：
	//tmp[j] - (s[j] * (i - 1) - inv[i - 1])  
	unsigned long long l = 1 , r = n ;
	while(l <= r)
	{
		unsigned long long mid = (l + r) / 2 ;
		unsigned long long pre = left(mid) ;
		if(pre <= m)
		{
			l = mid + 1 ;
		}
		else
		{
			r = mid - 1 ;
		}
	}
	l = 1 , r = n ;
	while(l <= r)
	{
		unsigned long long mid = (l + r) / 2 ;
		unsigned long long pre = right(mid) ;
		if(pre <= m)
		{
			r = mid - 1 ;
		}
		else
		{
			l = mid + 1 ;
		}
	}
	cout << cnt << "\n" ;
	return 0 ;
}
/*
5 5
1 2 4 8 9



5 8
-3 -1 2 2 7
*/
