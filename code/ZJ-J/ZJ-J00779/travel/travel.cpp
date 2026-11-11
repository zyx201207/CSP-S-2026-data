#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	cin >> a >> b >> c >> d;
	if(a == c){
		cout << 1;
	}else{
		cout << "0000";
		return 0;
	}
	
	if(b[0] == d[0] && b[1] == d[1]){
		cout << 1;
	}else{
		cout << "000";
		return 0;
	}
	
	char x = b[2] , y = d[2];
	if(x == 'A'){
		if(y == 'B'){
			cout << "11";
			return 0;
		}else if(y == 'C'){
			cout << "10";
		}else{
			cout << "00";
		}
	}else if(x == 'B'){
		if(y == 'A' || y == 'C'){
			cout << "11";
		}else{
			cout << "00";
		}
	}else if(x == 'C'){
		if(y == 'B'){
			cout << "11";
		}else if(y == 'A'){
			cout << "10";
		}else{
			cout << "00";
		}
	}else if(x == 'D'){
		if(y == 'E'){
			cout << "11";
		}else{
			cout << "00";
		}
	}else if(x == 'E'){
		if(y == 'D'){
			cout << "11";
		}else{
			cout << "00";
		}
	}
	return 0;
}
