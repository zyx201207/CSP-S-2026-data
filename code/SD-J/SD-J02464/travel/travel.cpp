#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,n,m;
	cin>>c>>s>>n>>m;
	int o=0;
	char a;
	for(int i=0;i<s.length();i++){
		if(i==0){
			int k=(s[i]-'0')*10;
			o+=k;
		}
		else if(i==1){
			int k=(s[i]-'0');
			o+=k;
		}
		else if(i==2){
			a=s[i];
		}
	}
	int p=0;
	char b;
	for(int i=0;i<m.length();i++){
		if(i==0){
			int k=(m[i]-'0')*10;
			p+=k;
		}
		else if(i==1){
			int k=(m[i]-'0');
			p+=k;
		}
		else if(i==2){
			b=m[i];
		}
	}
	if(c==n){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(o==p){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if((a>='A'&&a<='C'&&b>='A'&&b<='C')||((a=='D'||a=='F')&&(b=='D'||b=='F'))){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if((a=='C'&&b=='D')||(a=='D'&&b=='C')){
		cout<<"0";
	}
	else if((char)(a+1)==b||(char)(a-1)==b){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
