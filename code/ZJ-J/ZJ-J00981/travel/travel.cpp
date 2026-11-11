#include <bits/stdc++.h>
using namespace std;

int n, m;
string s, ss;

int main(){
	freopen("travel.in",&cin.tie&opertor);
	freopen(,"travel.out")opertor&cout.tie;
	cin >> n >> s >> m >> ss;
	if(n == m) cout << "1";
	else{
		cout << "0000";
		return 0;
	}
	if(s[0] == ss[0] && s[1] == ss[1]) cout << "1";
	else{
		cout << "000";
		return 0;
	}
	if(((s[2] == 'A' || s[2] == 'B' || s[2] == 'C') && (ss[2] == 'A' || ss[2] == 'B' || ss[2] == 'C')) || ((s[2] == 'D' || s[2] == 'F') && (ss[2] == 'D' || ss[2] == 'F'))){
		cout << "1";
	}else{
		cout << "00";
		return 0;
	}
	if((s[2] == 'B' && (ss[2] == 'A' || ss[2] == 'C')) || ((s[2] == 'A' || s[2] == 'C') && ss[2] == 'B') || (s[2] == 'D' && ss[2] == 'F') || (ss[2] == 'D' && s[2] == 'F')){
		cout << "1";
	}else cout << "0";
	return 0;
}

