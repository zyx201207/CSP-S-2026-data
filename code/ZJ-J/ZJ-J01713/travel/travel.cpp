#include<bits/stdc++.h>
using namespace std;
int a,b;
string a1,b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin >> a >> a1;
	cin >> b >> b1;
	char a3,b3;

	
	a3 = a1[2];
	b3 = b1[2];
	if(a == b){
		cout << "1";
		if(a1[0] == b1[0] && a1[1] == b1[1]){
			cout << "1";
			if(a3 >= 'D' && b3 >= 'D' || a3 <= 'C' && b3 <= 'C'){
				cout << "1";
				if(int(a3) - int(b3) == 1 || int(b3) - (a3) == 1){
					cout << "1";
				}else{
					cout << "0";
				}
			}else{
				cout << "00"; 
			}
			
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	
}
