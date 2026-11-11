#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string s1, s2, ss1, ss2;
	cin >> s1 >> s2 >> ss1 >> ss2;
	cout << (s1 == ss1) << (s1 == ss1 && s2[0] == ss2[0] && s2[1] == ss2[1]) << (s1 == ss1 && s2[0] == ss2[0] && s2[1] == ss2[1] && ((s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') && (ss2[2] == 'A' || ss2[2] == 'B' || ss2[2] == 'C') || ((s2[2] == 'D' || s2[2] == 'F') && (ss2[2] == 'D' || ss2[2] == 'F')))) << (s1 == ss1 && s2[0] == ss2[0] && s2[1] == ss2[1] && (s2[2] == 'A' && ss2[2] == 'B' || s2[2] == 'B' && ss2[2] == 'A' || s2[2] == 'B' && ss2[2] == 'C' || s2[2] == 'C' && ss2[2] == 'B' || s2[2] == 'D' && ss2[2] == 'F' || s2[2] == 'F' && ss2[2] == 'D')) << '\n';
	
	return 0;
}
//rp++
