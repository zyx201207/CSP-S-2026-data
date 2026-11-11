#include<bits/stdc++.h>
using namespace std;
int a,b;
string s,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>a>>s>>b>>c;
	if(a==b){
		cout <<"1";
	}else{
		cout <<"0000";
		return 0;
	}
	if(s[0]==c[0]&&s[1]==c[1]){
		cout <<"1";
	}else{
		cout <<"000";
		return 0;
	}
	if(s[2]>='A'&&s[2]<='C'&&c[2]<='C'&&c[2]>='A'||s[2]<='F'&&s[2]>='D'&&c[2]<='F'&&c[2]>='D'){
		cout <<"1"; 
	}else{
		cout <<"00";
		return 0;
	}
	if(s[2]=='A'){
		if(c[2]=='B'){
			cout <<"1";
			return 0;
		}else{
			cout <<"0";
			return 0;
		}
	}
	if(s[2]=='B'){
		if(c[2]=='C'||c[2]=='A'){
			cout <<"1";
			return 0;
		}else{
			cout <<"0";
			return 0;
		}
	}
	if(s[2]=='C'){
		if(c[2]=='B'){
			cout <<"1";
			return 0;
		}else{
			cout <<"0";
			return 0;
		}
	}
	if(s[2]=='D'){
		if(c[2]=='F'){
			cout <<"1";
			return 0;
		}else{
			cout <<"0";
			return 0;
		}
	}
	if(s[2]=='F'){
		if(c[2]=='F'){
			cout <<"1";
			return 0;
		}else{
			cout <<"0";
			return 0;
		}
	}
	return 0;
}
