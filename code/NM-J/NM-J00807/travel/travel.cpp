#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x1,z1,x2,z2;
	cin>>x1>>z1>>x2>>z2;
	string str="\0";
	bool f1=1,f2=1,f3=0,f4=0;
	if(x1!=x2){
		f1=0;
	}
	string n1="\0",n2="\0";
	char l1='\0',l2='\0';
	for(int i=0;i<z1.length();i++){
		if(z1[i]>='0'&&z1[i]<='9'){
			n1+=z1[i];
		}
		else{
			l1=z1[i];
		}
	}
	for(int i=0;i<z2.length();i++){
		if(z2[i]>='0'&&z2[i]<='9'){
			n2+=z2[i];
		}
		else{
			l2=z2[i];
		}
	}
	if(n1!=n2){
		f2=0;
	}
	if((l1=='A'||l1=='B'||l1=='C')&&(l2=='A'||l2=='B'||l2=='C')){
		f3=1;
	}else if((l1=='D'||l1=='F')&&(l2=='D'||l2=='F')){
		f3=1;
	}
	if(f3==1){
		if(l1-l2==1||l2-l1==1){
			f4=1;
		}
	}
	if(f1==1){
		str+="1";
		if(f2==1){
			str+="1";
		}else{
			str+="0";
			f3=0,f4=0;
		}
		
		if(f3==1){
			str+="1";
		}else{
			str+="0";
			f4=0;
		}
		
		if(f4==1){
			str+="1";
		}else{
			str+="0";
		}
	}else{
		str+="0000";
	}
	cout<<str;
	return 0;
}
