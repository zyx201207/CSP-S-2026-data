#include <bits/stdc++.h>
using namespace std;
bool check(char n, char m){
	if (n == 'A' or n == 'B' or n == 'C'){
		if (m == 'D' or m == 'F') return false;
		else return true;
	} else {
		if (m == 'D' or m == 'F') return true;
		else return false;
	}
}
bool check1(char n, char m){
	if (n == 'A' and m == 'B') return true;
	if (n == 'B' and m == 'C') return true;
	if (n == 'D' and m == 'F') return true;
	return false;
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int n = (s2[0] - '0') * 10 + (s2[1] - '0');
	int m = (s4[0] - '0') * 10 + (s4[1] - '0');
	char c1 = s2[2], c2 = s4[2];
	if (c1 > c2) swap(c1, c2);
	if (s1 == s3){
		cout << "1";
		if (n == m){
			cout << "1";
			if (check(c1, c2)){
				cout << "1";
				if (check1(c1, c2)){
					cout << "1";
				} else {
					cout << "0";
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}