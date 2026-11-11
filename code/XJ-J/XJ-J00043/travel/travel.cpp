#include <bits/stdc++.h> 
using namespace std;
char c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==1||c2==16)
	{
		return 0;
	}
	if(c1-'0'==c2-'0')
	{
		cout << "1";
	}
	else
	{
		cout <<"0000";
		return 0;
	}
	if(s1-'0'==s2-'0'+36)
	{
		cout << "111";
	}
	else
	{
	    cout << "000";
	}
	return 0;
}
