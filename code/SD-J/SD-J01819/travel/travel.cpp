#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1,f2,f3,f4;
bool check(char c,char c2){
	if(c2>='A'&&c2<='C'&&c>='A'&&c<='C'){
		return 1;
	}
	else if((c2>='A'&&c2<='C')||(c>='A'&&c<='C')){
		return 0;
	}
	if((c2=='D'||c2=='F')&&(c=='D'||c=='F')){
		return 1;
	}
	else{
		return 0;
	}
} 
bool check2(char c,char c2){
	if(c2>='A'&&c2<='C'&&c>='A'&&c<='C'){
		if(abs(c2-c)==1)return 1;
		else return 0;
	}
	if((c2=='D'||c2=='F')&&(c=='D'||c=='F')){
		return 1;
	}
} 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string ss1,ss2;
	for(int i=0; i<2; i++){
		ss1=ss1+s1[i];
		ss2=ss2+s2[i];
	}
	if(c1==c2){
		f1=1;
	}
	if(f1&&ss1==ss2){
		f2=1;
	}
	if(f2&check(s1[2],s2[2])){
		f3=1;
	}
	if(f3&&check2(s1[2],s2[2])){
		f4=1;
	}
	cout<<(f1?"1":"0")<<(f2?"1":"0")<<(f3?"1":"0")<<(f4?"1":"0");
	return 0;
}
