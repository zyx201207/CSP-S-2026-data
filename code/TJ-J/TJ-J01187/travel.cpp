#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	string ns1, ns2;
	string ms1, ms2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2)
	{
		cout << "1";
	}
	else cout << "0";

	if(ns1 == ns2)
	{
	cout << "1";
	}
	else cout << "0";
	
	if(ms1 == "A" ||ms1 == "B"|| ms1 == "C"&&ms2 == "A" || ms2 == "B" ||ms2 == "C")
	cout << "1";
	else if(ms1 == "D" || ms1 == "E" && ms2 == "D" ||ms2 == "E")
	cout << "1";
	else cout << "0";
		
	if(ms1 == "A" && ms2 == "B" || ms1 == "B" && ms2 == "A")
	cout << "1";
	else if(ms1 == "B" && ms2 == "C" || ms1 == "C" && ms2 == "B")
	cout << "1";
	else if(ms1 == "D" && ms2 == "E" || ms1 == "D" && ms2 == "E")
	cout << "1";
	else cout << "0";

	return 0;	
} 
