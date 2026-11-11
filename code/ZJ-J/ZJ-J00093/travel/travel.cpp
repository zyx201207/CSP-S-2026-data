#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
bool f(char a,char b){
	if(a=='A'&&b=='B'){//1
		return 1;
	}if(a=='A'&&b=='C'){//2
		return 1;
	}if(a=='B'&&b=='A'){//5
		return 1;
	}if(a=='B'&&b=='C'){//6
		return 1;
	}if(a=='C'&&b=='A'){//9
		return 1;
	}if(a=='C'&&b=='B'){//10
		return 1;
	}if(a=='D'&&b=='F'){//16
		return 1;
	}if(a=='F'&&b=='D'){//20
		return 1;
	}return 0;
}
bool f2(char a,char b){
	if(a=='A'&&b=='B'){
		return 1;
	}if(a=='B'&&b=='A'){
		return 1;
	}if(a=='B'&&b=='C'){
		return 1;
	}if(a=='C'&&b=='B'){
		return 1;
	}if(a=='D'&&b=='F'){
		return 1;
	}if(a=='F'&&b=='D'){
		return 1;
	}return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2){
		cout<<"1";
	}else{
		cout<<"0";
	}if(a1==a2&&b1[0]==b2[0]&&b1[1]==b2[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}if(a1==a2&&b1[0]==b2[0]&&b1[1]==b2[1]&&f(b1[2],b2[2])){
		cout<<"1";
	}else{
		cout<<"0";
	}if(a1==a2&&b1[0]==b2[0]&&b1[1]==b2[1]&&f2(b1[2],b2[2])){
		cout<<"1";
	}else{
		cout<<"0";
	}return 0;
}
