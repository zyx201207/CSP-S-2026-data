#include <iostream>
#include <cstdio>
#include <string>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool ans1, ans2, ans3, ans4;
	ans1 = c1 == c2;
	ans2 = ans1 && s1[0] == s2[0] && s1[1] == s2[1];
	int lr1, lr2;
	if(s1[2] <= 'C') lr1 = 1;
	else lr1 = 2;
	if(s2[2] <= 'C') lr2 = 1;
	else lr2 = 2;
	ans3 = ans2 && (lr1 == lr2);
	// cerr << s1[2] << " " << s2[2] << "\n";
	ans4 = ans3 && ( !((s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'A')) );
	putchar(ans1 + '0');
	putchar(ans2 + '0');
	putchar(ans3 + '0');
	putchar(ans4 + '0');
	putchar('\n');
	return 0;
}
/* fo zu bao you    mei you bug */
