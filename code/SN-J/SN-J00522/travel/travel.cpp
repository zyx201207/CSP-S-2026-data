#include <bits/stdc++.h>

using namespace std;
namespace eggy {
	void work() {
		string c1, s1, c2, s2;
		cin >> c1 >> s1 >> c2 >> s2;
		string f1, f2;
		f1[0] = s1[0];
		f1[1] = s1[1];
		f2[0] = s2[0];
		f2[1] = s2[1];
		char h1 = s1[2];
		char h2 = s2[2];
		if (c1 == c2) {
			cout << "1";
			if (f1[0] == f2[0] && f1[1] == f2[1]) cout << "1";
			else {
				cout << "000";
				return;
			}
			if (abs((int)(h1 - h2)) <= 2 && h1 != 'D' && h1 != 'F' && h2 != 'D' && h2 != 'F') cout << "1";
			else if ((h1 == 'D' && h1 == 'F') || (h2 == 'D' && h2 == 'F')) cout << "1";
			else {
				cout << "00";
				return;	
			}
			if (abs((int)(h1 - h2)) == 1 && h1 != 'D' && h1 != 'F' && h2 != 'D' && h2 != 'F') cout << "1";
			else if ((h1 == 'D' && h2 == 'F') || (h1 == 'F' && h2 == 'D')) cout << "1";
			else {
				cout << 0;
				return;
			}
		}
		else cout << "0000";
	}
}
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	return eggy::work(), 0;
}
/*
>v< >v< >v< >v<
AC AC AC AC AC 
*/
