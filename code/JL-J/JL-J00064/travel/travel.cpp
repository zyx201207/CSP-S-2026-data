#include <bits//stdc++.h>
using namespace std;
int a, b;
string s1, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> a >> s1 >> b >> s2;
	if(a != b)
	{
		cout << "0000\n";
		return 0;
	}
	int a1 = (s1[0] - '0') * 10 + s1[1] - '0';
	int a2 = (s2[0] - '0') * 10 + s2[1] - '0';
	int b1 = s1[2] - 'A' + 1;
	int b2 = s2[2] - 'A' + 1;
	cout << "1";
	if(a1 == a2)
	{
		cout << "1";
		if((b1 >= 1 && b1 <= 3 && b2 >= 1 && b2 <= 3) || (b1 >= 4 && b1 <= 5 && b2 <= 5 && b2 >= 4))
		{
			cout << "1";
		}
		else
		{
			cout << "0";
		}
	}
	else
	{
		cout << "00";
	}
	if((b1 == 3 && b2 == 4) || (b1 == 4 && b2 == 3))
	{
		cout << "0\n";
	}
	else if((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2) <= 1)
	{
		cout << "1\n";
	}
	else
	{
		cout << "0\n";
	}
	return 0;
}
