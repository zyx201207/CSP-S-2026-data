#include <bits/stdc++.h>
using namespace std; 


int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	 
	string c1,s1,c2,s2;
	string a = "ABCDE";
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		cout << 1;
		bool state = 1;
		if (s1[1] != s2[1] || s1[0] != s2[0]){
			cout << 0 << 0 << 0;
		}
		else{
			cout << 1;
			bool x = 0;
			for (int i = 0;i < 5;i ++){
				if (s1[2] == a[i] && s2[2] == a[i+1] && i < 2){
					cout << 11 ;
					x = 1;
				}else if(s2[2] == a[i] && s1[2] == a[i+1] && i < 2){
					cout << 11 ;
					x = 1;
				}else if(s2[2] == a[i] && s1[2] == a[i+2] && i < 2){
					cout << 10;
					x = 1;
				}else if(s1[2] == a[i] && s2[2] == a[i+2] && i < 2){
					cout << 10;
					x = 1;
				}else if (s1[2] == a[i] && s2[2] == a[i+1] && i >= 3){
					cout << 11 ;
					x = 1;
				}else if(s2[2] == a[i] && s1[2] == a[i+1] && i >= 3){
					cout << 11;
					x = 1;
				}
				
			}
			if (x == 0){
				cout << 0 << 0;
			}
			
		}
	}else{
		cout << 0 <<0 << 0 << 0;
	}
	return 0;
}

