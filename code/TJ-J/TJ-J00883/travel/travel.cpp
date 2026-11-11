#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int num1,num2;
char s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if(a == c){
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}
	for(int i = 0;i < b.size(); i++){
		if(b[i] >= '0' && b[i] <= '9'){
			num1 *= 10;
			num1 += b[i] - '0';
		} else {
			s1 = b[i];
		}
	}
	for(int i = 0;i < d.size(); i++){
		if(d[i] >= '0' && d[i] <= '9'){
			num2 *= 10;
			num2 += d[i] - '0';
		} else {
			s2 = d[i];
		}
	}
	if(num1 == num2){
		cout << 1;
	}
	else cout << 0;
	if(num1 == num2){
		if(s1 == 'A'){
			if(s2 == 'B' || s2 == 'C') cout << 1;
			else cout << 0;
		} 
		else if(s1 == 'B'){
			if(s2 == 'A' || s2 == 'C') cout << 1;
			else cout << 0;
		} 
		else if(s1 == 'C'){
			if(s2 == 'B' || s2 == 'A') cout << 1;
			else cout << 0;
		} 
		else if(s1 == 'D'){
			if(s2 == 'F') cout << 1;
			else cout << 0;
		} 
		else if(s1 == 'F'){
			if(s2 == 'D') cout << 1;
			else cout << 0;
		} 
	} else {
		cout << 0;
	}
	if(s1 == 'A'){
		if(s2 == 'B' && num1 == num2) cout << 1;
		else cout << 0;
	}
	else if(s1 == 'B'){
		if((s2 == 'A' || s2 == 'C') && num1 == num2) cout << 1;
		else cout << 0;
	}
	else if(s1 == 'C'){
		if(s2 == 'B' && num1 == num2) cout << 1;
		else cout << 0;
	}
	else if(s1 == 'D'){
		if(s2 == 'F' && num1 == num2) cout << 1;
		else cout << 0;
	}
	else if(s1 == 'F'){
		if(s2 == 'D' && num1 == num2) cout << 1;
		else cout << 0;
	}
	return 0;
} //02 01C 02 01D
