#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int f1,f2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]>='D'){
		f1=1;
	}else{
		f1=0;
	}
	if(s2[2]>='D'){
		f2=1;
	}else{
		f2=0;
	}
	if(c1==c2){
		cout<<'1';
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<'1';
	}else{
		cout<<"000";
		return 0;
	}
	if(f1==f2){
		cout<<'1';
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(s1[2]-s2[2])!=1||s1[2]=='D'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='D'){
		cout<<'0';
	}else{
		cout<<'1';
	}
	return 0;
}
