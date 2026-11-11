#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100010;
string c1, s1, c2, s2;
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	cout << (c1 == c2);
	cout << ((c1 == c2) && (s1[1] == s2[1] && s1[0] == s2[0]));
//	cout << (s1[1] == s2[1] && s1[0] == s2[0]);
	cout << ((c1 == c2) && (s1[1] == s2[1] && s1[0] == s2[0]) && ((s1[2] <= 'C') && (s2[2] <= 'C') || (s1[2] > 'C') && (s2[2] > 'C')));
	cout << ((c1 == c2) && (s1[1] == s2[1] && s1[0] == s2[0]) && ((s1[2] <= 'C') && (s2[2] <= 'C') && abs(s1[2] - s2[2] == 1) || (s1[2] > 'C') && (s2[2] > 'C')));
	return 0;
}
//100pts
//checked 
//O(1)
