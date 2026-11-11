#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[5], t[5];
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s >> m >> t;
	if(n == m){
		if((s[0] == t[0]) && (s[1] == t[1])){
			if(((s[2] == 'A') && (t[2] == 'B')) || ((s[2] == 'B') && (t[2] == 'A')) || ((s[2] == 'C') && (t[2] == 'B')) || ((s[2] == 'B') && (t[2] == 'C')) || ((s[2] == 'C') && (t[2] == 'A')) || ((s[2] == 'A') && (t[2] == 'C')) || ((s[2] == 'D') && (t[2] == 'E')) || ((s[2] == 'E') && (t[2] == 'D'))){
				if(((s[2] == 'A') && (t[2] == 'B')) || ((s[2] == 'B') && (t[2] == 'A')) || ((s[2] == 'C') && (t[2] == 'B')) || ((s[2] == 'B') && (t[2] == 'C')) || ((s[2] == 'D') && (t[2] == 'E')) || ((s[2] == 'E') && (t[2] == 'D')))
					cout << 1111 << '\n';
				else
					cout << 1110 << '\n';
			}
			else
				cout << 1100 << '\n';
		}
		else
			cout << 1000 << '\n';
	}
	else
		cout << "0000" << '\n';
}
