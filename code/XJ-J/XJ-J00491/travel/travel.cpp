#include<bits/stdc++.h>
using namespace std;

int mian(){
	//freopen("travel.in","r","stdin");
	//freopen("travel.out","w","stdout");
	char c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	} else{
		cout<<0;
	} if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		if(s1[2]>='D'&&s2>='D'){
			cout<<1;
		} else if(s1[2]<='C'&&s2[2]<='C'){
			cout<<1;
		} else{
			cout<<0;
		}
	} else{
		cot<<0<<0;
	} if(s1[1]+1==s[1]||s1[1]-1==s2[1]||s1[2]+1==s[2]||s1[2]-1==s2[2]){
		cout<<1;
	} else{
		cout<<0;
	return 0;
}