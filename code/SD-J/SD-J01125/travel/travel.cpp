#include<bits/stdc++.h>
using namespace std;
string s1,s2;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>a>>s2>>b;
	if(s1==s2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	
	if(s1==s2&&a[0]==b[0]&&a[1]==b[1]){
		cout<<"1"; 
	}else{
		cout<<"0";
	}
	
	
	if(s1==s2&&a[0]==b[0]&&a[1]==b[1]){
		if(a[2]=='A'||a[2]=='B'||a[2]=='C'){
			if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
				cout<<"1";
			}else{
				cout<<"0";
			} 
		}else if(a[2]=='E'||a[2]=='F'){
			if(b[2]=='E'||b[2]=='F'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}
	}else{
		cout<<"0";
	}
	
	
	if(s1==s2&&a[0]==b[0]&&a[1]==b[1]){
		if(a[2]=='A'&&b[2]=='B')cout<<"1";
		else if((a[2]=='B'&&b[2]=='C')||(a[2]=='B'&&b[2]=='A'))cout<<"1";
		else if(a[2]=='C'&&b[2]=='B')cout<<"1";
		else if(a[2]=='E'&&b[2]=='F')cout<<"1";
		else if(a[2]=='F'&&b[2]=='E')cout<<"1";
		else cout<<"0";
	}else{
		cout<<"0";
	}
	return 0; 
}
