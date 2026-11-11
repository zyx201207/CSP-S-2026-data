#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	bool t = 0;
	if(c1 == c2){
		cout << 1;
		t = 1;
	}else{
		cout << 0;
	}
	bool tmp = 0;
	if(t && s1[0] == s2[0] && s1[1] == s2[1]){
		cout << 1;
		tmp = 1;
	}else{
		cout << 0;
	}
	bool tmp1 = 0;
	if(t && tmp){
		char a = s1[2],b = s2[2];
		if(a == 'A' || a == 'B' || a == 'C' && b == 'A' || b == 'B' || b == 'C'){
			cout << 1;
			tmp1 = 1;
		}else{
			cout << 0;
		}
	}else{
		cout << 0;
	}
	if(t && tmp && tmp1){
		char a = s1[2],b = s2[2];
		if(a - 1 == b || b - 1 == a){
			cout << 1;
		}else if(a == 'D' && b == 'F' || a == 'F' && b == 'D'){
			cout << 1;
		}else{
			cout << 0;
		}
	}else{
		cout << 0;
	}
	return 0;
} 
