#include <bits/stdc++.h>
using namespace std;

string c1 , s1 , c2 , s2;
bool ce = false;

int main(){
	
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 == c2 && c1 != "01" && c1 != "16"){//≥µœ· 
		cout << 1;
	}
	else{
		for(int i = 1 ; i <= 4 ; i++){
			cout << 0;
		}
		return 0;
	}
	
	if(s1[0] == s2[0] && s1[1] == s2[1]){//≈≈ 
		cout << 1;
	}
	else{
		for(int i = 1 ; i <= 3 ; i++){
			cout << 0;
		}
		return 0;
	}
	
	if((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D' && s1[2] <= 'F' && s2[2] <= 'F')){//≤‡ 
		ce = true;
		cout << 1;
		
	
	}
	else{
		cout << 0;
	}
	
	if((s1[2] - s2[2] == 1 || s2[2] - s1[2] == 1) && ce == true){
		cout << 1;
	}
	else{
		cout << 0;
	}
} 
