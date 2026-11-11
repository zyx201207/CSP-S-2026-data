#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c, s, cc, ss;
	cin >> c >> s >> cc >> ss;
	if(c == cc){
		cout << "1";
		for(int i = 0; i < 2; i++){
			if(s[i] != ss[i]){
				cout << "000";
				return 0;
			}
		}
		cout << "1";
		if(s[2] == 'A'){
			if(ss[2] == 'B'){
				cout << "11";
				return 0;
			}else if(ss[2] == 'C'){
				cout << "10";
				return 0;
			}else if(ss[2] == 'D' || ss[2] == 'E'){
				cout << "00";
				return 0;
			}
		}else if(s[2] == 'B'){
			if(ss[2] == 'A' || ss[2] == 'C'){
				cout << "11";
				return 0;
			}else if(ss[2] == 'D' || ss[2] == 'E'){
				cout << "00";
				return 0;
			}
		}else if(s[2] == 'C'){
			if(ss[2] == 'A'){
				cout << "10";
				return 0;
			}else if(ss[2] == 'B'){
				cout << "11";
				return 0; 
			}else{
				cout << "00";
				return 0;
			}
		}else if(s[2] == 'D'){
			if(ss[2] == 'E'){
				cout << "11";
				return 0;
			}else{
				cout << "00";
				return 0;
			}
		}else{
			if(ss[2] == 'D'){
				cout << "11";
				return 0;
			}else{
				cout << "00";
				return 0;
			}
		}
	}else{
		cout << "0000";
	}
	
	return 0;
} 
