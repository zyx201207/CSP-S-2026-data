#include <iostream>
#include <string>
using namespace std;
int main(){
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2){
	   cout<<1;
	   if (s1[0]==s2[0]&&s1[1]==s2[1]){
	   	  cout<<1;
			if (s1[2]!='C'&&s2[2]!='D'||s1[2]!='D'&&s2[2]!='C'){
	   			cout<<1;
				  if (s1[2]=='C'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='C'){
	   				cout<<0;}
				  else if ((s1[2])+1==int(s2[2])||int(s1[2])-1==int(s2[2])){
						cout<<1;}
				  else{
				   	cout<<0;}}
	   	  	else{
	   	  		cout<<"00";}}
	   	else {
		cout<<"000";  
		}}
	else{
		cout<<"0000";}
	return 0;
	}   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   


























	   






