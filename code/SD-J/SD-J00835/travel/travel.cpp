#include<bits/stdc++.h>
using namespace std;
string c, cc, s, ss;
bool jmc = 0;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c >> s >> cc >> ss;
	if(c != cc){
		cout << "0000";
		return 0;
	}	
	for(int i = 0; i < s.size() - 1; i++){
		if(s[i] != ss[i]){
			jmc = 1;
			break;
		}
	}
	if(jmc == 1){
		cout << "1000";
		return 0;
	}
	int l = s.size() - 1;
//	cout << s[l] << " " << ss[l];
	if(s[l] == 'A' && ss[l] != 'B' && ss[l] != 'C'){
		cout << "1100";
	//	cout << ss[l];
		return 0;
	}
	else if(s[l] == 'B' && ss[l] != 'A' && ss[l] != 'C'){
		cout << "1100";
		return 0;
	}
	else if(s[l] == 'C' && ss[l] != 'A' && ss[l] != 'B'){
		cout << "1100";
		return 0;
	}
	else if(s[l] == 'D' && ss[l] != 'F'){
		cout << "1100";
		return 0;
	}
	else if(ss[l] != 'D' && s[l] == 'F'){
		cout << "1100";
		return 0;
	}	
	if(abs(s[l] - ss[l]) > 1){
		cout << "1110";
		return 0;
	}
	cout << "1111";
	return 0;
} 
