#include <bits/stdc++.h>
using namespace std;
int rc, xc;
int rp, xp;
char rl, xl;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> rc >> rp >> rl >> xc >> xp >> xl;
	if (rc != xc){
		cout << "0000";
	}else{
		cout << 1;
		if (rp != xp){
			cout << "000";
		}else{
			cout << 1;
			if (!((rl <= 'C' && xl <= 'C') || (rl >= 'D' && xl >= 'D'))){
				cout << "00";
			}else{
				cout << "1";
				if ((rl >= 'D' && xl >= 'D') || abs((int)rl - (int)xl) == 1){
					cout << "1";
				}else{
					cout << "0";
				}
			}
		}
	}
	return 0;
}
