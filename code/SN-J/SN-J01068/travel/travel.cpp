#include <bits/stdc++.h>
using namespace std;

int c1, c2, sn1, sn2, sc1, sc2;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// input
	char tc1, tc2, tsn1, tsn2, tsc;
	cin >> tc1 >> tc2 >> tsn1 >> tsn2 >> tsc;
	c1 = int(tc1 - '0')*10 + int(tc2 - '0');
	sn1 = int(tsn1 - '0')*10 + int(tsn2 - '0');
	sc1 = int(tsc) - 64;
	if(tsc == 'D'){
		sc1++;
	}
	cin >> tc1 >> tc2 >> tsn1 >> tsn2 >> tsc;
	c2 = int(tc1 - '0')*10 + int(tc2 - '0');
	sn2 = int(tsn1 - '0')*10 + int(tsn2 - '0');
	sc2 = int(tsc) - 64;
	if(tsc == 'D'){
		sc2++;
	}
	
	// solve & print
	if(c1 != c2){
		cout << "0000\n";
		return 0;
	}
	cout << 1;
	if(sn1 != sn2){
		cout << "000\n";
		return 0;
	}
	cout << 1;
	if(sc1 + sc2 != 11 && sc1 + sc2 > 5){
		cout << "00\n";
		return 0;
	}
	cout << 1;
	if(abs(sc1 - sc2) != 1){
		cout << "0\n";
		return 0;
	}
	cout << 1 << '\n';
	
	// end
	return 0;
}
