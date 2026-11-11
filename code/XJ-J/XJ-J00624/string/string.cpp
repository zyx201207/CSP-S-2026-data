#include<bits/stdc++.h>
using namespace std ; 

int main(){
	
	freopen("string.in" , "r" , stdin) ; 
	freopen("string.out" , "w" , stdout) ; 
	
	int t ; 
	cin >> t ; 
	while(t--){
		int n ; 
		cin >>n ; 
		string s ; 
		cin >> s ; 
		if(n == 1){
			cout << 0 ; 
			return 0 ; 
		}
		if(n <= 2){
			for(char i = 'a' ; i <= s ; i++){
				for(char j = 'a' ; j <= i ; j++){
					int l = i , k = j ; 
					if(l == k){
						cout << 0 ; return 0 ; 
					}else{
						cout << 1 ; return 0 ; 
					}
				}
			}
		}
	}
	
	
	return 0 ; 
}