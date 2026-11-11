
#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,t1,t2,t3,t4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		t1="1";
	}
	else{
		t1="0";
		t2="0";
		t3="0";
		t4="0";
		cout<<t1<<t2<<t3<<t4;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		t2="1";
	}
	else{
		t2="0";
		t3="0";
		t4="0";
		cout<<t1<<t2<<t3<<t4;
		return 0;
	}
	if(s1[2]=='A'&&s2[2]=='B'){
		t3="1";
		t4="1";
		cout<<t1<<t2<<t3<<t4;
		return 0;
	}
	else if(s1[2]=='B'&&s2[2]=='A'){
		t3="1";
		t4="1";
		cout<<t1<<t2<<t3<<t4;
		return 0;
	}
	else if(s1[2]=='A'&&s2[2]=='C'){
		t3="1";
		t4="0";
		cout<<t1<<t2<<t3<<t4;
		return 0;
	}
	else if(s1[2]=='C'&&s2[2]=='A'){
		t3="1";	
		t4="0";
		cout<<t1<<t2<<t3<<t4;
		return 0;
	}
	else if(s1[2]=='B'&&s2[2]=='C'){
		t3="1";
		t4="1";
		cout<<t1<<t2<<t3<<t4;
		return 0;
	}
	else if(s1[2]=='C'&&s2[2]=='B'){
		t3="1";
		t4="1";
		cout<<t1<<t2<<t3<<t4;
		return 0;
	}
	else if(s1[2]=='D'&&s2[2]=='F'){
		t3="1";
		t4="1";
		cout<<t1<<t2<<t3<<t4;
		return 0;
	}
	else if(s1[2]=='F'&&s2[2]=='D'){
		t3="1";
		t4="1";
		cout<<t1<<t2<<t3<<t4;
		return 0;
	}
	else{
		t3="0";
		t4="0";
		cout<<t1<<t2<<t3<<t4;
		return 0;
	}
	
}
