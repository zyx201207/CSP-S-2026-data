#include<bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;
int num;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	for(int i = 0; i <= 1; i ++) if(c1[i] == c2[i]) num ++;
	if(num == 2) cout << "1";
	else{
		cout << "0000";
		return 0;
	}
	num = 0;
	for(int i = 0; i <= 1; i ++) if(s1[i] == s2[i]) num ++;	
	if(num == 2) cout << "1";
	else{
		cout << "000";
		return 0;
	}
	num = 0;
	if(s1[2] == 'A' || s1[2] == 'C' || s1[2] == 'B'){
		if(s2[2] == 'A' || s2[2] == 'C' || s2[2] == 'B'){
			cout << "1";
			num ++;
		}
	}
	else if(s1[2] == 'D' || s1[2] == 'E'){
		if(s1[2] == 'D' || s1[2] == 'E'){
	    	cout << "1";
	    	num += 2; 
	    }
	}
	if(num == 0){
    	cout << "00";
		return 0;	
	} 
	if(num == 2) cout << "1";
	else if(s1[2] - '0' == s2[2] - '0' + 1 || s2[2] - '0' == s1[2] - '0' + 1){
		cout << "1";
	}
	else cout << "0";
	return 0;
} 