#include<bits/stdc++.h>
using namespace std;
char c1[2], s1[3], c2[2], s2[3];
int a = 0, b = 0, c = 0, d = 0;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
	for (int i = 0; i < 2; i ++) cin >> c1[i];
	for (int i = 0; i < 3; i ++) cin >> s1[i];
	for (int i = 0; i < 2; i ++) cin >> c2[i];
	for (int i = 0; i < 3; i ++) cin >> s2[i];
	if (c1[0] == c2[0]) a = 1;
	if (c1[1] == c2[1]) b = 1;
	if (a == 1 && b == 1) cout << '1';
	else cout << '0';
	if (s1[0] == s2[0]) c = 1;
	if (s1[1] == s2[1]) d = 1;
	if (a == 1 && b == 1 && c == 1 && d == 1) cout << '1';
	else cout << '0';
	if (a == 1 && b == 1 && ((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A') ||  (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D') || (s1[2] == 'C' && s2[2] == 'A'))) cout << '1';
	else cout << '0';
	if (a == 1 && b == 1 && ((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A') ||  (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D'))) cout << '1';
	else cout << '0';
	return 0;
} 
