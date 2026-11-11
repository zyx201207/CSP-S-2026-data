#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(" travel.in","r",stdin);
	freopen(" travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(s1==s2){
		cout<<0<<0<<0<<0;
		return 0;
	}
    if(c1==c2){
	    cout<<1;
	} 
	else 
	cout<<0;
	if(s1[0]+s1[1]==s2[0]+s2[1]&&s1[0]==s2[0]){
		cout<<1;
	}
	else
	cout<<0;
	if(s1[0]+s1[1]==s2[0]+s2[1]&&s1[0]==s2[0]&&s1[2]-'0'<'C'&&s2[2]-'0'<'C'||s1[2]-'0'>'C'&&s2[2]-'0'>'C'||s1[2]-'0'=='C'&&s2[2]-'0'=='C'){
		cout<<1;
	}
	else
	cout<<0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]+1==s2[2]||s1[2]-1==s2[2]){
		cout<<1;
	}
	else
	cout<<0;
	return 0;
}