#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2,f1="ABC",f2="FD";
	cin>>s1>>c1>>s2>>c2;
	if(s1==s2){
		cout<<"1";
	}else if(!(s1==s2)){
		cout<<"0000"<<endl;
		return 0;
	}
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<"1";
	}else if(!(c1[0]==c2[0]&&c1[1]==c2[1])){
		cout<<"0";
	}
    if((c1[0]==c2[0]&&c1[1]==c2[1])&&((f1.find(c1[2])!=-1&&f1.find(c2[2])!=-1)||(f2.find(c1[2])!=-1&&f2.find(c2[2])!=-1))){
    	cout<<"1";
	}else if(!((c1[0]==c2[0]&&c1[1]==c2[1])&&((f1.find(c1[2])!=-1&&f1.find(c2[2])!=-1)||(f2.find(c1[2])!=-1&&f2.find(c2[2])!=-1)))){
		cout<<"0";
	}
	if((c1[0]==c2[0]&&c1[1]==c2[1])&&((c1[2]=='A'&&c2[2]=='B')||(c2[2]=='A'&&c1[2]=='B')||(c1[2]=='B'&&c2[2]=='C')||(c2[2]=='B'&&c1[2]=='C')||(c1[2]=='F'&&c2[2]=='D')||(c2[2]=='F'&&c1[2]=='D'))){
		cout<<"1"<<endl;
		return 0;
	}else{
		cout<<"0"<<endl;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
