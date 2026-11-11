#include <bits/stdc++.h>
using namespace std;

int side(char x) {
	if (x == 'A' ||
	    x == 'B' || 
		x == 'C') {
		return 0;
	} else return 1;
} 

int main() {
	freopen("travel.in",  "r", stdin );
	freopen("travel.out", "w", stdout);
	
	int    c1, c2;
	string s1, s2;
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 == c2) {
		cout << 1;
		
		if (s1[0] == s2[0] && 
		    s1[1] == s2[1]) {
		    cout << 1;
		    
		    if (side(s2[2]) == side(s1[2])) {
		    	cout << 1;
		    	
		    	if (side(s1[2]) == 1 ||
					s1[2] == 'B' ||
					s2[2] == 'B') cout << 1;
					
				else cout << 0;
				
			} else cout << "00";
		    
		} else cout << "000";
		
	} else cout << "0000";
	
	fclose(stdin );
	fclose(stdout);
	
	return 0;
}
