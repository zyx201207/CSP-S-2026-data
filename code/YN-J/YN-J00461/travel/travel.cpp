#include <bits/stdc++.h>
using namespace std;
#define in cin
#define out cout
#define int long long

signed main() {
	freopen("travel.in", "r", stdin), freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false), in.tie(nullptr), out.tie(nullptr);
	string s1, s2, s3, s4; in >> s1 >> s2 >> s3 >> s4;
	out << (s1 == s3) << (s1 == s3 && s2[0] == s4[0] && s2[1] == s4[1]) << (s1 == s3 && s2[0] == s4[0] && s2[1] == s4[1] && s2[2] <= 'C' && s4[2] <= 'C');
	out << (s1 == s3 && s2[2] <= 'C' && s4[2] <= 'C' && s2[0] == s4[0] && s2[1] == s4[1] && min(s2[2], s4[2]) + 1 == max(s2[2], s4[2]));
	return 0;
}