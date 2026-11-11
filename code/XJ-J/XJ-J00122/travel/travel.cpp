#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";	
	}
	else if(s1[0]-'0'==s2[0]-'0'&&s1[1]-'0'==s2[1]-'0'&&s1[2]!='C'&&s2[2]!='D'&&s2[2]!='F'&&s1[2]!='A'){
		cout<<"1111";
	}
	else if(s1[0]-'0'==s2[0]-'0'&&s1[1]-'0'==s2[1]-'0'&&s1[2]=='C'&&s2[2]=='A'){
		cout<<"1110";
	}
	else if(s1[0]-'0'==s2[0]-'0'&&s1[1]-'0'!=s2[1]-'0'){
		cout<<"1000";
	}
	else if(s1[0]-'0'==s2[0]-'0'&&s1[1]-'0'==s2[1]-'0'&&s1[2]=='C'||s1[2]=='A'||s1[2]=='B'&&s2[2]!='D'||s2[2]!='F'){
		cout<<"1100";
	}
	
    return 0;
}
