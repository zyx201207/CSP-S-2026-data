#include<bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
string ans;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2)
	{
		cout << "0000" << endl;
		return 0;
	}

	if(s1[0] != s2[0] or s1[1] != s2[1])
	{
		cout << "1000" << endl;
		return 0;
	}
	
	if(!(s1[2] >= 'A' and s1[2] <= 'C' and s1[2] >= 'A' and s2[2] <= 'C'))
	{
		cout << "1100" << endl;
		return 0;
	}
	
	if(abs(s1[2] - s2[2]) != 1)
	{
		cout << "1110" << endl;
		return 0;
	}
	
	cout << "1111" << endl;
}