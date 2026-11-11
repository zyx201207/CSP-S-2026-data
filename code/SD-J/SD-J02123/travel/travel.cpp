#include<bits/stdc++.h>
using namespace std ;
int a[7] = {0 , 0 , 0 , 1 , 1 , 1} ;
int main(){
	freopen("travel.in" , "r" , stdin) ;
	freopen("travel.out" , "w" , stdout) ;
	string c1 , s1 , c2 , s2 ;
	cin >> c1 >> s1 >> c2 >> s2 ;
	if(c1[0] == c2[0] && c1[1] == c2[1]){
		cout << 1 ;
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << 1 ;
			if(a[s1[2] - 'A'] == a[s2[2] - 'A']){
				cout << 1 ;
				if(max(s1[2] , s2[2]) == min(s1[2] , s2[2])+1 || a[s1[2] - 'A'] == 1){
					cout << 1 ;
				}else{
					cout << 0 ;
				}
			}else{
				cout << "00" ;
			}
		}else{
			cout << "000" ;
		}
	}else{
		cout << "0000" ;
	}
	return 0 ;
}

