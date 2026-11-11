#include <bits/stdc++.h>
#define ll long long
using namespace std;

string a1, a2, b1, b2;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a1 >> b1 >> a2 >> b2;
	// 是否在同一节车厢 
	if(a1 == a2){
		cout << "1";
		// 是否在同一节车厢的同一排 
		if(b1[0] == b2[0] && b1[1] == b2[1]){
			cout << "1";
			// 且位于过道的同一侧
			if(((b1[2] == 'A' || b1[2] == 'B' || b1[2] == 'C') && (b2[2] == 'A' || b2[2] == 'B' || b2[2] == 'C')) ||
			((b1[2] == 'D' || b1[2] == 'F') && (b2[2] == 'D' || b2[2] == 'F'))){
				cout << "1";
				// 是否相邻
				int a = b1[2] - 'A';
				int b = b2[2] - 'A';
				if(abs(a-b) == 1){
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
