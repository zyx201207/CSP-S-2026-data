#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool f1=false,f2=false,f3=false;
	if(c1==c2){
		f1=true;
		cout<<1;
	}else{
		cout<<0;
	}
	string str="";
	string str1="";
	for(int i=0;i<2;i++){
		str+=s1[i];
		str1+=s2[i];
	}
	if(str==str1&&f1){
		f2=true;
		cout<<1;
	}else{
		cout<<0;
	}
	char x=s1[2];
	char x1=s2[2];
	if(((x<='C'&&x1<='C')||(x>='D'&&x1>='D'))&&f1&&f2){
		f3=true;
		cout<<1;
	}else{
		cout<<0;
	}
	if(f1&&f2&&f3&&(x-x1==1||x-x1==-1)){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
