#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool f1=0,f2=0,f3=0;
	if(c1==c2){
		f1=1;
		cout<<'1';
	}else{
		cout<<'0';
	}
	if(f1&&s1[0]+s1[1]==s2[0]+s2[1]){
		f2=1;
		cout<<'1';
	}else{
		cout<<'0';
	}
	if(f1&&f2&&s1[2]>='A'&&s2[2]>='A'&&s1[2]<='C'&&s2[2]<='C'){
		f3=1;
		cout<<'1';
	}else if(s1[2]>='D'&&s2[2]>='D'&&s1[2]<='F'&&s2[2]<='F'){
		f3=1;
		cout<<'1'; 
	}else{
		cout<<'0'; 
	}
	bool f4=(s1[2]==char(s2[2]+1)||s1[2]==char(s2[2]-1));
	if(f1&&f2&&f3&&f4){
		cout<<'1'<<endl;
	}else{
		cout<<'0'<<endl;
	}
	return 0;
}

