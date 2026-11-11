#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin >> c1;
	for(int i = 1; i <= 3; i++){
		cin >> s1[i]; 
	}
	cin >> c2;
	for(int j = 1; j <= 3; j++){
		cin >> s2[j];
	}
	if(c1 == c2){
		cout <<'1';
	}else{
		cout <<"0000";
	}
	if(s1[1] == s2[1] || s1[2] == s2[2]){
		cout << '1';
	}else{
		cout <<'0';
	}
	if(s1[3] - s2[3] == 1){
		cout << "11";
	}else{
		if(s2[3] - s1[3] == 1){
			cout << "11";
		}else{
			cout << "00";
		}
	}
	return 0;
} 
