#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int N = 1e5 + 5;
int x, y;
char a[5], b[5];
signed main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	cin >> x>> (a + 1)>> y>> (b + 1);
	if (x == y){
		cout << 1;
		if (a[1] == b[1] && a[2] == b[2]){
			cout << 1;
			if ((a[3] >= 'A' && a[3] <= 'C') && (b[3] >= 'A' && b[3] <= 'C')){
				cout << 1;
				if (abs(a[3] - b[3]) == 1) cout << 1;
				else cout << 0;
			} 
			else if((a[3] == 'D' || a[3] == 'F') && (b[3] == 'D' || b[3] == 'F')){
				cout << 1;
				if (abs(a[3] - b[3]) == 1) cout << 1;
				else cout << 0;
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
return 0;
}
