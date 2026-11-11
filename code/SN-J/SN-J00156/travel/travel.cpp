#include <bits/stdc++.h>
using namespace std;
int c[25];
char s[95];
int no[100];
int main (){
	freopen("travel.in" ,"r" stdin);
	freopen("travel.out","w"  stdout);
	for(int i = 0; i < 2; i ++){
		cin >> c[i] >> no[i] >> s[i]; 
	}
	for(int i = 0; i < 1; i++){
		
		if(c[i] != c[i + 1])
		{
			cout << "0000";
			
		}else{
			cout << '1';
			if(no[i] != no[i + 1]){
				cout << "000";
			}else{
				cout << '1';
				if(((s[i] >= 'A' || s[i] <='B') && (s[i + 1] >= 'A' || s[i + 1] <='B')) || ((s[i] >= 'D' || s[i] <='F') && (s[i + 1] >= 'D' || s[i + 1] <='F'))){
					cout << '1';
					if((s[i] == 'A' && s[i + 1] == 'B' )|| (s[i] == 'B' && (s[i + 1] == 'A' || s[i + 1] == 'C')) || (s[i] == 'C' && s[i + 1] == 'B') || (s[i] == 'D' && s[i + 1] == 'F') || (s[i] == 'F' && s[i + 1] == 'D')){
						cout << '1';
					}else{
						cout << '0';
					}
				}else{
					cout << "00";
				}
			}
		}
		
		
	}
	
	
	
	
	return 0;
}
