#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t1, t2;
	string s1, s2;
	cin>>t1>>s1>>t2>>s2;
	if(t1 == t2)
	{
		cout << 1;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	if((s1[0] == s2[0]) && (s1[1] == s2[1]))
	{
		cout << 1;
	}
	else
	{
		cout << "000";
		return 0;
	}
	if(s1[2] >= 'A' && s1[2] < 'D')
	{
		if(s2[2] >= 'A' && s2[2] < 'D' && s2[2] != s1[2])
		{
			cout << 1 << (abs(s1[2] - s2[2]) == 1);
		}
		else
		{
			cout << "00";
		}
	}
	else
	{
	    if((s2[2] == 'D' || s2[2] == 'F') && s2[2] != s1[2])
	    {
	    	cout << "11";
		}
		else
		{
			cout << "00";
		}
	}
	return 0;
}

