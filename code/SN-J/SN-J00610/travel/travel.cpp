#include<bits/stdc++.h>
using namespace std ;

int main()
{
	freopen("travel.in" , "r" , stdin) ;
	freopen("travel.out" , "w" , stdout) ; 
	ios::sync_with_stdio(0) ;
	cin.tie(0) , cout.tie(0) ;
	string x , y , l , r ; cin >> x >> y >> l >> r ;
	bool fl = false ;
	if(x == l)
	{
		cout << 1 ;
		fl = true ;
	}
	else
	{
		cout << 0 ;
	}
	if(y.substr(0 , 2) == r.substr(0 , 2) && fl)
	{
		cout << 1 ;
	}
	else
	{
		cout << 0 ;
	}
	bool f = false ;
	char tmp = y[y.size() - 1] , res = r[r.size() - 1] ;
	if(y.substr(0 , 2) == r.substr(0 , 2) && fl)
	{
		if((tmp <= 'C' && res <= 'C') || (tmp > 'C' && tmp <= 'F' && res > 'C' && res <= 'F'))
		{
			cout << 1 ;
			f = true ;
		}
		else
		{
			cout << 0 ;
		}
	}
	else
	{
		cout << 0 ;
	}
	if(f && abs(tmp - res) == 1 && fl)
	{
		cout << 1 ;
	}
	else
	{
		cout << 0 ;
	}
	cout << "\n" ;
	return 0 ;
}
/*
02 01A 02 01B



02 01C 02 01A



02 01C 02 01D



02 02B 02 01A



02 01A 03 01A
*/
