#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s="";
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int flagac=1;//a,c标记 
	for(int i=0;i<2;i++){
		if(a[i]!=c[i]){
			flagac=0;
		}
	}
	int flagbd=1;//b,d前两位标记 
	for(int i=0;i<2;i++){
		if(b[i]!=d[i]){
			flagbd=0;
		}
	}
	int flag=0;//b,d最后一位标记 
	int flagz=0;
	if(b[2]<='C'&&d[2]<='C'){
		flag=1;
		if(abs(b[2]-d[2])==1){
			flagz=1;
		}
	}else if(b[2]>'C'&&d[2]>'C'){
		flag=1; 
		flagz=1;
	}
	
	if(flagac==1){
		s+="1";
		if(flagbd==1){
			s+="1";
			if(flag==1){
				s+="1";
				if(flagz==1) s+="1";
				else s+="0";
			} 
			else{
				s+="00";
			}
		}
		else{
			s+="000";
		}
	}
	else{
		s+="0000";
	}
	cout<<s;
	
	
	return 0;
}
