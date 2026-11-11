#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
string c1, c2, s1, s2;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	bool a=(c1==c2), b=(s1[0]==s2[0] && s1[1]==s2[1]), c=0, d=0;
	cout<<a;
	cout<<(a&&b);
	if(a&&b) {
		set<char> le({'A', 'B', 'C'}), ri({'D', 'F'});
		if(le.count(s1[2]) && le.count(s2[2])) {
			c=1;
			if(s1[2]+1==s2[2] || s1[2]-1==s2[2]) d=1;
		}
		if(ri.count(s1[2]) && ri.count(s2[2])) c=d=1;
	}
	cout<<c<<d;
    return 0;
}
