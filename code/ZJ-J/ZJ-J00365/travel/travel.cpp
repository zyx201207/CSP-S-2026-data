#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, c1, s2, c2;
	cin >> s1 >> c1 >> s2 >> c2;
	int f1 = 0, f2 = 0, f3 = 0, f4 = 0;
	if(s1 == s2){
		f1 = 1;
		if(c1[0] == c2[0] && c1[1] == c2[1]){
			f2 = 1;
			if((c1[2] >= 'A' && c1[2] <= 'C' && c2[2] >= 'A' && c2[2] <= 'C') || (c1[2] >= 'D' && c1[2] <= 'F' && c2[2] >= 'D' && c2[2] <= 'F')){
				f3 = 1;
				if((c1[2] >= 'D' && c1[2] <= 'F' && c2[2] >= 'D' && c2[2] <= 'F') || (c1[2] >= 'A' && c1[2] <= 'C' && c2[2] >= 'A' && c2[2] <= 'C' && abs(c1[2]-c2[2]) == 1)){
					f4 = 1;
				}
			}
		}
	}
	cout << f1 << f2 << f3 << f4;
	return 0;
}
