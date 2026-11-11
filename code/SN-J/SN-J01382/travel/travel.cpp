#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel","r",stdin);
	//freopen("travel","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000" <<" ";
	}
	if(c1 == c2){
		cout << "1";
		if(s1[1] != s2[1]){
			cout << "000";
		}
		if(s1[1] == s2[1]){
			if(s1[0] == s2[0]){
				cout << "1";
				if(s1[2] == 'D' || s1[2] == 'F'){
					if(s2[2] == 'D' || s2[2] == 'F'){
						cout << "11";
					}
					
					if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
						if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
							cout << "10" ;
						}
					}
				}
			}
		}
	}
		
	
	return 0;
}
