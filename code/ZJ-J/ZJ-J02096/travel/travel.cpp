#include<bits/stdc++.h>
using namespace std;

const int side[] = {1, 1, 1, 2, 2};

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int s11, s21;
	char s12, s22;
	string c1, c2;
	cin >> c1 >> s11 >> s12 >> c2 >> s21 >> s22;
	if(c1 == c2) cout << 1;
	else cout << 0;
	if(c1 == c2 && s11 == s21) cout << 1;
	else cout << 0;
	if(c1 == c2 && s11 == s21 && side[s12 - 'A'] == side[s22 - 'A']) cout << 1;
	else cout << 0;
	if(c1 == c2 && s11 == s21 && side[s12 - 'A'] == side[s22 - 'A'] && abs(s12 - s22) == 1) cout << 1;
	else cout << 0;
	return 0;
}
