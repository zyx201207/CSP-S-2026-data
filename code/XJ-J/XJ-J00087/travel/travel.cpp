#include<bits/stdc++.h>
using namespace std;
string n, m;
string s, k; 
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n >> s >> m >> k;
	if(n != m){
		cout << "0000" << "\n";
	}else{
		cout << 1;
		if(s[0] == k[0] && s[1] == k[1]){
			cout << 1;
			if(s[2] == 'A' && k[2] == 'B'){
				cout << 1 << 1 << "\n";
			}else if(s[2] == 'A' && k[2] == 'C'){
				cout << 1 << 0 << "\n";
			}else if(s[2] == 'B' && k[2] == 'A'){
				cout << 1 << 1 << "\n";
			}else if(s[2] == 'B' && k[2] == 'C'){
				cout << 1 << 1 << "\n";
			}else if(s[2] == 'C' && k[2] == 'B'){
				cout << 1 << 1 << "\n";
			}else if(s[2] == 'C' && k[2] == 'A'){
				cout << 1 << 0 << "\n";
			}else{
				cout << 0 << 0 << "\n";
			}
		}else{
			cout << 0 << 0 << 0 << "\n";
		}
	}
	return 0;
} 
