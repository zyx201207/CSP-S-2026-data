#include <bits/stdc++.h>
using namespace std;

char  s1, s2;
int c1, c2;
int s11, s22;

bool check(){
	if(s1 == 'F' && s2 == 'D') return true;
	else if(s1 == 'D' && s2 == 'F') return true;
	else if(s1 == 'A' && s2 == 'B' || s2 == 'C') return true;
	else if(s1 == 'B' && s2 == 'A' || s2 == 'C') return true;
	else if(s1 == 'C' && s2 == 'B' || s2 == 'A') return true;
	else return false;
}

bool check2(){
	if(s1 == 'F' && s2 == 'D') return true;
	else if(s1 == 'D' && s2 == 'F') return true;
	else if(s1 == 'A' && s2 == 'B') return true;
	else if(s1 == 'B' && s2 == 'A' || s2 == 'C') return true;
	else if(s1 == 'C' && s2 == 'B') return true;
	else return false;
}

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w" , stdout);
	cin >> c1 >> s11  >> s1 >> c2 >> s22 >> s2;
	if(c1 == c2) cout << 1;
	else cout << 0;
	if(c1 == c2 && s11 == s22) cout << 1;
	else cout << 0;
	if(c1 == c2 && s11 == s22 && check()) cout << 1;
	else cout << 0;
	if(c1 == c2 && s11 == s22 && check2()) cout << 1;
	else cout << 0;
	return 0;
}
