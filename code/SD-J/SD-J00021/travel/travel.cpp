#include<bits/stdc++.h>
using namespace std;
bool check1(char a,char b){
	if(a<='C'){
		if(b<='C'){
			return 1;
		}else{
			return 0;
		}
	}else{
		if(b>'C'){
			return 1;
		}else{
			return 0;
		}
	}
}
bool check2(char a,char b){
	if(a=='A'){
		if(b=='B'){
			return 1;
		}else{
			return 0;
		}
	}else if(a=='B'){
		return 1;
	}else if(a=='C'){
		if(b=='A'){
			return 0;
		}else{
			return 1;
		}
	}else{
		return 1;
	}
}
int main(){
	freopen("travel5.in","r",stdin);
	freopen("travel1.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	
	char e=b[2],f=d[2];
	
	if(check1(e,f)){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(check2(e,f)){
		cout<<"1";
	}else{
		cout<<"0";
	}
}

