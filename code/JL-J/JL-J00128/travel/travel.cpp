#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a=0,b=0;
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	if(s1!=s2){
	   cout<<0000;
	   return 0;	
    }else{
	   if(c1[0]!=c2[0]){
		  cout<<1000;
		  return 0;   
	   }else{
		  if(c1[1]!=c2[1]){
			 cout<<1000;
			 return 0;  
	      }else{
			a=c1[2]-'0';
			b=c2[2]-'0';
			if((a<=67&&b>=68)||(b<=67&&a>=68)){
			   cout<<1100;	
			   return 0;
		    }else{
			   if(abs(a-b)==1){
				  cout<<1111;
				  return 0;   
			   }else{
				  cout<<1110;
				  return 0;   
			   }	
		    }
	      }
	   }   
    }
    return 0;
}
