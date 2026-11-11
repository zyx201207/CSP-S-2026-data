#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int m,n,e,t;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		m = 1;
	}
	cout << s1[2]; 
	if(s1[0] == s2[0] && s1[1] == s2[1])
	{
		n == 1;	
		if(s1[2] == "A" && s2[2] == "B" || s1[2] == "B" && s2[2] == "C" || s1[2] == "D" && s2[2] == "F" || s1[2] == "B" && s2[2] == "A" || s1[2] == "C" && s2[2] == "B" || s1[2] == "F" && s2[2] == "D"|| s2[2] == "A" && s2[2] == "C" || s1[2] == "C" && s2[2] == "A")
			e = 1;
	} 
	
	if(s1[2] == "A" && s2[2] == "B" || s1[2] == "B" && s2[2] == "C" || s1[2] == "D" && s2[2] == "F" || s1[2] == "B" && s2[2] == "A" || s1[2] == "C" && s2[2] == "B" || s1[2] == "F" && s2[2] == "D")
	{
		t = 1;
	}
	cout << m << n << e << t;
	return 0;
}






