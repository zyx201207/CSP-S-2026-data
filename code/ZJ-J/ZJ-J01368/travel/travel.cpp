#include<bits/stdc++.h>
using namespace std ;
#define int long long
#define FIO ios::sync_with_stdio(),cin.tie(0),cout.tie(0) ;
int f (string x)
{
	int i = 0 , s = 0 ;
	while(x[i] >= '0' && x[i] <= '9')
	{
		s = s * 10 + (x[i] - '0') ;
		i ++ ;
	}
	return s ;
}
bool check (char x , char y)
{
	int t1 , t2 ;
	t1 = t2 = 0 ;
	if(x >= 'D' && x <= 'F') t1 = 1 ;
	if(y >= 'D' && y <= 'F') t2 = 1 ;
	if(t1 == t2) return true ;
	else return false ;
	return false ;
}
int n1 , n2 ;
string s1 , s2 ;
signed main()
{
	freopen("travel.in" , "r" , stdin) ;
	freopen("travel.out" , "w" , stdout) ;
	FIO
	cin >> n1 >> s1 ;
	cin >> n2 >> s2 ;
	if(n1 == n2) cout << 1 ;
	else {cout << "0000" ; return 0 ;}
	
	if(f(s1) == f(s2)) cout << 1 ;
	else {cout << "000" ; return 0 ;}
	
	if(check(s1[2] , s2[2])) cout << 1 ;
	else {cout << "00" ; return 0 ;}
	
	if(s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2])cout << 1 ;
	else cout << "0" ;
	
	return 0 ;
}                  