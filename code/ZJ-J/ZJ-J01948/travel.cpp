#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string c1={},s1={},c2={},s2={};
     for(int i=0;i<3;i++){
     	char wyx,zhi,xh,ssh;
     	cin>>wyx,zhi,xh,ssh;
     	c1.push_back(wyx);
     	s1.push_back(zhi);
     	c2.push_back(xh);
     	s2.push_back(ssh);
	 }
	if(c1[1]==c2[1] && c1[2]==c2[2]){
		cout<<'1';
	}else{
		cout<<'0';
	}
	if (s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<'1';
	}else{
		cout<<'0';
	}
	if(s1[2]=='A' || s1[2]=='B'||s1[2]=='C'){
		if(s2[2]=='A' || s2[2]=='B'||s2[2]=='C'){
		 cout<<'1';
    	}
	}else if(s1[2]=='D'||s1[2]=='F'){
		if(s2[2]=='F'||s2[2]=='F'){
		  cout<<'1';
	  }
	} else{
		cout<<'0';
	}
	if(s1[2]=='D' &&s2[2]=='F'){
		cout<<'1';
	} else if(s2[2]=='D' &&s1[2]=='F'){
		cout<<'1';
	} else if(s1[2]=='A' &&s2[2]=='B'){
	   cout<<'1';
	}else if(s2[2]=='A'&&s1[2]=='B'){
	   cout<<'1';
	}else if(s1[2]=='B' &&s2[2]=='C'){
        cout<<'1';
	}else if(s2[2]=='B' &&s1[2]=='C'){
	   cout<<'1';
	}else if(s1[2]=='D'&&s2[2]=='F'){
	   cout<<'1';
	}else if(s1[2]=='F' &&s2[2]=='D'){
	   cout<<'1';
	}else{
		cout<<'0';
	}
	return 0;
}