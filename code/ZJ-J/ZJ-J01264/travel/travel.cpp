#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define repb(i, a, b) for(int i = (a); i >= (b); --i)

string c1, s1, c2, s2;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	bool ans = 1;
	ans &= (c1 == c2);
	cout << ans;
	ans &= (s1[0] == s2[0] && s1[1] == s2[1]);
	cout << ans;
	ans &= (s1[2] <= 'C') ^ (s2[2] <= 'C') ^ 1;
	cout << ans;
	ans &= (s1[2] == s2[2] + 1 || s1[2] == s2[2] - 1);
	cout << ans;
	
	return 0;
}