#include<bits/stdc++.h>
using namespace std;
string c[0],s[0];
int main()
{
	for(int i = 0;i <= 2;i++){
		for(int j = 0;j <= 2;j++){
			if(c[i]==c[j]){
				cout<<11;
			}
			else{
				cout<<00;
			}
			if(s[i]==s[j]){
				cout<<11;
			}
			else{
				cout<<00;
			}
		}
	}
	return 0;

 } 
