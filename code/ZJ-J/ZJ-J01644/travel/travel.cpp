#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string c1, s1, c2, s2;

bool check2()
{
	if (s1[0] == s2[0] && s1[1] == s2[1]) return true;
	return false;
}

bool check3()
{
	char k1 = s1[2], k2 = s2[2];
	
	if (k1 <= 'C' && k2 <= 'C') return true;
	if (k1 >= 'D' && k2 >= 'D') return true;
	
	return false;
}

bool check4()
{
	char k1 = s1[2], k2 = s2[2];
	if (k1 <= 'C' && k2 <= 'C')
	{
		if (k1 == 'A' && k2 == 'C') return false;
		if (k1 == 'C' && k2 == 'A') return false;
		
		return true;
	}
	if (k1 >= 'D' && k2 >= 'D') return true;
	return false;
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 == c2) 
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	
	if (c1 == c2 && check2()) 
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	
	if (c1 == c2 && check2() && check3()) 
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	
	if (c1 == c2 && check2() && check3() && check4()) 
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	
	cout << endl;
	
	return 0;
}
