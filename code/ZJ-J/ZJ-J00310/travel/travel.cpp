#include <bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	cin>>c1>>c2>>s1>>s2;
	if(c1[0]!=s1[0]||c1[1]!=s1[1]){
		cout<<"0000";
		return 0;
	}
	if(c2[0]!=s2[0]||c2[1]!=s2[1]){
		cout<<"1000";
		return 0;
	}
	if(c2[2]>='D'&&s2[2]<'D'||c2[2]<'D'&&s2[2]>='D'){
		cout<<"1100";
		return 0;
	}
	if(c2[2]+1==s2[2]||s2[2]+1==c2[2]){
		cout<<"1111";
	}else{
		cout<<"1110";
	}
	return 0;
}
