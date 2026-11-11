#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopean("travel.in","r",stdin);
//	freopean("travel.out","W",stdout);
    int c1,c2,s1,s2; 
    cin>>c1>>s1>>c2>>s2;
    if(c1=c2){
    	cout<<0;
	}
	else{
		cout<<1;
	}
	if(s1=s2){
		cout<<0;
	}
	else{
		cout<<1;
	}
	if(c1<c2){
		cout<<0;
	}   
	else{
		cout<<1;
	}
	if(s1<s2){
		cout<<0;
	}
	else{
		cout<<1;
	}
	return 0;
}
