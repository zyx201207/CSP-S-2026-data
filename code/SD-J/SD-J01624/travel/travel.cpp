#include<bits/stdc++.h>
using namespace std;
string c1,c2;
string s1,s2;
inline bool check(char a,char b){
	int A='C'-a,B='C'-b;
	 return (A>=0&&B>=0)||(A<0&&B<0);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
	cout<<1;
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
	cout<<1;
if(check(s1[2],s2[2])){
cout<<1;
if(abs(s1[2]-s2[2])==1)cout<<1;
else cout<<0; 
}
else cout<<"00";
}
    else {cout<<"000";return 0;}
	 
}
	else {cout<<"0000";return 0;}
	
	return 0;
} 
