#include<bits/stdc++.h>
using namespace std;
string ca, cb, sa, sb;
char s[4];
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> ca >> sa >> cb >> sb;
	for(int i = 0;i <= 3;i++){
		s[i] = '0';
	}
	if(ca == cb){
		s[0] = '1';
		if(sa[0] == sb[0] && sa[1] == sb[1]){
			s[1] = '1';
			if((sa[2] <= 'C' && sb[2] <= 'C') || (sa[2] >= 'D' && sb[2] >= 'D')){
				s[2] = '1';
				if(sa[2] >= 'D' && sb[2] >= 'D'){
					s[3] = '1';
				}
				else{
					if(sa[2] - 1 == sb[2] || sa[2] + 1 == sb[2]){
						s[3] = '1';
					}
				}
				
			}
		}
	}
	cout << s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}