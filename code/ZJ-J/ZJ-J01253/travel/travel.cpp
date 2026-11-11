#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string cR, sR, cX, sX;
	cin >> cR >> sR >> cX >> sX;
	if(cR == cX){
		cout << "1";
		if(sR[0] == sX[0] && sR[1] == sX[1]){
			cout << "1";
			if((sR[2] >= 'A' && sR[2] <= 'C' && sX[2] >= 'A' && sX[2] <= 'C') || (sR[2] >= 'D' && sR[2] <= 'F' && sX[2] >= 'D' && sX[2] <= 'F')){
				cout << "1";
				if(sR[2] >= 'A' && sR[2] <= 'C' && sX[2] >= 'A' && sX[2] <= 'C'){
					int minn = min((sR[2]-'A'), (sX[2]-'A')), maxn = max((sR[2]-'A'), (sX[2]-'A'));
					if(maxn-minn == 1){
						cout << "1";
					}
					else{
						cout << "0";
					}
				}
				else{
					cout << "1";
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