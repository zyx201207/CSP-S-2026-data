#include<bits/stdc++.h>

using namespace std ; 

int main(){
	
	freopen("travel.in" , "r" , stdin) ; 
	freopen("travel.out" , "w" , stdout) ;
	
	
	string c1 , s1 , c2 , s2 ; 
	cin >> c1 >> s1 >> c2 >> s2 ; 
	if(c1 == c2){
		cout << '1' ; 
	}else{
		cout << '0' ; 
	}
	//1
	int cnt = 0 ; 
	for(int i = 0 ; i < s1.size() - 1 ; i++){
		if(s1[i] == s2[i]){
			cnt++ ; 
		}
	}
	if(cnt == 2 && c1 == c2){
		cout << '1' ; 
	}else{
		cout <<'0' ; 
	}
	//2
	for(char i = 0 ; i < 3 ; i++){
		if(i==2){
			if((('A'<=s1[i] || s1[i]<='C') && ('A'<=s2[i] || s2[i]<='C')) ||
			 ((('D'==s1[i] || s1[i]=='F') && ('D'==s2[i] || s2[i]=='F'))) && cnt == 2 && c1 == c2){
				cout << '1' ; 
				break ; 
				else{
			 cout <<'0' ; 
				break ; 
			 
					
	}
	//3
	while(1){
		1      i]=='A'&&s2[1]=='B')||(s1[1]=='B'&&s2[1]=='A')||(s1[1]=='C'&&s2[1]=='B')
		||(s1[1]=='B'&&s2[1]=='C')||(s1[1]=='D'&&s2[1]=='F')||(s1[1]=='F'&&s2[1]=='D')){
			cout <<'1' ; 
			break ; 
			
			cout <<'0' ; 
			break ; 
			
		eturn 0 ; 
}f((s1[