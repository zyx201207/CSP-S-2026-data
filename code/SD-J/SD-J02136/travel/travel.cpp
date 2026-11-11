#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool f1,f2,f3,f4;
bool check(char a,char b){
	if(('A'<=a&&a<='C'&&'A'<=b&&b<='C')||((a=='D'||a=='F')&&(b=='D'||b=='F'))){
		return true;
	}
	else{
		return false;
	}
}
bool check0(char a,char b){
	if(a=='A'){
		if(b=='B'){
			return true;
		}
		else{
			return false;
		}
	}
	else if(a=='B'){
		if(b=='A'||b=='C'){
			return true;
		}
		else{
			return false;
		}
	}
	else if(a=='C'){
		if(b=='B'){
			return true;
		}
		else{
			return false;
		}
	}
	else if(a=='D'){
		if(b=='F'){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		if(b=='D'){
			return true;
		}
		else{
			return false;
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		f1=true;
	}
	if(f1==true&&s1[0]==s2[0]&&s1[1]==s2[1]){
		f2=true;
	}
	char c=s1[2],d=s2[2];
	if(f1==true&&f2==true&&check(c,d)==true){
		f3=true;
	}
	if(f1==true&&f2==true&&f3==true&&check0(c,d)==true){
		f4=true;
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
