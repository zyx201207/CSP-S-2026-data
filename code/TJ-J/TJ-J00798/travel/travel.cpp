#include <bits/stdc++.h>
#include <string>
#include <cmath>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	
	char c1[4],c2[4],s1[4],s2[4];
	cin >> c1 >> s1 >> c2 >> s2;
	
	
	if(c1[0] == c2[0] && c1[1] == c2[1]){
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
				if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
					if(s2[2] - s1[2] == 1 || s1[2] - s2[2] == 1){
						cout << "1111";
					}
					else cout << "1110";
				}
				else cout << "1100";
			}
			else if(s1[2] == 'D' || s1[2] == 'E'){
				if(s2[2] == 'D' || s2[2] == 'E'){
					if(s2[2] - s1[2] == 1 || s1[2] - s2[2] == 1){
						cout << "1111";
					}
					else cout << "1110";
				}
				else cout << "1100";
			}
		}
		else cout << "1000";
	}
	else cout << "0000";
	
	
	return 0;
}
