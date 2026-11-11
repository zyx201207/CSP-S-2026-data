#include <bits/stdc++.h>
using namespace std;
string cr, sr, cx, sx;
bool f = 0, fl = 0;
char c[4] = {'A', 'B', 'C'};
char d[3] = {'D', 'F'};
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> cr >> sr >> cx >> sx;
	if (cr == cx){
		cout << 1;
		if (sr.substr(0, 2) == sx.substr(0, 2)){
			cout << 1;
			if ((sr[2] == 'D' || sr[2] == 'F') && (sx[2] == 'D' || sx[2] == 'F')){
				f = 1;
			}
			else{
				for (int i = 0; i < 3; i++){
					if (sx[2] == c[i]){
						f = 1;
						break;
					}
				}
			}
			if (f){
				cout << 1;
				for (int i = 0; i < 3; i++){
					if (sr[2] == c[i]){
						if (i == 0){
							if (sx[2] == c[i + 1]){
								fl = 1;
								break;
							}
						}
						else if (i == 2){
							if (sx[2] == c[i - 1]){
								fl = 1;
								break;
							}
						}
						else{
							if (sx[2] == c[i - 1] || sx[2] == c[i + 1]){
								fl = 1;
								break;
							}
						}
					}
				}
				if ((sr[2] == 'D' && sx[2] == 'F') || (sr[2] == 'F' && sx[2] == 'D')){
					fl = 1;
				}
				if (fl){
					cout << 1;
				}
				else{
					cout << 0;
				}
			}
			else{
				cout << "00";
			}
		}
		else{
			cout << "000";
		}
	}
	else{
		cout << "0000";
	}
	return 0;
}
