#include<bits/stdc++.h>
using namespace std;
string a[]={"A","B","C"};
string b[]={"D","F"};

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	int len=s1.length();
	for(int i=0;i<len;i++){
	if(s1[0]+s1[1]==s2[0]+s2[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	break;
}
	if(c2==c1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	
	for(int i=0;i<len;i++){
		if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'){
			cout<<"1";
		}else if(s1[2]=='C'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'){
			cout<<"1";
		}else if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'){
			cout<<"1";
		}else{
			cout<<"0";
		}
		break;
	}
	
	return 0;
}