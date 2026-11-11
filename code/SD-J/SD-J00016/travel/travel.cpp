#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
#define ll long long
#define endl '\n'
int Int(char c) { return c-'0'; }
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a, b; string s, t;
	cin >> a >> s >> b >> t;
	int A = 10 * Int(s[0]) + Int(s[1]), B = 10 * Int(t[0]) + Int(t[1]);
	if(s[2] == 'F') s[2] = 'E';
	if(t[2] == 'F') t[2] = 'E';
	
	bool f1 = a == b;
	bool f2 = f1 && A == B;
	bool f3 = f2 && (s[2] <= 'C' && t[2] <= 'C' || s[2] > 'C' && t[2] > 'C');
	bool f4 = f3 && (abs((int)s[2] - t[2]) == 1);
	cout << f1 << f2 << f3 << f4;
	return 0;
}

