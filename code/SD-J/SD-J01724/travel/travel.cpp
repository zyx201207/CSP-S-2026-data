#include<bits/stdc++.h>
#define st string
using namespace std; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c[3];
	st s1,s2; 
	cin>>c[1]>>s1>>c[2]>>s2;
	if(c[1]==c[2]){
		cout<<1;
	}else{
		cout<<0;
	}if(c[1]==c[2]&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0;
	}if(c[1]==c[2]&&(s1[0]==s2[0]&&s1[1]==s2[1])&&(s2[2]<='C'&&s1[2]<='C'||s2[2]>='D'&&s1[2]>='D')){
		cout<<1;
	}else{
		cout<<0;
	}if(c[1]==c[2]&&s1[0]==s2[0]&&s1[1]==s2[1]&&(s2[2]<='C'&&s1[2]<='C'&&abs(int(s1[2])-int(s2[2]))==1||s2[2]>='D'&&s1[2]>='D')){
		cout<<1;
	}else{
		cout<<0;
	}
	
return 0;
}
