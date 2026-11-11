#include <bits/stdc++.h>
using namespace std;

string a, A, b, B;

bool F1(){
	if(A == B) return true;
	else return false;
}

bool F2(){
	if(A != B) return false;
	if(a[0] == b[0] && a[1] == b[1]) return true;
	return false;
}

bool F3(){
	if(A != B) return false;
	if(a[0] != b[0] || a[1] != b[1]) return false;
	if(a[2] == 'A' && b[2] == 'B') return true;
	if(a[2] == 'A' && b[2] == 'C') return true;
	if(a[2] == 'B' && b[2] == 'A') return true;
	if(a[2] == 'B' && b[2] == 'C') return true;
	if(a[2] == 'C' && b[2] == 'B') return true;
	if(a[2] == 'C' && b[2] == 'A') return true;
	if(a[2] == 'D' && b[2] == 'F') return true;
	if(a[2] == 'F' && b[2] == 'D') return true;
	return false;
}

bool F4(){
	if(A != B) return false;
	if(a[0] != b[0] || a[1] != b[1]) return false;
	if(a[2] == 'A' && b[2] == 'B') return true;
	if(a[2] == 'B' && b[2] == 'A') return true;
	if(a[2] == 'B' && b[2] == 'C') return true;
	if(a[2] == 'C' && b[2] == 'B') return true;
	if(a[2] == 'D' && b[2] == 'F') return true;
	if(a[2] == 'F' && b[2] == 'D') return true;
	return false;
}

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> A >> a >> B >> b;
	if(F1()) cout << 1;
	else cout << 0;
	if(F2()) cout << 1;
	else cout << 0;
	if(F3()) cout << 1;
	else cout << 0;
	if(F4()) cout << 1;
	else cout << 0;
	return 0;
}
