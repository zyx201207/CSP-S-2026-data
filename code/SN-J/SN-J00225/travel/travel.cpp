#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in ","r",stdin);
	freopen("travel.out ","w",stdout);
	string c1,s1,c2,s2;	
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;	
	}

	if(s1[0,1]==s2[0,1]){ 
		cout<<1;
	}
	else{
		cout<<0;	
	} 
	if(s1[2]=='C'&&s2[2]=='D' ||s1[2]=='D'&&s2[2]=='C'){ 
		cout<<0;
	}
	else{
		cout<<1;	
	} 
	if(abs(s1[2]-s2[2])==1){ 
		cout<<0;
	}
	else{
		cout<<1;	
	} 
	return 0;
}

