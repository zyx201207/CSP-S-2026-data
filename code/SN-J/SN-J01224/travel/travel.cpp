#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int ans1 =0,ans2 =0,ans3 =0,ans4 =0;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 == c2) ans1 = 1;
	if(c1 != c2){
		cout << "0000";
		return 0;
	} 
	
	if(s1[0] == s2[0] && s1[1] == s2[1]){
		ans2 = 1;
	}
	if(s1[0] != s2[0] || s1[1] != s2[1]){
		cout << "1000";
		return 0;
	}
	
	if(s1[2] <= 'C' && s1[2] >= 'A' && s2[2] <= 'C' && s2[2] >= 'A'){
		ans3 = 1;
	}
	else if(s1[2] <= 'E' && s1[2] >= 'D' && s2[2] <= 'E' && s2[2] >= 'D'){
		ans3 = 1;
	}
	else{
		cout << "1100";
		return 0;
	}
	
	if(s1[2] == 'A' or s2[2] == 'A'){
		if(s1[2] == 'B' or s2[2] == 'B'){
			cout << "1111";
			return 0;
		}
	}
	
	else if(s1[2] == 'C' or s2[2] == 'C'){
		if(s1[2] == 'B' or s2[2] == 'B'){
			cout << "1111";
			return 0;
		}
	}
	
	else if(s1[2] == 'D' or s2[2] == 'D'){
		if(s1[2] == 'E' or s2[2] == 'E'){
			cout << "1111";
			return 0;
		}
	}
	

	cout << "1110";

	
	return 0;
} 
