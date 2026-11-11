#include<bits/stdc++.h>
#define pb push_back
#define int long long
#define zxh(x, y, z, qwq) for(int qwq = x; qwq <= y; qwq += z)
#define dxh(x, y, z, qwq) for(int qwq = x; qwq >= y; qwq -= z)
using namespace std;

string s1, s2, c1, c2;

signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> s1 >> s2 >> c1 >> c2;
	if(s1 == c1) cout << 1;
	else cout << 0;
	if(s2[0] == c2[0] && s2[1] == c2[1] && s1 == c1){
		cout << 1; 
	} else {
		cout << 0;
	}
	if(s2[0] == c2[0] && s2[1] == c2[1] && s1 == c1){
		if(s2[2] == 'A'){
			if(c2[2] == 'B' || c2[2] == 'C') cout << 1;
			else cout << 0;
		} else if(s2[2] == 'B') {
			if(c2[2] == 'A' || c2[2] == 'C') cout << 1;
			else cout << 0;
		} else if(s2[2] == 'C') {
			if(c2[2] == 'B' || c2[2] == 'A') cout << 1;
			else cout << 0;
		} else if(s2[2] == 'D') {
			if(c2[2] == 'F') cout << 1;
			else cout << 0;
		} else if(s2[2] == 'F') {
			if(c2[2] == 'D') cout << 1;
			else cout << 0;
		}
	} else {
		cout << 0;
	}
	if(s2[0] == c2[0] && s2[1] == c2[1]){
		if(s2[2] == 'A'){
			if(c2[2] == 'B') cout << 1;
			else cout << 0;
		} else if(s2[2] == 'B') {
			if(c2[2] == 'A' || c2[2] == 'C') cout << 1;
			else cout << 0;
		} else if(s2[2] == 'C') {
			if(c2[2] == 'B') cout << 1;
			else cout << 0;
		} else if(s2[2] == 'D') {
			if(c2[2] == 'F') cout << 1;
			else cout << 0;
		} else if(s2[2] == 'F') {
			if(c2[2] == 'D') cout << 1;
			else cout << 0;
		}
	} else {
		cout << 0;
	}
	return 0;
} 

/*
T1À×öª´óÄ£Äâ25minÄÃÏÂ 
*/

