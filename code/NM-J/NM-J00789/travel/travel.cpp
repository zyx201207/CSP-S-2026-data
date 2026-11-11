#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2&&c1!="01"&&c1!="17"&&c2!="01"&&c2!="17")cout<<"1";
	else{
	cout<<"0";
	}
	if(c1==c2&&c1!="01"&&c1!="17"&&c2!="01"&&c2!="17"&&s1.substr(0,2)==s2.substr(0,2)){
		cout<<"1";
	}
	else{			
		cout<<"0";
	}
	if(c1==c2&&c1!="01"&&c1!="17"&&c2!="01"&&c2!="17"&&s1.substr(0,2)==s2.substr(0,2)&&s1.substr(2,1)=="A"&&s2.substr(2,1)=="B")cout<<"1";
	else if(c1==c2&&c1!="01"&&c1!="17"&&c2!="01"&&c2!="17"&&s1.substr(0,2)==s2.substr(0,2)&&s1.substr(2,1)=="A"&&s2.substr(2,1)=="C")cout<<"1";
	else if(c1==c2&&c1!="01"&&c1!="17"&&c2!="01"&&c2!="17"&&s1.substr(0,2)==s2.substr(0,2)&&s1.substr(2,1)=="B"&&s2.substr(2,1)=="A")cout<<"1";
	else if(c1==c2&&c1!="01"&&c1!="17"&&c2!="01"&&c2!="17"&&s1.substr(0,2)==s2.substr(0,2)&&s1.substr(2,1)=="B"&&s2.substr(2,1)=="C")cout<<"1";
	else if(c1==c2&&c1!="01"&&c1!="17"&&c2!="01"&&c2!="17"&&s1.substr(0,2)==s2.substr(0,2)&&s1.substr(2,1)=="C"&&s2.substr(2,1)=="A")cout<<"1";
	else if(c1==c2&&c1!="01"&&c1!="17"&&c2!="01"&&c2!="17"&&s1.substr(0,2)==s2.substr(0,2)&&s1.substr(2,1)=="C"&&s2.substr(2,1)=="B")cout<<"1";
	else if(c1==c2&&c1!="01"&&c1!="17"&&c2!="01"&&c2!="17"&&s1.substr(0,2)==s2.substr(0,2)&&s1.substr(2,1)=="D"&&s2.substr(2,1)=="F")cout<<"1";
	else if(c1==c2&&c1!="01"&&c1!="17"&&c2!="01"&&c2!="17"&&s1.substr(0,2)==s2.substr(0,2)&&s1.substr(2,1)=="F"&&s2.substr(2,1)=="D")cout<<"1";
	else{
		cout<<"0";
	}
	if(c1==c2&&c1!="01"&&c1!="17"&&c2!="01"&&c2!="17"&&s1.substr(0,2)==s2.substr(0,2)&&s1.substr(2,1)=="A"&&s2.substr(2,1)=="B")cout<<"1";
	else if(c1==c2&&c1!="01"&&c1!="17"&&c2!="01"&&c2!="17"&&s1.substr(0,2)==s2.substr(0,2)&&s1.substr(2,1)=="B"&&s2.substr(2,1)=="A")cout<<"1";
	else if(c1==c2&&c1!="01"&&c1!="17"&&c2!="01"&&c2!="17"&&s1.substr(0,2)==s2.substr(0,2)&&s1.substr(2,1)=="B"&&s2.substr(2,1)=="C")cout<<"1";	
	else if(c1==c2&&c1!="01"&&c1!="17"&&c2!="01"&&c2!="17"&&s1.substr(0,2)==s2.substr(0,2)&&s1.substr(2,1)=="C"&&s2.substr(2,1)=="B")cout<<"1";
	else if(c1==c2&&c1!="01"&&c1!="17"&&c2!="01"&&c2!="17"&&s1.substr(0,2)==s2.substr(0,2)&&s1.substr(2,1)=="D"&&s2.substr(2,1)=="F")cout<<"1";
	else if(c1==c2&&c1!="01"&&c1!="17"&&c2!="01"&&c2!="17"&&s1.substr(0,2)==s2.substr(0,2)&&s1.substr(2,1)=="F"&&s2.substr(2,1)=="D")cout<<"1";
	else{cout<<"0";
	}
	return 0;
}
