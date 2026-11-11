#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool pd(string s0){
	if(s0[2]=='A'||s0[2]=='B'||s0[0]=='C',return 1)
}
int main(){
	fropen("trane.in","r",stdin);
	frepen("trane.in","m",stdout);
	cin >>c1>>s1>>c2>>s2;
	if(c1==c2){
	    cout <<1;
	    if(s1[0]==s2[0] && s1[1]==s2[1]){
		    cout <<1<<"A";
		    if(pd(s1)==pd(s2)){
			    cout <<1<<"B";
			    if(pd(s1)==0) cout <<1<<"C";
			    else if(pd(s1)==1){
				    if(s1[2]-1==s2[2]  	||s1[2]+1==s2[2]){
					    cout<<1;
				   }
				   else cout<<0;
		       }
		   }
			else cout<<0;
	   }
	   else cout <<0;
   } 
	esle cout<<0;
	return 0;
}
