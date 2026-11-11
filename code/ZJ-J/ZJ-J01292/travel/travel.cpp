#include <bits/stdc++.h>
using namespace std;

string s1, s2, s3, s4;
int judge1()
{
	if(s1 == s3) return 1;
	return 0;
}
int judge2()
{
	if(!judge1()) return 0;
	if(s2[0] != s4[0]) return 0;
	if(s2[1] != s4[1]) return 0;
	return 1;
}
int judge3()
{
	if(!judge2()) return 0;
	if(s2[2] == 'A' && s4[2] == 'B') return 1;
	if(s2[2] == 'A' && s4[2] == 'C') return 1;
	if(s2[2] == 'B' && s4[2] == 'A') return 1;
	if(s2[2] == 'B' && s4[2] == 'C') return 1;
	if(s2[2] == 'C' && s4[2] == 'A') return 1;
	if(s2[2] == 'C' && s4[2] == 'B') return 1;
	if(s2[2] == 'D' && s4[2] == 'F') return 1;
	if(s2[2] == 'F' && s4[2] == 'D') return 1;
	return 0;
}
int judge4()
{
	if(!judge3()) return 0;
	if(abs(s2[2] - s4[2]) == 1) return 1;
}
signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	cout << judge1();
	cout << judge2();
	cout << judge3();
	cout << judge4();
	puts("");
	return 0;
}
