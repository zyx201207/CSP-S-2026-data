#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout); 
	char c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1=='A' and s2=='B'){
		cout<<"1";
	}
	else if(s1=='B' and s2=='c'){
		cout<<"1";
	}
	else if(s1=='D' and s2=='F'){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
