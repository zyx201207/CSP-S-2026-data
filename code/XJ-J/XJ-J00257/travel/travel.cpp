#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	//1
	if(a == c){
		cout << "1";
	}else{
		cout << "0000";
		return 0;
	}
	//2
	if(b[0] == d[0]){
		if(b[1] == d[1]){
			cout<<"1";
		}else{
			cout << "000";
			return 0;
		}
	}else{
		cout << "000";
		return 0;
	}
	//3
	int cnt = 0;
	if(b[2] >= 'A'&&b[2]<= 'C'&& d[2] >= 'A' && d[2] <= 'C'){
		cnt = 1;
	}
	if(b[2] == 'D' &&d[2] == 'F'){
		cnt = 1;
	}
	if(b[2] == 'F' &&d[2] == 'D'){
		cnt = 1;
	}
	if(cnt == 1){
		cout << "1";
	}else{
		cout<<"00";
		return 0;
	}
	//xl
	int cnt1 = 0;;
	if(b[2] == 'A'&&d[2] == 'B'){
		cnt1 = 1;
	}
	if(b[2] == 'B'&&d[2] == 'A'){
		cnt1 = 1;
	}
	if(b[2] == 'B'&&d[2] == 'C'){
		cnt1 = 1;
	}
	if(b[2] == 'C'&&d[2] == 'B'){
		cnt1 = 1;
	}
	if(b[2] == 'D'&&d[2] == 'F'){
		cnt1 = 1;
	}
	if(b[2] == 'F'&&d[2] == 'D'){
		cnt1 = 1;
	}
	if(cnt1 = 1){
		cout << "1";
	}else{
		cout << "0";
	}
	return 0;
}