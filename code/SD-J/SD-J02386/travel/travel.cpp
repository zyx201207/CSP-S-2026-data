#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1,f2,f3,f4; 
bool tyc(string x,string y){
	if((x[2]=='A'&&y[2]!='B')&&(x[2]=='A'&&y[2]!='C')){
		return false;
	}
	else if((x[2]=='B'&&y[2]!='A')&&(x[2]=='B'&&y[2]!='C')){
		return false;
	}
	else if((x[2]=='C'&&y[2]!='A')&&(x[2]=='C'&&y[2]!='B')){
		return false;
	}
	else if(x[2]=='D'&&y[2]!='E'){
		return false;
	}
	else if(x[2]=='E'&&y[2]!='D'){
		return false;
	}
	else{
		return true;
	} 
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!=c2[0] || c1[1]!=c2[1]){
		f1=false;
		f2=false;
		f3=false;
		f4=false;
	}
	else{
		f1=true;
		if(s1[0]!=s2[0] || s1[1]!=s2[1]){
			f2=false;
			f3=false;
			f4=false;
		}
		else{
			f2=true;
			if(tyc(s1,s2)==false){
				f3=false;
				f4=false;
			}
			else{
				f3=true;
				if(abs(int(s1[2])-int(s2[2]))>1){
					f4=false;
				}
				else{
					f4=true;
				}
			}
		}
	}
	if(!f1){
		cout<<0;
	}
	else{
		cout<<1;
	}
	if(!f2){
		cout<<0;
	}
	else{
		cout<<1;
	}
	if(!f3){
		cout<<0;
	}
	else{
		cout<<1;
	}
	if(!f4){
		cout<<0;
	}
	else{
		cout<<1;
	}
	return 0;
}
