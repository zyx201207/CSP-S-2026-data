#include<bits/stdc++.h>
using namespace std;
string s1, s2, s3, s4;
bool a, b, c, d;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1 == s3){
		a = 1;
		if(s2[0] == s4[0] && s2[1] == s4[1]){
			b = 1;
			int x = s2[2] - 'A' + 1;
			int y = s4[2] - 'A' + 1;
			if((x >= 1 && x <= 3 && y >= 1 && y <= 3) || (x >= 4 && x <= 6 && y >= 4 && y <= 6)){
				c = 1;
				if(x + 1 == y || y + 1 == x){
					d = 1;
				}
				if((x == 4 && y == 6) || (x == 6 || y == 4)){
					d = 1;
				}
			}
		}
	}
	cout << a << b << c << d;
	return 0;
}
