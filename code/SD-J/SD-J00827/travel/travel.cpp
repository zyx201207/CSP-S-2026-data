#include<bits/stdc++.h>
using namespace std; 
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << "1";
//		cout << "\n";
		char seat1 = s1[2],seat2 = s2[2];
		int x = (s1[0]-'0')*10+(s1[1]-'0'),y = (s2[0]-'0')*10+(s2[1]-'0');
//		cout << seat1 << " " << seat2 << " " << x << " " << y << "\n";
		if(x == y){
			cout << "1";
			if(seat1 <= 'C'&&seat2 <= 'C'){
				cout << "1";
				if(abs(seat1-seat2) == 1) cout << "1";
				else cout << "0";
			}else if(seat1 >= 'D'&&seat2 >= 'D'){
				cout << "1";
				if(abs(seat1-seat2) == 2) cout << "1";
				else cout << "0";
			}else cout << "00";
		}else cout << "000";
	}else cout << "0000";
	
}
