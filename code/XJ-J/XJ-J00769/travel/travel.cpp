#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	
	if(s1[0]==s2[0]&&s2[1]==s1[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	int a=s1[2],b=s2[2];
	if((65<=b<=67&&65<=a<=67)||(68<=a<=69&&68<=b<=69)){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if(abs(a-b)==1){
		cout<<1;
		
	}else{
		cout<< 0;
	}
	return 0;
} 
