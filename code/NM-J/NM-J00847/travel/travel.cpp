#include <bits/stdc++.h>
using namespace std;
string c1;
string c2;
string s1;
string s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	string ans = "";
	if(c1 == c2){
		ans += '1';
	}else{
		cout << "0000";
		return 0;
	}
	int s = s1[0] - '0';
	int ss = s1[1] - '0';
	int s3 = s2[0] - '0';
	int ss3 = s2[1] - '0';
	
	int sum = s * 10 + ss;
	int sum2 = s3 * 10 + ss3;
	if(c1 == c2 && sum == sum2){
		ans += '1';
	}else{
		cout << "1000";
		return 0;
	}
	
	int s4 = s1[2];
	int s5 = s2[2];
	
	if(c1 == c2 && sum == sum2 && (((s4 >= 'A' && s4 <= 'C') && (s5 >= 'A' && s5 <= 'C') && s4 != s5) || ((s4 == 'D' && s5 == 'F') || (s5 == 'D' && s4 == 'F')))){
		ans += '1';
		
	}else{
		cout << "1100";
		return 0;
	}
	
	if(c1 == c2 && sum == sum2 && (((s4 >= 'A' && s4 <= 'C') && (s5 >= 'A' && s5 <= 'C') && s4 != s5) || ((s4 == 'D' && s5 == 'F') || (s5 == 'D' && s4 == 'F'))) && ((s4 == 'A' && s5 == 'B') || (s5 == 'A' && s4 == 'B') || (s4 == 'B' && s5 == 'C') || (s4 == 'C' && s5 == 'B') || (s4 == 'D' && s5 == 'F') || (s4 == 'F' && s5 == 'D'))){
		ans += '1';
		
	}else{
		cout << "1110";
		return 0;
	}
	
	cout << ans;
	return 0;
}
