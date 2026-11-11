#include<bits/stdc++.h>
using namespace std;
string f(string s1,string s2){
	if(s1[2]<'D' and s2[2]<='C'){
	
		if(s1[2]-1==s2[2] || s1[2]+1==s2[2]){
			return "1111";
		}else return "1110";
		
	} else if(s1[2]>'C' && s2[2]>'C'){
		if(s1[2]-2==s2[2] || s1[2]+2==s2[2]){
			return "1111";
		}else return "1110";
	}else{
		return "1100";
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1[0]=s2[0] && s1[1]==s2[1]){
			cout<<f(s1,s2);
		}else cout<<"1000";
	}else cout<<"0000";
	
	return 0;
} 
