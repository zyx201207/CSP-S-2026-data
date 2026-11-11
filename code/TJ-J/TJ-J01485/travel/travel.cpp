#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
int t[5];
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	if (a == c){
		t[1] = 1;
		string x, y;
		x = "";
		y = "";
		x += b[0];
		x += b[1];
		y += d[0];
		y += d[1];
		if (x == y){
			t[2] = 1;
			char i, j;
			i = b[2];
			j = d[2];
			if ((i - 'A' >= 0 && i - 'A' <= 2 && j - 'A' >= 0 && j - 'A' <= 2) || (i == 'D' && j == 'F') || (i == 'F' && j == 'D')){
				t[3] = 1;
				if ((i == 'A' && j == 'B') || (i == 'B' && j == 'A') || (i == 'B' && j == 'C') || (i == 'C' && j == 'B') || (i == 'D' && j == 'F') || (i == 'F' && j == 'D')){
					t[4] = 1;
				}
			}
		}
	}
	cout << t[1] << t[2] << t[3] << t[4];
	return 0;
} 
