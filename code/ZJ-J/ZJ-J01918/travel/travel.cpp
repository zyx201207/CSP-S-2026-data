#include<bits\stdc++.h>
using namespace std;
int main(){
	ifstream("travel.in");
	ofstream("travel.out");
	string s1,c1,s2,c2,ans="0000";
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		ans[0]='1';
		if(s1[0]==s2[0] and s1[1]==s2[1]){
			ans[1]='1';
			if(s1[2]<='C' and s2[2]<='C'){
				ans[2]='1';
				if((s1[2]=='A' and s2[2]=='B') or (s1[2]=='B' and s2[2]=='A') or (s1[2]=='C' and s2[2]=='B') or (s1[2]=='B' and s2[2]=='C')){
					ans[3]='1';
				}
			}
			else if(s1[2]>'C' and s2[2]>'C'){
				ans[2]='1';
				ans[3]='1';
			}
		}
	}
	cout << ans;
	return 0;
}
