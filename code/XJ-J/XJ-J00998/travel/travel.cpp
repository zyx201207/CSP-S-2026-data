#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(s1[0]==s2[0] && s1[1]==s1[1]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(s1[2]=='C',s2[2]=='D' || s1[2]=='D',s2[2]=='C' ){
		cout<<"0";
	}
	else{
		cout<<"1";
    	int s3=(int) s1[2],s4=(int) s2[2];
    	char s5=(char) s3+1,s6=(char) s4+1;
		if(s1[2]==s6 ||s2[2]==s5){
			cout<<"1";
		}
		if(s1[2]=='D',s2[2]=='F' || s2[2]=='D',s1[2]=='F'){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	return 0;
}