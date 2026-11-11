//SN-J01043
#include<bits/stdc++.h>
using namespace std;
constexpr int N = 10;
char c2[N], s2[N], c1[N], s1[N];
bool ok = 1;
int ans[N];
int arc(char c){
	if (c <= 'C') return 0;
	return 1;
}
int intg(char c){
	if (c == 'F') c = 'E';
	return c - 'A' + 1;
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out","w", stdout);
	cin >> (c1 + 1) >> (s1 + 1) >> (c2 + 1) >> (s2 + 1);
	ok &= (c1[1] == c2[1] && c1[2] == c2[2]);
	if (ok) ans[1] = 1;
	ok &= (s1[1] == s2[1] && s1[2] == s2[2]);
	if (ok) ans[2] = 1;
	ok &= (arc(s1[3]) == arc(s2[3]));
	if (ok) ans[3] = 1;
	int maxn = max(intg(s1[3]), intg(s2[3])), 
	minn = min(intg(s1[3]), intg(s2[3]));
	ok &= (maxn - minn == 1);
	if (ok) ans[4] = 1;
	for (int i = 1; i <= 4; i++) cout << ans[i];
}
