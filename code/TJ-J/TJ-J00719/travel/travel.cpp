#include<bits/stdc++.h>
using namespace std;
char s1[5];
char s2[5];
char c1[5];
char c2[5]; 
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, s2;
	for(int i = 1; i <= 2; i++) {
		cin >> c1[i];
	}
	for(int i = 1; i <= 3; i++) {
		cin >> s1[i];
	}
	for(int i = 1; i <= 2; i++) {
		cin >> c2[i];
	}
	for(int i = 1; i <= 3; i++) {
		cin >> s2[i];
	}
	if(c1[1] == c2[1] && c1[2] == c2[2]) {
		printf("1");
	}
	else {
		printf("0");
	}
	if(c1[1] == c2[1] && c1[2] == c2[2] && s1[1] == s2[1] && s1[2] == s2[2]) {
		printf("1");
	}
	else {
		printf("0");
	}
	if(c1[1] == c2[1] && c1[2] == c2[2] && s1[1] == s2[1] && s1[2] == s2[2] && (((s1[3] == 'A' || s1[3] == 'B' || s1[3] == 'C') && (s2[3] == 'A' || s2[3] == 'B' || s2[3] == 'C')) || ((s1[3] == 'D' || s1[3] == 'F') && (s2[3] == 'D' || s2[3] == 'F')))) {
		printf("1");
	}
	else {
		printf("0");
	}
	char a1 = s1[3];
	char a2 = s2[3];
	if(a2 == 'F') {
		char(a2 = 'E');
	}
	if(c1[1] == c2[1] && c1[2] == c2[2] && s1[1] == s2[1] && s1[2] == s2[2] && (((s1[3] == 'A' || s1[3] == 'B' || s1[3] == 'C') && (s2[3] == 'A' || s2[3] == 'B' || s2[3] == 'C')) || ((s1[3] == 'D' || s1[3] == 'F') && (s2[3] == 'D' || s2[3] == 'F'))) && ((a1 != 'C' && a2 != 'D' || a1 != 'D' && a2 != 'C') && (int)(abs(a1-a2) == 1))) {
		printf("1");
	}
	else {
		printf("0");
	}
	return 0;
}
