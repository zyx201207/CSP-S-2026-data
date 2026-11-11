#include <bits/stdc++.h>
#define int long long int
#define st string
#define re return
using namespace std;
int x, y;
st str1, str2;
bool a, b, c, d;
signed main(){
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	
	cin >> x >> str1 >> y >> str2;
	if (x == y) {
		a = true;
		if (str1[0] == str2[0] && str1[1] == str2[1]) {
			b = true;
			if (!((str1[2] == 'A' || str1[2] == 'B' || str1[2] == 'C') &&
				(str2[2] == 'D' || str2[2] == 'E'))) {
				c = true;
				if (str1[2] + 1 == str2[2] || str2[2] + 1 == str1[2] ||
					(str1[2] == 'D' && str2[2] == 'F') || (str1[2] == 'F' && str2[2] == 'D')) {
					d = true;
				}
			}
		}
	}
	cout << a << b << c << d << endl;
	
	fclose (stdin);
	fclose (stdout);

	re 0;
}
