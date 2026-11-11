#include<bits/stdc++.h>
using namespace std;
int n[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(int(s1[2])+int(s2[2])==131||132||133||135){
		cout<<1;
		if(int(s1[2])+1==int(s2[2]) || int(s1[2])-1==int(s2[2])){
			cout<<1;
			
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<00;
	}

		
	return 0;
	
} 
