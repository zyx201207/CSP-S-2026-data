//西安理工大学附属中学
//SN-J00843 
//戴琨洋 

#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	string a[20];
	string b[20];
	
   
	if(c1!=c2){
	    cout<<"0000";
	}
	else{
	    cout<<"1";	
	}
	
	
    for(int i=0;i<3;i++){
        a[i]=s1[i];
	}
	for(int i=0;i<3;i++){
	    b[i]=s2[i];
	}
	if(a[1]==b[1]&&a[0]==b[0]){
		cout<<"1";
	}
	else{
	    cout<<"0";
	} 
	
    cout<<'1';
	
	if((a[2]=="C"&&b[2]=="B")||(a[2]=="B"&&b[2]=="C")||(a[2]=="A"&&b[2]=="B")||(a[2]=="B"&&b[2]=="A")||(a[2]=="D"&&b[2]=="F")||(a[2]=="F"&&b[2]=="D")){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
