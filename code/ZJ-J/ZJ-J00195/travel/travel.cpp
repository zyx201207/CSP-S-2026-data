#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	char s1[5],s2[5];
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<"11";
	else{
		cout<<"1000";
		return 0;
	}
	
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		if(s2[3]=='D'||s2[3]=='F'){
			cout<<"00";
		}
		else{
			cout<<"1";
			if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1)cout<<"1";
			else cout<<0;
		}
	}	
	else{
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')cout<<"00";
		else{
			cout<<"1";
			if(s1[2]-s2[2]==2||s1[2]-s2[2]==-2)cout<<"1";
			else cout<<0;
		}
		
	}
	
	return 0;
}
