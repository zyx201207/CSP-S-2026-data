#include <bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2,c1,c2;
	cin>>c1>>s1>>c1>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s1[0]==0){
		if(s2[0]==0){
			if(s1[1]==s2[1]){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else{
			cout<<0;
		}
	}
	else{
		if(s2[0]==1){
			if(s1[1]==s2[1]){
				cout<<1; 
			}
			else{
				cout<<0;
			}
		}
		else{
			cout<<0;
		}
	}
	if(s1[2]=='C' or 'A' or 'B'){
		if(s2[2]=='D' or 'F'){
		    cout<<0;
		}
		else{
			cout<<1;
		}
	}
	else if(s1[2]=='D' or 'F'){
		if(s2[2]=='C' or 'A' or 'B'){
			cout<<0;
		}
		else{
			cout<<1;
		} 
	}
	if(s1[2]=='A'){
		if(s2[2]=='B'){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(s1[2]=='B'){
		if(s2[2]=='A' or 'C'){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(s1[2]=='C'){
		if(s2[2]=='B'){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(s1[2]=='D'){
		if(s2[2]=='F'){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(s1[2]=='F'){
		if(s2[2]=='D'){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}




















