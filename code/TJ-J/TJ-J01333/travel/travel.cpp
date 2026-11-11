#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
int ce(char a){
	if((a-'A')<=2 && (a-'A')>=0){
		return 0;
	}else{
		return 1;
	}
}
int lin(char a,char b){
	if(a-b==1 || a-b==-1){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;//c³µÏáºÅ,s×ùÎ»ºÅ 
	cin>>c1>>s1>>c2>>s2;
//	if(c){
//		cout<<
//	}
	for(int i=0;i<=1;i++){
		if(c1[i]!=c2[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<1;
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(ce(s1[2])==ce(s2[2])){
		cout<<1<<lin(s1[2],s2[2]);
	}else{
		cout<<"00";
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
