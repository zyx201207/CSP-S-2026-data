#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	char a[2],b[3],c[2],d[3];
	for(int i = 0; i < 2; i++) cin >> a[i];
	for(int i = 0; i < 3; i++) cin >> b[i];
	for(int i = 0; i < 2; i++) cin >> c[i];
	for(int i = 0; i < 3; i++) cin >> d[i];
	for(int i = 0; i < 2; i++){
		if(a[i] != c[i]){
			cout << "0000";
			break;
		}
	}
	cout << "1";
	for(int i = 0; i < 2; i++){
		if(b[i] != d[i]){
			cout << "000";
			break;
		}
	}
	if(b[2] == 'A' && d[2] == 'B') cout << "11";
	else if(d[2] =='B' && b[2] == 'C') cout << "11";
	else if(d[2] == 'D' && b[2] == 'E') cout << "11";
	else if(b[2] == 'B' && d[2] == 'C') cout << "11";
	else if(b[2] == 'D' && d[2] == 'E') cout << "11";
	else if(b[2] == 'A' && d[2] == 'C') cout << "10";
	else if(d[2] == 'A' && b[2] == 'C') cout << "10";
	else cout << "00";
}
