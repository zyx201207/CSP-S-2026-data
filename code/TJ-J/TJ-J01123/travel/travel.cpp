#include<bits/stdc++.h>
using namespace std;
string 	C1, S1, C2, S2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> C1 >> S1 >> C2 >> S2;
	if (C1 == C2) cout << 1; 
	else {
		cout << "0000";
		return 0;
	}
	if (S1[0] == S2[0] && S1[1] == S2[1])
		cout << 1;
	else cout << 0;
	if (S1[2] == 'A' || S1[2] == 'B' || S1[2] == 'C' && S2[2] == 'A' || S2[2] == 'B' || S2[2] == 'C')
		cout << 1;
	else if (S1[2] == 'D' || S1[2] == 'F' && S2[2] == 'D' || S2[2] == 'F')
		cout << 1;
	else cout << 0;
	if (S1[2] == 'A' && S2[2] == 'B') cout << 1;
	if (S1[2] == 'A' && S2[2] == 'C') cout << 0;
	if (S1[2] == 'B' && S2[2] == 'A') cout << 1;
	if (S1[2] == 'B' && S2[2] == 'C') cout << 1;
	if (S1[2] == 'C' && S2[2] == 'A') cout << 0;
	if (S1[2] == 'C' && S2[2] == 'B') cout << 1;
	if (S1[2] == 'D' && S2[2] == 'F') cout << 1;
	if (S1[2] == 'F' && S2[2] == 'D') cout << 1;
	return 0;
}
