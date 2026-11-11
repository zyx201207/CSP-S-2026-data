#include<bits/stdc++.h>
using namespace std;
int main(){
	string c1,s1,c2,s2,num;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[0] == c2[0] && c1[1] == c2[1] && '0' <= c1[0] <= '1' && '0' <= c1[1] <= '6'){
		if (c1[0] == '0' && c1[1] == '1'){
			num = "0000";
		}else if(c1[0] == '1' && c1[1] == '6'){
			num = "0000";
		}else{
			if (s1[0] == s2[0] && s1[1] == s2[1] && '0' <= s1[0] <= '1' && '1' <= s1[1] <= '8'){
				if (s1[2] == 'A' && s2[2] == 'B' || s1[2] == 'A' && s2[2] == 'C' || s1[2] == 'B' && s2[2] == 'C'){
					if (s1[2] == 'A' && s2[2] == 'B'){
						num = "1111";
					}else if(s1[2] == 'B' && s2[2] == 'C'){
						num = "1111";
					}else{
						num = "1110";
					}
				}else if(s1[2] == 'D' && s2[2] == 'F'){
					num = "1111";
				}else{
					num = "1100";
				}
			}else{
				num = "1000";
			}
		}
	}else{
		num = "0000";
	}
	cout << num;
	return 0;
}
