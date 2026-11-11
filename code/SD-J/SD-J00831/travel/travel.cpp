#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
string c1,s1,c2,s2;
bool check(string a,string b){
	char k1=a[2],k2=b[2];
	if((k1=='A'||k1=='B'||k1=='C')&&(k2=='A'||k2=='B'||k2=='C')){
		return 1;
	}
	else if((k1=='D'||k1=='F')&&(k2=='D'||k2=='F')){
		return 1;
	}
	else{
		return 0;
	}
}
bool is(string a,string b){
	int k1=a[2]-'A',k2=b[2]-'A';
	if((k1==k2+1)||(k2==k1+1)){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1[0]==c2[0]&&c1[1]==c2[1]&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1[0]==c2[0]&&c1[1]==c2[1]&&s1[0]==s2[0]&&s1[1]==s2[1]&&check(s1,s2)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1[0]==c2[0]&&c1[1]==c2[1]&&s1[0]==s2[0]&&s1[1]==s2[1]&&check(s1,s2)&&is(s1,s2)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
