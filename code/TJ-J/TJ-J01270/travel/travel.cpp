#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i = 0;i < 2;i++){
			cin >> c1[i];
	}
	for(int i = 0;i <3;i++){
		cin >> s1[i];
	}
	for(int i = 0;i <2;i++){
		cin >> c2;	
	}
	for(int i = 0;i <3;i++){
		cin >> s2;
	}
	a[0]= s1[0];
	a[1] = s1[1];
	b[0] = s2[0];
	b[1] = s2[1];
	if(c1 == c2){
		cout << 1;
		if(a == b){
			cout << 1; 
			if(s1[2] >= 'A'&& s1[2] <= 'C' && s2[2] >='A'&& s2[2] <= 'C'||s1[2]>= 'D'&& s1[2] <= 'F' && s2[2] >='D'&& s2[2] <= 'F'){		
				if(s1[2] + 1 == s2[2] || s1[2]-1 == s2[2]){
					cout << 1;  
				}
				else{
					cout << 0;
				}
			}
		}
		else{
			cout << 0;
		}
	}
	else{
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
} 
