#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","W",stdout);
	string c1,s1,c2,s2;
	cin >>c1>>s2>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<"11";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"11";
		return 0;
	}
	else{
		cout<<"10";
		return 0;
	}
	if(s1[2]=='A'){
		if(s2[2]=='B'||s2[2]=='c'){
			cout<<"1";
		}
		else if(s1[2]=='B'){
			cout<<"1";
			return 0;
		    
		}
		   
		else{
			cout<<"0";
			return 0;
		}
	}
	if(s1[2]=='E'){
		if(s2[2]=='F'||s2[2]=='G'){
			cout<<"1";
		}
		else if(s1[2]=='F'){
			cout<<"1";
			return 0;
		}
	}
	return 0;
	
}
