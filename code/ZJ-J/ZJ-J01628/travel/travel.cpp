#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	bool a1,a2,a3,a4;
	if(c1==c2){
		a1=1;
	}
	else{
		a1=0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		a2=1;
	}
	else{
		a2=0;
	}
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
		a3=1;
	}
	else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
		a3=1;
	}
	else{
		a3=0;
	}
	if(abs(s1[2]-s2[2])==1){
		a4=1;
	}
	else{
		a4=0;
	}
	if(a1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(a1&&a2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(a1&&a2&&a3){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(a1&&a2&&a3&&a4){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	return 0;
}
