#include<bits/stdc++.h>
using namespace std;
//100
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, s2, n, m;
	cin >> n >> s1;
	cin >> m >> s2;
	if(n != m)
	{
		cout << "0000" << endl;
		return 0;
	}
	int xa = s1[0] * 10 + s1[1];
	int xb = s2[0] * 10 + s2[1];
	if(xa != xb) 
	{
		cout << "1000" << endl;
		return 0;
	}
	if(!((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'A') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')))
	{
		cout << "1100" << endl;
		return 0;
	}
	if(((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')))
	{
		cout << "1111" << endl;
		return 0;
	}
	cout << "1110" << endl;
	return 0;
} 
