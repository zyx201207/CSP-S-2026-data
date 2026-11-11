#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	string v,s;
	int n,m;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
	   cout<<"1";
	}
	
	else{
		cout<<"0";
	} 
	if(c1==c3){
	n=c2[1];
	m=c4[1];
	if(n==m){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	v=c2[2];
	s=c4[2];
	if(n==m){
	if(v=="A"&&s=="B"){
		cout<<"11";
	}
	else if(v=="A"&&s=="C"){
		cout<<"10";
	}
	else if(v=="B"&&s=="A"){
		cout<<"11";
	}
	else if(v=="B"&&s=="C"){
		cout<<"11";
	}
	else if(v=="C"&&s=="A"){
		cout<<"10";
	}
	else if(v=="C"&&s=="B"){
		cout<<"11";
	}
	else if(v=="D"&&s=="F"){
		cout<<"11";
	}
	else if(v=="F"&&s=="D"){
		cout<<"11";
	}
	else{
	    cout<<"00";
    }
  }
	else{
	    cout<<"00";
	}
  }
   else{
   	   cout<<"000";
   }
	return 0;	
}
