#include<bits/stdc++.h>
using namespace std ;
string ejz(int n)
{
	string result1 , result ;
	int turn = 0 ;
	while(n > 0)
	{
		turn += 1 ;
		result1[turn] = n % 2 ;
		n /= 2 ;
	}
	for (int i = 1 ; i <= turn ; i++)
	{
		result[i] = result1[turn - i + 1] ;
	}
	return result ;
}

int awy(int a , int b)
{
	string a1 , b1 , cnt ;
	a1 = ejz(a) ;
	b1 = ejz(b) ;
	int as1 = a1.size() ;
	int bs1 = b1.size() ;
	int num = min(as1 , bs1) ;
	for (int i = 1 ; i <= num ; i++)
	{
		if(a1[num - i + 1] == b1[num - i + 1])
			cnt[num - i + 1] = 1 ;
		else
			cnt[num - i + 1] = 0 ;
	}
	int ans = 0 ;
	for (int i = num ; i >= 1 ; i--)
	{
		ans += cnt[i] * 2^(num - 1) ;
	}
	return ans ;
}
int main()
{
	freopen("and.in" , "r" , stdin) ;
	freopen("ans.out" , "w" , stdout) ;
	int n , m , cnt = 0 ;
	cin >> n >> m ;
	int num[n + 5] ;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> num[i] ;
	}
	int ans = awy(num[1] , num[2]) ;
	while(m > 0)
	{
		for (int i = 3 ; i <= m ; i++)
		{
			ans = awy(ans , num[i]) ;
		}
		cnt = max(cnt , ans) ;
		ans = awy(num[1] , num[2]) ;
		m-- ;
	}
	cout << cnt ;
	return 0 ;
}
