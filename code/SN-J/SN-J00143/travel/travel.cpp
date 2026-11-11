#include<bits/stdc++.h>
using namespace std ;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,c1,s,s1;
	cin>>c>>s>>c1>>s1;
	string a="";
	string x,x1,y,y1;
	x=s.substr(0,2);
	x1=s1.substr(0,2);
	y=s.substr(2,1);
	y1=s1.substr(2,1);
	if(c==c1){
		a+='1';
		if(x==x1){
			a+='1';
		}
		else{
			a+="00";
			if((y=="A"&&y1=="B")||(y=="B"&&y1=="C")||(y=="D"&&y1=="E")){
				a+='1';
			}else{
				a+='0';
				
			}
			cout<<a;
			return 0;
		}
		if((y=="A"&&y1=="B")||(y=="B"&&y1=="C")||(y=="D"&&y1=="E")||(y=="A"&&y1=="C")){
			a+='1';
		}else{
			a+='0';
		}
		if((y=="A"&&y1=="B")||(y=="B"&&y1=="C")||(y=="D"&&y1=="E")){
			a+='1';
		}else{
			a+='0';
		}
	}else{
		a+="0000";
	}
	cout<<a; 
	return 0;
} 
