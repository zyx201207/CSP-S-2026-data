#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("travel.open","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	string ans;
	if(c1!=c2){
		ans+='0';
	}else{
		ans+='1';
	}
	if(s1[1]!=s2[1]){
		ans+='0';
	}else{
		ans+='1';
		
	}
	if(s1[2]=='C'&&s2[2]=='D'||s2[2]=='C'&&s1[2]=='D'){
		ans+='0';
	}else{
		ans+='1';
	}
	if(s1[2]=='A'&&s2[2]=='B'||s2[2]=='A'&&s1[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s2[2]=='B'&&s1[2]=='C'||s1[2]=='D'&&s2[2]=='F'||s2[2]=='D'&&s1[2]=='F'){
		ans+='1';
	}else{
		ans+='0';
	}
	cout<<ans;
	return 0;
	
	
}
