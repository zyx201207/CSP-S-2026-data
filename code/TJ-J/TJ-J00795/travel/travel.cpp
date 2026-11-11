#include<bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;
int ans1, ans2, ans3, ans4;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) {
		ans1 = 1;
		if(s1.substr(0, 2) == s2.substr(0, 2)) {
			ans2 = 1;
			if(('A'<=s1[2]&&s1[2]<='C') == ('A'<=s2[2]&&s2[2]<='C')) {
				ans3 = 1;
				ans4 = 1;
				if(s1[2]=='A'&&s2[2]=='C' || s1[2]=='C'&&s2[2]=='A') ans4 = 0;
			}
		}
	}
	cout << ans1 << ans2 << ans3 << ans4 << endl;
	return 0;
}
