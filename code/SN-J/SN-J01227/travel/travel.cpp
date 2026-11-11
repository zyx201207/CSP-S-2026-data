#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0);
	string c,s,c2,s2,a,b;
	char d,e;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c >> s >> c2 >> s2;
	if (c == c2){
		cout << 1;
	}
	else{
		cout << "0000";
		return 0;
	}
	for (int i = 0;i <= 1;i++){
		a += s[i];
	}
	for (int i = 0;i <= 1;i++){
		b += s2[i];
	}
	if (a == b){
		cout << 1;
	}
	else{
		cout << "000";
		return 0;
	}
	e = s[2];
	d = s2[2];
	if (e >= 'A' && e <= 'C' && d >= 'A' && d <= 'C'){
		cout << 1;
	}
	else if (e >= 'D' && d >= 'D'){
		cout << 1;
	}
	else{
		cout << "00";
		return 0;
	}
	if(e - 1 == d || e + 1 == d){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}
