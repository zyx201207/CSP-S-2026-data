#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long 

string c1, s1, c2, s2;
bool ans1, ans2, ans3, ans4;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);	

	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
		ans1 = 1;
	else
	{
		cout << "0000" << endl;
		return 0;
	}
		
	if (s1[0] == s2[0] && s1[1] == s2[1])
		ans2 = 1;
	else
	{
		cout << "1000" << endl;
		return 0;
	}
		
	if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D'))
		ans3 = 1;
	else
	{
		cout << "1100" << endl;
		return 0;
	}
		
	if ((s1[2] == char(s2[2] + 1) || s1[2] == char(s2[2] - 1)) || (s1[2] >= 'D' && s2[2] >= 'D'))
		ans4 = 1;
	else
	{
		cout << "1110" << endl;
		return 0;
	}
	
	cout << ans1 << ans2 << ans3 << ans4;
	return 0;	
} 
