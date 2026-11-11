//张睿航 SN-J00822 西安市第六中学 
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string zhc1, zhc2, zhs1, zhs2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> zhc1 >> zhs1 >> zhc2 >> zhs2;
	cout << bool(zhc1 == zhc2);
	char c1 = zhs1[2], c2 = zhs2[2];
	string s1 = zhs1.substr(0, 2), s2 = zhs2.substr(0, 2);
	cout << bool(zhc1 == zhc2 && s1 == s2);
	cout << bool(zhc1 == zhc2 && s1 == s2 && ((c1 < 'D' && c2 < 'D') || (c1 > 'C' && c2 > 'C')));
	cout << bool(zhc1 == zhc2 && s1 == s2 && ((c1 < 'D' && c2 < 'D') || (c1 > 'C' && c2 > 'C')) && (c1 + 1 == c2 || c2 + 1 == c1));
//	cout << c1 << c2;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
