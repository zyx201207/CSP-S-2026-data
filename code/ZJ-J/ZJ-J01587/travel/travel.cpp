#include <bits/stdc++.h>
using namespace std;

struct node{
	string s,c;
};

node a,b;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> a.c >> a.s >> b.c >> b.s;
	if(a.c == b.c){
		cout << 1;
		if(a.s[0] == '0'){
			if(b.s[0] == '0'){
				if(a.s[1] == b.s[1]){
					cout << 1;
					if(a.s[2] >= 'D' && a.s[2] <= 'F' && b.s[2] >= 'D' && b.s[2] <= 'F' || a.s[2] >= 'A' && a.s[2] <= 'C' && b.s[2] >= 'A' && b.s[2] <= 'C'){
						cout << 1;
						if(a.s[2] == 'A' && b.s[2] == 'B' || a.s[2] == 'B' && b.s[2] == 'A' || a.s[2] == 'B' && b.s[2] == 'C' || a.s[2] == 'C' && b.s[2] == 'B' || a.s[2] == 'D' && b.s[2] == 'F' || a.s[2] == 'F' && b.s[2] == 'D'){
							cout << 1;
						}else{
							cout << 0;
							return 0;
						}
					}else{
						cout << 0 << 0;
						return 0;
					}
				}else{
					cout << 0 << 0 << 0;
					return 0;
				}
			}else{
				cout << 0 << 0 << 0;
				return 0;
			}
		}else{
			if(b.s[0] == '1'){
				if(a.s[1] == b.s[1]){
					cout << 1;
					if(a.s[2] >= 'D' && a.s[2] <= 'F' && b.s[2] >= 'D' && b.s[2] <= 'F' || a.s[2] >= 'A' && a.s[2] <= 'C' && b.s[2] >= 'A' && b.s[2] <= 'C'){
						cout << 1;
						if(a.s[2] == 'A' && b.s[2] == 'B' || a.s[2] == 'B' && b.s[2] == 'A' || a.s[2] == 'B' && b.s[2] == 'C' || a.s[2] == 'C' && b.s[2] == 'B' || a.s[2]== 'D' && b.s[2] == 'F' || a.s[2] == 'F' && b.s[2] == 'D'){
							cout << 1;
						}else{
							cout << 0;
							return 0;
						}
					}else{
						cout << 0 << 0;
						return 0;
					}
				}else{
					cout << 0 << 0 << 0;
					return 0;
				}
			}else{
				cout << 0 << 0 << 0;
				return 0;
			}
		}
	}else{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	
	return 0;
}
