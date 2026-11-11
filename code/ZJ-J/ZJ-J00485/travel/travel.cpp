#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2) cout << "0000";
	else{
		cout << "1";
		int p1 = (s1[0] - '0') * 10 + (s1[1] - '0');
		int p2 = (s2[0] - '0') * 10 + (s2[1] - '0');
		if(p1 != p2) cout << "000";
		else{
			cout << "1";
			char z1 = s1[2], z2 = s2[2];
			if(z1 > z2){
				char l = z1;
				z1 = z2;
				z2 = l;
			}
			if(z2 == 'F') z2 = 'E';
			if(z1 <= 'C' && z2 <= 'C' || z1 >= 'D' && z2 >= 'D'){
				cout << "1";
				if(z2 - z1 == 1) cout << "1";
				else cout << "0";
			}
			else cout << "00";
		}
	}
	
	return 0;
}
