#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel5.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string c1,s1,c2,s2;
	cin >> c1 >> c2 >> s1 >> s2;
	int a = c2[2], b = s2[2];
	if(c1==s1){
		cout << '1';
		if(c2[0] == s2[0] && c2[1] == s2[1]){
			cout << '1';
			if(((c2[2] == 'A' || c2[2] == 'B' || c2[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) || ((c2[2] == 'D' || c2[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F'))){
				cout << '1';
				if((c2[2] == 'C' && s2[2] == 'D') || (s2[2] == 'C' && c2[2] == 'D')){
					cout <<'0';
					return 0;
				}
				else if(max(a, b) - 1 == min(a, b)){
					cout << '1';
				}else{
					cout << '0';
				}
			}else{
				cout << "00";
			}
		}
		else{
			cout << "000";
		}
		
	}else{
		cout << "0000";
		
		
	}
	
	
	
	return 0;
}
