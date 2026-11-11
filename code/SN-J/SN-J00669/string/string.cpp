// 蒲逸尘 西安理工大学附属中学 SN-J00669
#include <bits/stdc++.h>
using namespace std ;
int n ;
string s ;
int main()
{
	freopen("string.in" , "r" , stdin) ;
	freopen("string.out" , "w" , stdout) ;
	cin >> n ;
	for(int i = 1 ; i <= n ; i++)
	{
		int x ;
		char c ;
		cin >> x >> c ;
		for(int j = 1 ; j <= x ; j++)
			s += c ;
	}
	long long l = s.size() ;
	if(l % (1ll*2) == 0)
	{
		string s1 = s.substr(0 , s.size() / 2) ;
		string s2 = s.substr(s.size() / 2 , s.size() / 2) ;
		long long res = 0 ;
		for(long long i = 0 ; i < s1.size() ; i++)
			if(s1[i] != s2[i]) ++res;
		cout << res << endl ;
	}
	if(l % (1ll*2) == 1)
	{
		string s1 = s.substr(0 , s.size() / 2) ;
		string s2 = s.substr(s.size() / 2 + 1 , s.size() / 2) ;
		long long res = 0 ;
		for(long long i = 0 ; i < s1.size() ; i++)
			if(s1[i] != s2[i]) ++res;
		cout << res << endl ;
	}
	return 0 ;
}
