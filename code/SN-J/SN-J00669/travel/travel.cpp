// 蒲逸尘 西安理工大学附属中学 SN-J00669 
#include <bits/stdc++.h>
using namespace std ;
string c1 , s1 , c2 , s2 ;
string ans = "" ;
int f(string x , string y)
{
	char cx , cy ;
	for(int i = 0 ; i < x.size() ; i++) cx = x[i] ;
	for(int i = 0 ; i < y.size() ; i++) cy = y[i] ;
	if(cx > cy)
	{
		if(cx - cy == 1 && cx != 'D' && cy != 'C') return 1 ;
		else return 0 ;
	}
	else
	{
		if(cy - cx == 1 && cy != 'D' && cx != 'C') return 1 ;
		else return 0 ;
	}
}
int main()
{
	freopen("travel.in" , "r" , stdin) ;
	freopen("travel.out" , "w" , stdout) ;
	cin >> c1 >> s1 >> c2 >> s2 ;
	s1 += "      ";
	s2 += "      ";
	string ss1 = s1.substr(0 , 2) ;
	string ss2 = s2.substr(0 , 2) ;
	string sss1 = s1.substr(2 , 1) ;
	string sss2 = s2.substr(2 , 1) ;
	//cout << ss1 << " " << ss2 << endl << sss1 << " " << sss2 << endl ;
	if(c1 == c2)
		ans += '1';
	else ans += '0';
	if(c1 == c2 && ss1 == ss2)
		ans += '1';
	else ans += '0';
	if(c1 == c2 && ss1 == ss2 && ((sss1 <= "C" && sss2 <= "C") || (sss1 > "C" && sss2 > "C")))
		ans += '1';
	else ans += '0' ;
	if(c1 == c2 && ss1 == ss2 && ((sss1 <= "C" && sss2 <= "C") || (sss1 > "C" && sss2 > "C")) && f(sss1 , sss2) == 1)
		ans += '1' ;
	else ans += '0' ;
	cout << ans << endl ;
	return 0 ;
}
