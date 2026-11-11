#include <bits/stdc++.h>

#define int long long 

using namespace std;

string c1, c2;
string s1, s2;
int num[100010];

void solve() {
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) {
		cout << "1";
		if(s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << "1";
			num[s1[2] - 'A'] ++ ;
			num[s2[2] - 'A'] ++ ;	
			int sz = 0;
			for(int i = 0; i < 3; i ++ ) 
				sz += num[i];
			if(sz == 2 || !sz) {
				cout << "1";
				if((!sz) || (num[0] && num[1]) || (num[1] && num[2])) {
					cout << "1";
				}
				else {
					cout << "0";
				}
			}
			else {
				cout << "00";
			}
		}
		else {
			cout << "000";
		}
	}
	else {
		cout << "0000";
	}
}

signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int t; t = 1;
	while(t -- ) solve();
	return 0;
} 
