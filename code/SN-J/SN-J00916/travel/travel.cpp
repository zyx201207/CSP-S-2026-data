#include <bits/stdc++.h>
using namespace std;

string c1, c2, c3, c4;
int cnt1, cnt2, cnt3, cnt4;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> c2 >> c3 >> c4;
	if (c1 == c3){
		cnt1 = 1;
	}
	if (c2[0] == c4[0] && c2[1] == c4[1]){
		cnt2 = 1;
	}
	if (c2[2] == 'A'){
		if (c2[2] + 1 == c4[2] || c2[2] + 2 == c4[2]){
			cnt3 = 1;
			if (c2[2] + 1 == c4[2]){
				cnt4 = 1;
			}
		}
	}
	else if (c2[2] == 'B'){
		if (c2[2] + 1 == c4[2] || c2[2] - 1 == c4[2]){
			cnt3 = 1;
			cnt4 = 1;
		}
	}
	else if (c2[2] == 'C'){
		if (c2[2] - 1 == c4[2] || c2[2] - 2 == c4[2]){
			cnt3 = 1;
			if (c2[2] - 1 == c4[2]){
				cnt4 = 1;
			}
		}
	}
	else if (c2[2] == 'D'){
		if (c2[2] + 1 == c4[2]){
			cnt3 = 1;
			cnt4 = 1;
		}
	}
	else if (c2[2] == 'F'){
		if (c2[2] - 1 == c4[2]){
			cnt3 = 1;
			cnt4 = 1;
		}
	}
	cout << cnt1 << cnt2 << cnt3 << cnt4;
	return 0;
}
