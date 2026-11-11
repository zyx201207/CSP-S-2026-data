#include<bits/stdc++.h>
#include<string>
using namespace std;
char c1[3];
char s1[4];
char c2[3];
char s2[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		cin>>c1[i]>>c2[i];
	}
	for(int i=1;i<=3;i++){
		cin>>s1[i]>>s2[i];
	}
	if(c1[1]==c2[1]&&c1[2]==c2[2]){
		cout<<'1';
	}
	if(s1[1]==s2[1]){
		if(s1[1]=s2[1]){
			cout<<'1';
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"000"; 
		return 0;
	}
	if(s1[3]=='D'||s1[3]=='E'){
		if(s2[3]=='D'||s2[3]=='E'){
			cout<<'1';
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		if(s2[3]=='A'||s2[3]=='B'||s2[3]=='C'){
			cout<<'1';
		}else{
			cout<<"00";
			return 0;
		}
	}
	if(s1[3]+'1'==s2[3]){
		cout<<'1';
	}else if(s1[3]-'1'==s2[3]){
		cout<<'1';
	}else{
		cout<<'0';
	}
	fclose(stdin);
	fclose(stdout);
}
