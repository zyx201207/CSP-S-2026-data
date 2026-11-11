#include<bits/stdc++.h>

using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("r","travel.in",stdin);
	freopen("w","travel.out",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	long long a = 10 * (s1[0] - '0') + s1[1] - '0';
	long long b = 10 * (s2[0] - '0') + s2[1] - '0';
	long long c = s1[2];
	long long d = s2[2];
	if(c1 == c2){
		cout << '1';
	}else{
		cout << "0000";
		return 0;
	}
	if(a == b){
		cout << '1';
	}else{
		cout << '0';
	}
	if(a == b){
		if((c >= 68 && d >= 68) || (c < 68 && d < 68)){
			cout << '1';
		}else{
			cout << '0';
		}
	}else{
		cout << '0';
	}
	if(a == b){
		if((c >= 68 && d >= 68) || (c < 68 && d < 68)){
			if(abs(c - d) == 1){
				cout << '1';
			}else{
				cout << '0';
			}
		}else{
			cout << '0';
		}
	}else{
		cout << '0';
	}
	return 0;
}
