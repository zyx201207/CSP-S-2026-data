#include <bits/stdc++.h>
using namespace std;

string a, b;
string s1, s2;
bool f[10];
char f_or_r(string s){
	if (s[2] == 'A' || s[2] == 'B' || s[2] == 'C') return 'f';
	else return 'r';
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> s1 >> b >> s2;
	//cout << a << " " << s1 << " " << b << " " << s2 << "\n";
	if (a[0] == b[0] && a[1] == b[1]) f[1] = true; 
	if (s1[0] == s1[0] && s1[1] == s2[1] && f[1] == true) f[2] = true;
	if (f_or_r(s1) == f_or_r(s2) && f[2] == true) f[3] = true;
	if (int(abs(s1[2] - s2[2])) == 1 && f[3] == true) f[4] = true;
	for (int i = 1; i <= 4; i++) cout << f[i];
	return 0;
}
