
include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;

	if(c1==c2) {
		if(s1-s2<=4||s2-s1<=4) {
			if(s1-s2<=1||s2-s1<=1) {
				cout << "1111";
				return 0;
			}
			 else{
				cout << "1100";
				     return 0;
			}
		}
		 else{
			cout << "1000";
			return 0;
		}
	}
	 else{
		cout << "0000";
		return 0;
	}	
	return 0;