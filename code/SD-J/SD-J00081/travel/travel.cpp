#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ll c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool flag = true;
	if(c1 == c2){
		cout << 1;
	}else{
		cout << 0;
		flag = false;
	}
	if(flag){
		flag = true;
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << 1;
		}else{
			cout << 0;
			flag = false;
		}
	}else{
		cout << 0;
	}	
	if(flag){
		flag = true;
		if(s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C'){
			cout << 1;
		}else if(s1[2] >= 'D' && s1[2] <= 'E' && s2[2] >= 'D' && s2[2] <= 'E'){
			cout << 1;
		}else{
			cout << 0;
			flag = false;
		}
	}else{
		cout << 0;
	}
	if(flag){
		if((s1[2] == 'C' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'C')){
			cout << 0;
		}else if((int)(abs(s2[2] - s1[2])) == 1){
			cout << 1;
		}
		else{
			cout << 0;
		}
	}else{
		cout << 0;
	}
	return 0;
}
