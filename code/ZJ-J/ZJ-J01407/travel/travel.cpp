#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string C1_c,S1_s,C2_c,S2_s;
	cin >> C1_c >> S1_s>>C2_c>>S2_s;
	if(C1_c == C2_c){
		cout << 1;
		if((S2_s[0] == S2_s[0])&&(S1_s[1] == S2_s[1])){
			cout << 1;
			if((S2_s[2] <= 'C')&&(S1_s[2] <= 'C')){
				cout << 1;
				int nn = int(S2_s[2]),mm = int(S1_s[2]);
				int kpp = abs(nn-mm);
				if(kpp == 1){
					cout << 1;
				}
				else cout << 0;
			}
			else if((S2_s[2] <= 'E')&&(S1_s[2] <= 'E')&&(S2_s[2] >= 'D')&&(S1_s[2] >= 'D')){
				cout << 1;
				int nn = int(S2_s[2]),mm = int(S1_s[2]);
				int kpp = abs(nn-mm);
				if(kpp == 1){
					cout << 1;
				}
				else cout << 0;
			}
			else cout << "00";
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