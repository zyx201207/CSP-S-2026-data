#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin >> s1 >> s2 >> s3 >> s4;
	bool flag = true;
	if(s1 == s3){
		cout << 1;
	}else{
		cout << 0;
		flag = false;
	}
	if(s2[0] == s4[0] && s2[1] == s4[1] && flag){
		cout << 1;
	}else{
		cout << 0;
		flag = false;
	}
	if('A' <= s2[2] && 'C' >= s2[2] && flag){
		if('A' <= s4[2] && 'C' >= s4[2]){
			cout << 1;
		}else{
			cout << 0;
			flag = false;
		}
	}else if(flag){
		cout << 1;
	}else{
		cout << 0;
	}
	if(((int)s2[2] + 1 == (int)s4[2] || (int)s2[2] - 1 == (int)s4[2]) && flag) cout << 1;
	else cout << 0;
	return 0;
} 
