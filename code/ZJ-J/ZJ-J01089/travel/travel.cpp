#include <iostream>
#include <string>
#include <stdio.h>

using  namespace  std;

bool  mp[] = {1, 1, 1, 0, 0};
bool  f1, f2, f3, f4;
string  t1, t2;
string  s1, s2;

int  main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> t1 >> s1 >> t2 >> s2;
	
	if(t1 == t2) { f1 = 1;
		if(s1[0] == s2[0] && s1[1] == s2[1]) { f2 = 1;
			int  a = s1[2] - 'A', b = s2[2] - 'A';
			if(mp[a] == mp[b]) { f3 = 1;
				if(a - b == 1 || b - a == 1)  f4 = 1; } } }
	cout << f1 << f2 << f3 << f4;
	return  0;
}
