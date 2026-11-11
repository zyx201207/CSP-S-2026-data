#include<bits/stdc++.h>
using namespace std;
int main(){
	int cr,cx;
	string sr,sx;
	cin>>cr>>sr>>cx>>sx;
	if(cr!=cx){
		cout<<"0000";
		return 0;
	}
	if(sr[0]==sx[0] and sr[1]==sx[1]){
		if((sr[2]>='D' and sx[2]>='D') or (sr[2]<'D' and sx[2]<'D')){
			if(sr[2]-'A'==sx[2]-'B' or sr[2]-'B'==sx[2]-'A')cout<<"1111";
			else cout<<"1110";
			
		}else cout<<"1100";
	}else cout<<"1000";
	return 0;
} 
