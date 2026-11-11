#include<bits/stdc++.h>
using namespace std;
string c1,s1;
string c2,s2;
int q='A'+'B';
int p='B'+'C';
int v='A'+'C';
bool ce(char x,char y){
	if((x=='D' && y=='F') || (x=='F' && y=='D')){
		return true;
	}
	else{
		int s=x+y;
		if(s==q || s==p || s==v){
			return true;
		}
		else{
			return false;
		}
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	
	string pai1="";
	pai1+=s1[0];
	pai1+=s1[1];
	string pai2="";
	pai2+=s2[0];
	pai2+=s2[1];
	if(pai1==pai2){
		cout<<1;	
	}
	else{
		cout<<"000";
		return 0;
	}
	
	if(ce(s1[2],s2[2])){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	
	if((s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D')){
		cout<<1;
	}
	else{
		int qwq=s1[2]+s2[2];
		if(qwq==q || qwq ==p){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}