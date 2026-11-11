#include <bits/stdc++.h>
using namespace std;
int main(){
	string a[100],b[100];
	for(int i = 1;i <= 2;i++){
		cin >> a[i];
	    }	
	for(int i = 1;i <= 2;i++){
		cin >> b[i];
	}
	if(b[1]== a[1]){
		if(a[2][1] == b[2][1]){
			if(a[2][2]=='A' || a[2][2] == 'B' || a[2][2] == 'C'){
				if(b[2][2]=='A' || b[2][2] == 'B' || b[2][2] == 'C'){
					if(a[2][2] == 'A' && b[2][2] == 'B'){
						cout << "1111";
					}
					if(a[2][2] == 'B' && b[2][2] == 'A'){
						cout << "1111";
					}
					if(a[2][2] == 'B' && b[2][2] == 'C'){
						cout << "1111";
					}
					if(a[2][2] == 'C' && b[2][2] == 'B'){
						cout << "1111";
					}
					if(a[2][2] == 'A' && b[2][2] == 'C'){
						cout << "1110";
					}
					if(a[2][2] == 'C' && b[2][2] == 'A'){
						cout << "1110";
					}
				}
				else{
					cout << "1100";
				}
			}
			if(a[2][2]=='E' || a[2][2] == 'F'){
				if(a[2][2]=='E' || a[2][2] == 'F'){
					cout << "1111"; 
				}
				else{
					cout << "1100";
				}
			}
		}
		else{
			cout << "1000";
		}
	}
	else{
		cout << "0000";
	}
	return 0;
}
