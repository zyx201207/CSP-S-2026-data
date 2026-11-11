#include<bits/stdc++.h>
using namespace std;
char c1[2],s1[3],c2[2],s2[3];
bool flag1,flag2,flag31,flag32,flag4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<2;i++){
		cin>>c1[i];
	}
	for(int i=0;i<3;i++){
		cin>>s1[i];
	}
	for(int i=0;i<2;i++){
		cin>>c2[i];
	}
	for(int i=0;i<3;i++){
		cin>>s2[i];
	}
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<1;
		flag1=1;
	}else{
		cout<<0;
	}
	if(flag1==1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		flag2=1;
	}else{
		cout<<0;
	}
	if(flag2==1&&(s1[2]>'C'&&s2[2]>'C')){
		flag31=1;
		cout<<1;
	}else if(flag2==1&&(s1[2]<='C'&&s2[2]<='C')){
		flag32=1;
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(flag31==1){
		cout<<1;
	}else if(flag32==1&&(int(s1[2]-s2[2])<2)){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
