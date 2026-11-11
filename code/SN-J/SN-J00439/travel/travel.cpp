#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1, s1, c2, s2;
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
		cout << 1;
	else
		cout << 0;
	if((c1 == c2) &&
	   (s1[0] == s2[0] && s1[1] == s2[1]))
		cout << 1;
	else
		cout << 0;
	char C1 = s1[2], C2 = s2[2];
	if((c1 == c2) &&
	   (s1[0] == s2[0] && s1[1] == s2[1]) &&
	   ((('A' <= C1 && C1 <= 'C') && ('A' <= C2 && C2 <= 'C')) || ('D' <= C1 && C1 <= 'E') && ('D' <= C2 && C2 <= 'E')))
	   	cout << 1;
	else
		cout << 0;
	char _C1 = char(C1 + 1);
	char _C2 = char(C2 + 1);
	if((c1 == c2) &&
	   (s1[0] == s2[0] && s1[1] == s2[1]) &&
	   ((('A' <= C1 && C1 <= 'C') && ('A' <= C2 && C2 <= 'C')) || ('D' <= C1 && C1 <= 'E') && ('D' <= C2 && C2 <= 'E')) &&
	   (_C1 == C2 || _C2 == C1))
		cout << 1;
	else
		cout << 0;
	return 0;
}
