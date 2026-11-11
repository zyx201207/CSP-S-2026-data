#include<bits/stdc++.h> 
using namespace std;
int main(){
	reopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]){
		if(c1[1]==c2[1]){
			cout<<"1";
		}else{
			cout<<"0000";
			return 0;
		}
	}
	if(s1[0]==s2[0]){
		if(s1[1]==s2[1]){
			cout<<"1";
		}else{
			cout<<"000";
			return 0;
		}
	}
	if(char(s1[2])<='C' and char(s2[2])<='C'){
		cout<<"1";
	}else if(char(s1[2])>='D' and char(s2[2])>='D'){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(char(s1[2]+1)==char(s2[2]) or char(s1[2]-1)==char(s2[2])){
		if(char(s1[2])=='C' or char(s1[2])=='D'){
			if(char(s2[2])=='C' or char(s2[2])=='D'){
				cout<<"0";
			}
		}else{
			cout<<"1";
		}
	}else{
		cout<<"0";
	}
	return 0;
}
