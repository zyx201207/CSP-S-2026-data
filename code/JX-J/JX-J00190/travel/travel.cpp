#include<bits/stdc++.h>
using namespace std;
#define int long long

int a, b;
string s;
string t;
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> s;
	cin >> b >> t;
	if(a == b) cout << 1;
	else cout << 0;
	if(a == b && (s[0] == t[0] && s[1] == t[1])) cout << 1;
	else cout << 0;
    if(a == b && (s[0] == t[0] && s[1] == t[1]) && ((s[2] >= 'D' && t[2] >='D') || (s[2] <= 'C' && t[2] <= 'C'))) cout << 1;
    else cout << 0;
    if(a == b && (s[0] == t[0] && s[1] == t[1]) && ((s[2] >= 'D' && t[2] >='D') || (s[2] <= 'C' && t[2] <= 'C')) && abs(s[2] - t[2]) <= 1) cout << 1;
    else cout << 0;
    
    return 0;
}
