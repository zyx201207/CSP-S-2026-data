#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
	freoen(stdin,"r",travel.in);
	freopen(stdout,"w",travel.out);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1!=c2){
		cout<<"0";
	}else if(s1[1]==s2[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(s1[2]==65||66||67,s2[2]==68||70){
		cout<<"0";
	}else{
		cout<<"1";
	}
	if(s1[2]==65||66||67,s2[2]==68||70){
		cout<<"0";
	}else if(s1[2]+1==s2[2]){
		cout<<"1";
	}else if(s1[2]-1==s2[2]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
